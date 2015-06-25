/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Configuration page
 */
#include "app_logprint.h"
#include "main.h"
#include "option.h"
#include "ui_option.h"

/* this define set the window title */
#define WINDOW_TITLE "CONFIGURATION"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_OPTION_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
option::option(QWidget *parent) :
    page(parent),
    ui(new Ui::option)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* if exist and is not empty enable the WINDOW_ICON */
    if (strlen(WINDOW_ICON) > 0)
    {
        /* enable this line, define the WINDOW_ICON and put a Qlabel named labelIcon in your ui file if you want have a window icon */
        labelIcon = ui->labelIcon;
    }
    /* if exist and is not empty enable the WINDOW_TITLE */
    if (strlen(WINDOW_TITLE) > 0)
    {
        /* enable this line, define the WINDOW_TITLE and put a Qlabel named labelTitle in your ui file if you want have a window title */
        labelTitle = ui->labelTitle;
    }
    
    /* set up the page style */
    SET_PAGE_STYLE();
    /* set the style described into the macro SET_OPTION_STYLE */
    SET_OPTION_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void option::reload()
{
    if (active_password == pwd_operator_e)
    {
        ui->pushButtonPasswords->setEnabled(false);
    }
    else
    {
        ui->pushButtonPasswords->setEnabled(true);
    }
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void option::updateData()
{
    /* call the parent updateData member */
    page::updateData();
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
option::~option()
{
    delete ui;
}


void option::on_pushButtonDateAndTime_clicked()
{
    goto_page("time_set");
}

void option::on_pushButtonPasswords_clicked()
{
    int min = 0, max = 999999;
    numpad * dk;
    
    int password;
    dk = new numpad(&password, NO_DEFAULT, min, max,true);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (password < min || password > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value is invalid.\nThe value must ranging between %2 and %3").arg(min).arg(max));
            delete dk;
            return;
        }
        
        passwords[active_password] = password;
        if (dumpPasswords())
        {
            QMessageBox::information(this,tr("Password changed"), tr("The password is succesfully changed."));
        }
        else
        {
            QMessageBox::critical(this,tr("Saving error"), tr("Cannot save the new password."));
        }
    }
    else
    {
    }
    delete dk;
}

void option::on_pushButtonModbus_clicked()
{
    goto_page("commpar_rtu");
}

void option::on_pushButtonErrorsStrategy_clicked()
{
    goto_page("sgdd");
}

void option::on_pushButtonDatalog_clicked()
{
    goto_page("datalog_set");
}

void option::on_pushButtonHomePage_clicked()
{
    if (setAsStartPage(HomePage))
    {
        QMessageBox::information(this,tr("Intal page"), tr("The initial page is resetted."));
    }
}

void option::on_pushButtonHome_clicked()
{
    go_home();
}

void option::on_pushButtonBack_clicked()
{
    go_back();
}


void option::on_pushButtonDisplaySettings_clicked()
{
    goto_page("display_settings");
}

void option::on_pushButtonBuzzerSettings_clicked()
{
    goto_page("buzzer_settings");
}


