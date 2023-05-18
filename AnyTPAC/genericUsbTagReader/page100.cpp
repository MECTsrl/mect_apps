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

#include <QFile>
#include <QCoreApplication>

// Info for qDebug
#define LOG_STRING      "[%s] %s(%d):\t"
#define LOG_POINT       QTime::currentTime().toString("HH:mm:ss.zzz").toLatin1().data(), __func__, __LINE__

const   QString szFORMATTime    = "hh:mm:ss";
const   QString szLedGray       = "border-image: url(\":/systemicons/LedGrey.png\");";       // Grey Led
const   QString szLedYellow     = "border-image: url(\":/systemicons/LedYellow.png\");";     // Yellow Led
const   QString szLedRed        = "border-image: url(\":/systemicons/LedOff.png\");";        // Red Led
const   QString szLedGreen      = "border-image: url(\":/systemicons/LedOn.png\");";         // Green Led

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
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
    myReader = 0;
    myStatus = 0;
    serialDevice = QString("/dev/ttyUSB0");
    myMessage.clear();
    ui->lineEdit->clear();
    ui->lblMessage->clear();
    ui->lblElapsed->clear();
    ui->lblLen->clear();
    ui->lblLoops->clear();
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page100::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
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
    /* call the parent updateData member */
    page::updateData();
    //-------------------------------------------
    // Step 0: Searching for Serial Port
    //-------------------------------------------
    if (myStatus == 0)  {
        ui->ledReader->setStyleSheet(szLedGray);
        // Check Device presence
        if (QFile::exists(serialDevice))  {
            myMessage = QString("Device [%1] Present!") .arg(serialDevice);
            qDebug(LOG_STRING"%s", LOG_POINT, myMessage.toLatin1().data());
            myStatus = 1;
        }
        else  {
            myMessage = QString("Device [%1] NOT Found!") .arg(serialDevice);
            qCritical(LOG_STRING"%s", LOG_POINT, myMessage.toLatin1().data());
            myStatus = 3;
        }
        goto endUpdateData;
    }
    //-------------------------------------------
    // Step 1: Creation of Tag Reader Object and Serial Port Opening (only once in the Application Life)
    //-------------------------------------------
    else if (myStatus == 1)  {
        ui->ledReader->setStyleSheet(szLedYellow);
        myMessage = QString("Opening Device [%1]") .arg(serialDevice);
        qDebug(LOG_STRING"%s", LOG_POINT, myMessage.toLatin1().data());
        myReader = new tagReader(this);
        sleep(1);
        if (myReader->openSerialPort(serialDevice))  {
            myMessage = QString("Device [%1] Opened!") .arg(serialDevice);
            qDebug(LOG_STRING"%s", LOG_POINT, myMessage.toLatin1().data());
            myStatus = 2;
        }
        else  {
            myMessage =  QString("Dev.[%1] not Opened! - No Hope") .arg(serialDevice);
            qCritical(LOG_STRING"%s", LOG_POINT, myMessage.toLatin1().data());
            myStatus = 3;
        }
        goto endUpdateData;
    }
    //-------------------------------------------
    // Step 2: Checking Tag Reader and Connect remote signals  (only once in the Application Life)
    //-------------------------------------------
    else if (myStatus == 2)  {
        myMessage = QString("Connecting Device [%1] Signals") .arg(serialDevice);
        if (myReader->isOpen())  {
            ui->ledReader->setStyleSheet(szLedGreen);
            connect(myReader, SIGNAL(readNewTag(QString)), this, SLOT(updateTagData(QString)));
            myMessage.clear();
            myStatus = 4;
        }
        goto endUpdateData;
    }
    //-------------------------------------------
    // Step 3: No hope to read Cards
    //-------------------------------------------
    else if (myStatus == 3)  {
        // Nothing to do
        goto endUpdateData;
    }
    //-------------------------------------------
    // Step 4: Reader Connected, Updating Interface
    //-------------------------------------------
    else if (myStatus == 4)  {
        if (ui->ledReader->styleSheet() != szLedGreen)  {
            ui->ledReader->setStyleSheet(szLedGreen);
        }
    }

endUpdateData:

    // Update Message Label
    if (ui->lblMessage->text() != myMessage)  {
        ui->lblMessage->setText(myMessage);
    }
    QCoreApplication::processEvents();
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


void page100::updateTagData(QString currentTagID)
{
    // Line Edit
    ui->lineEdit->clear();
    ui->lineEdit->setText(currentTagID);
    ui->lineEdit->setCursorPosition(currentTagID.length() - 1);
    ui->lineEdit->selectAll();
    // Elapsed Time
    ui->lblElapsed->setText(QString("%1") .arg(myReader->getElapsedTime()));
    // Tag Len
    ui->lblLen->setText(QString("%1") .arg(currentTagID.length()));
    // Read Loops
    ui->lblLoops->setText(QString("%1") .arg(myReader->getReadLoops()));
    // User Message
    myMessage = QString("%1 - Read New Tag") .arg(QTime::currentTime().toString(szFORMATTime));
    // Led
    ui->ledReader->setStyleSheet(szLedRed);
    ui->ledReader->update();
}
