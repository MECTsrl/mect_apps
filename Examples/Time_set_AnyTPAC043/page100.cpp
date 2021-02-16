/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Generic page
 */
#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"
#include "timepopup.h"
#include "calendar.h"
#include "ntpclient.h"
#include <sys/time.h>
#include <QMessageBox>


#define TIME_MASK "HH:mm:ss"
#define DATE_MASK "yyyy-MM-dd"

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE100_STYLE */
    SET_PAGE100_STYLE();
    translateFontSize(this);

    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    // Running Flags
    lockInterface = false;
    ntpSyncRunning = false;
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page100::reload()
{
    /* Load data and time 1*/
    nOffset = ntpclient->getOffset_h();
    nTimeOut = ntpclient->getTimeout_s();
    nPeriod = ntpclient->getPeriod_h();
    szTimeServer = ntpclient->getNtpServer();

    updateIface();
    ui->progressBarElapsed->setVisible(false);
    lockInterface = false;
    lockUI(lockInterface);
    showFullScreen();
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    lockUI(lockInterface);
    // Progress Bar di aggiornamento NTP
    ui->progressBarElapsed->setVisible(ntpSyncRunning);
    if (ntpSyncRunning && nTimeOut && syncElapsed.isValid())  {
        int nElapsed = syncElapsed.elapsed() / 1000;
        if (nElapsed <= ui->progressBarElapsed->maximum())  {
            ui->progressBarElapsed->setValue(nElapsed);
        }
    }
    /* call the parent updateData member */
    page::updateData();
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page100::~page100()
{
    delete ui;
}

void page100::on_pushButtonTime_clicked()
{
    if (timepopup) {
        QTime t = QTime::fromString(ui->pushButtonTime->text(), "hh:mm:ss"); // and not "HH:mm:ss"
        if (t.isValid()) {
            lockInterface = true;
            lockUI(true);
            timepopup->setTime(t);
            timepopup->movePosition(ui->pushButtonTime->geometry().x(),ui->pushButtonTime->geometry().y());
            timepopup->setModal(true);
            if (timepopup->exec() == QDialog::Accepted) {
                // ui->timeEdit->setTime(timepop->getTime());
                ui->pushButtonTime->setText(timepopup->getTime().toString(TIME_MASK));
            }
            lockInterface = false;
        }
    }
}

/**
  * @brief save the actual date/time
  */

void page100::on_pushButtonHome_clicked()
{
    //go_home();
    goto_page("menu");
}

void page100::on_pushButtonBack_clicked()
{
    //go_back();
}

void page100::on_pushButtonCalendar_clicked()
{

    if (calendarpopup) {
        QDate d = QDate::fromString(ui->pushButtonCalendar->text(), DATE_MASK);
        if (d.isValid()) {
            lockInterface = true;
            lockUI(true);
            calendarpopup->setDate(d);
            calendarpopup->movePosition(ui->pushButtonCalendar->geometry().x(),ui->pushButtonCalendar->geometry().y());
            calendarpopup->setModal(true);
            if (calendarpopup->exec() == QDialog::Accepted) {
                ui->pushButtonCalendar->setText(calendarpopup->getDate().toString(DATE_MASK));
            }
            lockInterface = false;
        }
    }
}

void page100::on_pushButtonNTPSync_clicked()
{
    // Avvio della sincronizzazione via NTP
    if (! szTimeServer.isEmpty() && nTimeOut)  {
        ui->progressBarElapsed->setMaximum(nTimeOut);
        ntpclient->setNtpParams(szTimeServer, nTimeOut, nOffset, nPeriod);
        QObject::connect(ntpclient, SIGNAL(ntpSyncFinish(bool )), this, SLOT(ntpSyncDone(bool)));
        ntpclient->requestNTPSync();
        lockInterface = true;
        ntpSyncRunning = true;
        syncElapsed.restart();
    }
}

void page100::on_pushButtonNTPServer_clicked()
{
    char value [64];
    alphanumpad tastiera_alfanum(value,ui->pushButtonNTPServer->text().toAscii().data());
    tastiera_alfanum.showFullScreen();
    if(tastiera_alfanum.exec()==QDialog::Accepted)
    {
        szTimeServer = QString(value);
        updateIface();
    }
}

void page100::on_pushButtonSetManual_clicked()
{
    QDate d = QDate::fromString(ui->pushButtonCalendar->text(), DATE_MASK);
    QTime t = QTime::fromString(ui->pushButtonTime->text(), "hh:mm:ss");
    if (d.isValid() && t.isValid())  {
        lockInterface = true;
        QDateTime   currentDT(d, t);
        QObject::connect(ntpclient, SIGNAL(ntpDateTimeChangeFinish(bool)), this, SLOT(ntpManualSetDone(bool)));
        datetimeTarget = currentDT;
        ntpclient->requestDateTimeChange(currentDT);
    }
}

void page100::on_pushButtonNTPOffset_clicked()
{
    numpad * dk;
    int value = nOffset;
    int min = -12;
    int max = +12;

    dk = new numpad(&value, nOffset, min, max);
    dk->showFullScreen();
    if (dk->exec() == QDialog::Accepted)
    {
        nOffset = value;
        updateIface();
    }
}

void page100::on_pushButtonNTPTimeOut_clicked()
{
    numpad * dk;
    int value = nTimeOut;
    int min = 1;
    int max = 60;

    dk = new numpad(&value, nTimeOut, min, max);
    dk->showFullScreen();

    if (dk->exec() == QDialog::Accepted)
    {
        nTimeOut = value;
        updateIface();
    }
}

void page100::on_pushButtonNTPPeriod_clicked()
{
    numpad * dk;
    int value = nPeriod;
    int min = 0;
    int max = THE_NTP_MAX_PERIOD_H;

    dk = new numpad(&value, nPeriod, min, max);
    dk->showFullScreen();

    if (dk->exec() == QDialog::Accepted)
    {
        nPeriod = value;
        updateIface();
    }
}

void page100::on_pushButtonNTPSet_clicked()
{
    if (! szTimeServer.isEmpty())  {
        ntpclient->setNtpParams(szTimeServer, nTimeOut, nOffset, nPeriod);
    }
}

void page100::on_pushButtonNTPDefualts_clicked()
{
    // Restore default values
    szTimeServer = QString(THE_NTP_SERVER);
    nTimeOut = 10;
    nPeriod = 0;
    nOffset = 1;
    updateIface();

}

void page100::updateIface()
{
    ui->pushButtonNTPServer->setText(szTimeServer);
    ui->pushButtonNTPOffset->setText(QString("%1 h") .arg(nOffset,2,10));
    ui->pushButtonNTPTimeOut->setText(QString("%1 s") .arg(nTimeOut,2,10));
    ui->pushButtonNTPPeriod->setText(QString("%1 h") .arg(nPeriod,4,10));
    ui->pushButtonTime->setText(QTime::currentTime().toString(TIME_MASK));
    ui->pushButtonCalendar->setText(QDate::currentDate().toString(DATE_MASK));
}

void page100::lockUI(bool setLocked)
{
    // Aggiornamento dell'interfaccia utente
    ui->pushButtonCalendar->setEnabled(! setLocked);
    ui->pushButtonTime->setEnabled(! setLocked);
    ui->pushButtonNTPServer->setEnabled(! setLocked);
    ui->pushButtonSetManual->setEnabled(! setLocked);
    ui->pushButtonNTPSet->setEnabled(! setLocked);
    ui->pushButtonNTPSync->setEnabled(! setLocked);
    ui->pushButtonNTPDefualts->setEnabled(! setLocked);
    ui->pushButtonNTPOffset->setEnabled(! setLocked);
    ui->pushButtonNTPTimeOut->setEnabled(! setLocked);
    ui->pushButtonNTPPeriod->setEnabled(! setLocked);
}

void page100::ntpManualSetDone(bool setOk)
{
    QObject::disconnect(ntpclient, SIGNAL(ntpDateTimeChangeFinish(bool)), 0, 0);
    if (setOk)  {
        QMessageBox::information(this,trUtf8("Manual Date Time Set"), trUtf8("Current Date and Time set to:\n%1") .arg(datetimeTarget.toString(DATE_MASK" "TIME_MASK)));
    }
    else {
        QMessageBox::critical(this,trUtf8("Manual Date Time Set"), trUtf8("Error setting Date and Time to:\n%1") .arg(datetimeTarget.toString(DATE_MASK" "TIME_MASK)));
    }
    lockInterface = false;
    lockUI(lockInterface);
}

void page100::ntpSyncDone(bool timeOut)
{
    QObject::disconnect(ntpclient, SIGNAL(ntpSyncFinish(bool )), 0, 0);
    ntpSyncRunning = false;
    if (timeOut)  {
        QMessageBox::warning(this,trUtf8("NTP Time Error"), trUtf8("Time Out syncing Date and Time with NTP Server:\n%1") .arg(szTimeServer));
    }
    else  {
        QMessageBox::information(this,trUtf8("NTP Time Set"), trUtf8("Current Date and Time set from NTP Server:\n%1") .arg(szTimeServer));
    }
    updateIface();
    lockInterface = false;
    lockUI(lockInterface);
}
