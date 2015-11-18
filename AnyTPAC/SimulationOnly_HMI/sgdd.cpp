/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Error management page
 */
#include <QMessageBox>

#include "app_logprint.h"
#include "app_cfg_file.h"
#include "main.h"
#include "numpad.h"
#include "sgdd.h"
#include "ui_sgdd.h"

/* this define set the window title */
#define WINDOW_TITLE "SGDD/PRIORITIES"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_SGDD_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

sgdd::sgdd(QWidget *parent) :
    page(parent),
    ui(new Ui::sgdd)
{
    ui->setupUi(this);
    /* set here the protection level (administrator_e, service_e, operator_e), default is operator_e
     * protection_level = operator_e;
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
    SET_SGDD_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

void sgdd::reload()
{
    if (loadModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot read communication option. Using default value\n");
    }
    
    /* Read and show the maximum fail number from the configuration file */
    ui->pushButtonFailNb->setText(QString("%1").arg(FailNb));
    
    /* Read and show the fail divisior from the configuration file */
    ui->pushButtonFailDivisor->setText(QString("%1").arg(FailDivisor));
    
    ui->pushButtonHighPriorityTimer->setText(QString("%1").arg(HighPriorityTimerMsec));
    ui->pushButtonMediumPriorityTimer->setText(QString("%1").arg(MediumPriorityTimerMsec));
    ui->pushButtonLowPriorityTimer->setText(QString("%1").arg(LowPriorityTimerMsec));
}

void sgdd::updateData()
{
    page::updateData();
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void sgdd::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}
#endif

sgdd::~sgdd()
{
    delete ui;
}


void sgdd::on_pushButtonHome_clicked()
{
    go_home();
}

void sgdd::on_pushButtonBack_clicked()
{
    go_back();
}

void sgdd::on_pushButtonFailNb_clicked()
{
    int min = 0, max = 99;
    numpad * dk;
    dk = new numpad(&FailNb, FailNb, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (FailNb < min || FailNb > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(FailNb).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonFailNb->setText(QString("%1").arg(FailNb));
    }
    else
    {
    }
    delete dk;
}

void sgdd::on_pushButtonFailDivisor_clicked()
{
    int min = 0, max = 99;
    numpad * dk;
    dk = new numpad(&FailDivisor, FailDivisor, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (FailDivisor < min || FailDivisor > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(FailDivisor).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonFailDivisor->setText(QString("%1").arg(FailDivisor));
    }
    else
    {
    }
    delete dk;
}

void sgdd::on_pushButtonOk_clicked()
{
    if (saveModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot Save the SGDD option.\n");
        QMessageBox::critical(this,tr("SGDD options"), tr("Impossibile to save the SGDD option."));
    }
    else
    {
        QMessageBox::information(this,tr("SGDD options"), tr("SGDD options saved.\nThey will be active to next reboot."));
    }
}

void sgdd::on_pushButtonHighPriorityTimer_clicked()
{
    int min = 0, max = 9999999;
    numpad * dk;
    dk = new numpad(&HighPriorityTimerMsec, HighPriorityTimerMsec, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (HighPriorityTimerMsec < min || HighPriorityTimerMsec > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(HighPriorityTimerMsec).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonHighPriorityTimer->setText(QString("%1").arg(HighPriorityTimerMsec));
    }
    else
    {
    }
    delete dk;
}

void sgdd::on_pushButtonMediumPriorityTimer_clicked()
{
    int min = 0, max = 9999999;
    numpad * dk;
    dk = new numpad(&MediumPriorityTimerMsec, MediumPriorityTimerMsec, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (MediumPriorityTimerMsec < min || MediumPriorityTimerMsec > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(MediumPriorityTimerMsec).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonMediumPriorityTimer->setText(QString("%1").arg(MediumPriorityTimerMsec));
    }
    else
    {
    }
    delete dk;
}

void sgdd::on_pushButtonLowPriorityTimer_clicked()
{
    int min = 0, max = 9999999;
    numpad * dk;
    dk = new numpad(&LowPriorityTimerMsec, LowPriorityTimerMsec, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (LowPriorityTimerMsec < min || LowPriorityTimerMsec > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(LowPriorityTimerMsec).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonLowPriorityTimer->setText(QString("%1").arg(LowPriorityTimerMsec));
    }
    else
    {
    }
    delete dk;
}

