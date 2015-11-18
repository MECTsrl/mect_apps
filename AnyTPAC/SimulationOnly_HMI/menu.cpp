/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#include <QMessageBox>

#include "app_logprint.h"
#include "main.h"
#include "numpad.h"
#include "menu.h"
#include "ui_menu.h"

/* this define set the window title */
#define WINDOW_TITLE "MAIN MENU"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ":/systemicons/img/Home.png"

/**
 * @brief this macro is used to set the page 1  style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE1_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* this section set the style of the generic QPushButton in this page */ \
    mystyle.append("QPushButton#pushButtonPages4"); \
    mystyle.append("{"); \
    mystyle.append("    background-image: url(:/icons/img/button1.png);"); \
    mystyle.append("    background-repeat: none;"); \
    mystyle.append("}"); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
menu::menu(QWidget *parent) :
    page(parent),
    ui(new Ui::menu)
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
    
    SET_PAGE_STYLE();
    SET_PAGE1_STYLE();
    labelDataOra = ui->labelDataOra;
    
    /* the demo button is visible only if this program is build with DEMO define */
#ifdef DEMO
    ui->pushButton->setVisible(true);
#else
    ui->pushButton->setVisible(false);
#endif
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void menu::reload()
{
    
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void menu::updateData()
{
    page::updateData();
    if (active_password == pwd_operator_e)
    {
        ui->pushButtonLogin->setText(tr("LOGIN"));
    }
    else
    {
        ui->pushButtonLogin->setText(tr("LOGOUT"));
    }
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void menu::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}
#endif

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
menu::~menu()
{
    delete ui;
}


void menu::on_pushButtonLogin_clicked()
{
    int min = 0, max = 999999;
    numpad * dk;
    int i;
    int password;
    
    if (active_password != pwd_operator_e)
    {
        active_password = pwd_operator_e;
        ui->pushButtonLogin->setText(tr("LOGIN"));
    }
    else
    {
        dk = new numpad(&password, min, max,true);
        dk->showFullScreen();
        
        if (dk->exec() == QDialog::Accepted)
        {
            active_password = pwd_operator_e;
            
            if (min < max && (password < min || password > max))
            {
                QMessageBox::critical(this,tr("Invalid password"), tr("The inserted password is wrong!!!"));
                delete dk;
                return;
            }
            for (i = 0; i <= PASSWORD_NB; i++)
            {
                LOG_PRINT(info_e, "#############%d vs %d\n", password, passwords[i]);
                if (password == passwords[i])
                {
                    active_password = i;
                    LOG_PRINT(info_e, "%d vs %d\n", password, passwords[i]);
                    break;
                }
            }
            if (active_password == pwd_operator_e)
            {
                QMessageBox::critical(this,tr("Invalid password"), tr("The inserted password is wrong!!!"));
                delete dk;
                return;
            }
            else
            {
                QMessageBox::information(this,tr("Login"), tr("Logged as User: %1.").arg(PasswordsString[active_password]));
                ui->pushButtonLogin->setText(tr("LOGOUT"));
            }
        }
        else
        {
        }
        delete dk;
    }
}

void menu::on_pushButtonData_clicked()
{
    goto_page("data_manager");
}

void menu::on_pushButtonConfigurations_clicked()
{
    goto_page("options");
}

void menu::on_pushButtonInfo_clicked()
{
    goto_page("info");
}

void menu::on_pushButtonPages1_clicked()
{
    goto_page("page100");
}

void menu::on_pushButtonPages2_clicked()
{
    goto_page("page200");
}

void menu::on_pushButtonPages3_clicked()
{
    goto_page("page300");
}

void menu::on_pushButtonPages4_clicked()
{
    goto_page("page400");
}

/* this section is enabled only if this program is build with DEMO define */
#ifdef DEMO
void menu::on_pushButton_clicked()
{
    exit(0);
}
#endif


