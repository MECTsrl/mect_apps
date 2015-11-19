/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief data log setting
 */

#include <QMessageBox>

#include "app_cfg_file.h"
#include "app_logprint.h"
#include "main.h"
#include "datalog_set.h"
#include "ui_datalog_set.h"
#include "numpad.h"

/* this define set the window title */
#define WINDOW_TITLE "DATALOGGER"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_DATALOG_SET_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
datalog_set::datalog_set(QWidget *parent) :
    page(parent),
    ui(new Ui::datalog_set)
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
    /* set the style described into the macro SET_DATALOG_SET_STYLE */
    SET_DATALOG_SET_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    //reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void datalog_set::reload()
{
    ui->pushButtonLogFreqS->setText(QString("%1").arg(LogPeriodSecS));
    ui->pushButtonLogFreqF->setText(QString("%1").arg(LogPeriodSecF));
    QDateTime reference = QDateTime(QDate(0,0,0), QTime(0,0,0)).addSecs(MaxWindowSec);
    
    ui->spinBoxDays->setMaximum(30);
    ui->spinBoxHours->setMaximum(23);
    ui->spinBoxMinutes->setMaximum(59);
    ui->spinBoxSeconds->setMaximum(59);
    
    LOG_PRINT(info_e, "MaxWindowSec %d\n", MaxWindowSec);
    ui->spinBoxDays->setValue(   reference.date().day() - 1);
    ui->spinBoxHours->setValue(  reference.time().hour());
    ui->spinBoxMinutes->setValue(reference.time().minute());
    ui->spinBoxSeconds->setValue(reference.time().second());
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void datalog_set::updateData()
{
    /* call the parent updateData member */
    page::updateData();
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void datalog_set::changeEvent(QEvent * event)
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
datalog_set::~datalog_set()
{
    delete ui;
}


void datalog_set::on_pushButtonHome_clicked()
{
    go_home();
}

void datalog_set::on_pushButtonBack_clicked()
{
    go_back();
}

/* save the actual log period */
void datalog_set::on_pushButtonOk_clicked()
{
    char value[DESCR_LEN];
    sprintf(value, "%d", LogPeriodSecS);
    if (writeCfgVal(CONFIG_FILE, LOG_PERIOD_SLOW, value) <= 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", LOG_PERIOD_SLOW, LogPeriodSecS);
    }
    else
    {
        LOG_PRINT(info_e, "Written '%s' = %d\n", LOG_PERIOD_SLOW, LogPeriodSecS);
    }
    
    sprintf(value, "%d", LogPeriodSecF);
    if (writeCfgVal(CONFIG_FILE, LOG_PERIOD_FAST, value) <= 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", LOG_PERIOD_FAST, LogPeriodSecF);
    }
    else
    {
        LOG_PRINT(info_e, "Written '%s' = %d\n", LOG_PERIOD_FAST, LogPeriodSecF);
    }
    
    MaxWindowSec =
            ui->spinBoxSeconds->value() +
            ui->spinBoxMinutes->value() * 60 +
            ui->spinBoxHours->value() * 3600 +
            ui->spinBoxDays->value() * 3600 * 24;
    
    sprintf(value, "%d", MaxWindowSec);
    if (writeCfgVal(CONFIG_FILE, WINDOW_SEC, value) <= 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", WINDOW_SEC, MaxWindowSec);
    }
    else
    {
        LOG_PRINT(info_e, "Written '%s' = %d\n", WINDOW_SEC, MaxWindowSec);
    }
    
    sprintf(value, "%d", MaxLogUsageMb);
    if (writeCfgVal(CONFIG_FILE, MAX_SPACE_AVAILABLE_TAG, value) <= 0)
    {
        LOG_PRINT(error_e, "Cannot write '%s' = %d\n", MAX_SPACE_AVAILABLE_TAG, MaxLogUsageMb);
    }
    else
    {
        LOG_PRINT(info_e, "Written '%s' = %d\n", MAX_SPACE_AVAILABLE_TAG, MaxLogUsageMb);
    }
    
    go_back();
}

/* set the actual log period but not save it untill Ok button is pressed */
void datalog_set::on_pushButtonLogFreqS_clicked()
{
    int min = 1, max = 99999;
    numpad * dk;
    
    dk = new numpad(&LogPeriodSecS, ui->pushButtonLogFreqS->text().toInt(), min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (LogPeriodSecS < min || LogPeriodSecS > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(LogPeriodSecS).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonLogFreqS->setText(QString("%1").arg(LogPeriodSecS));
    }
    else
    {
        /* Rejected value, nothing to do */
    }
    delete dk;
}

/* set the actual log period but not save it untill Ok button is pressed */
void datalog_set::on_pushButtonLogFreqF_clicked()
{
    int min = 1, max = 99999;
    numpad * dk;
    
    dk = new numpad(&LogPeriodSecF, ui->pushButtonLogFreqF->text().toInt(), min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (LogPeriodSecF < min || LogPeriodSecF > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(LogPeriodSecF).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonLogFreqF->setText(QString("%1").arg(LogPeriodSecF));
    }
    else
    {
        /* Rejected value, nothing to do */
    }
    delete dk;
}

void datalog_set::on_pushButtonSpace_clicked()
{
    int min = 0, max = 0;
    numpad * dk;
    
    dk = new numpad(&MaxLogUsageMb, ui->pushButtonSpace->text().toInt(),  min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (MaxLogUsageMb < min || MaxLogUsageMb > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(LogPeriodSecF).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonSpace->setText(QString("%1").arg(MaxLogUsageMb));
    }
    else
    {
        /* Rejected value, nothing to do */
    }
    delete dk;
}


