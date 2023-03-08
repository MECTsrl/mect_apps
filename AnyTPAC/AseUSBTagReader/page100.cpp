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
#include "automation.h"
#include "tagreader.h"

#include <QDebug>
#include <QFile>
#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QElapsedTimer>


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
    // Start-Up values to handle Serial Port
    firstTime = true;
    serialOpened = false;
    serialPortFound = false;
    serialPortName.clear();
    // serialThread = 0;
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE100_STYLE */
    SET_PAGE100_STYLE();
    translateFontSize(this);
    myKeyboard = 0;
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page100::reload()
{
    QString szUndef = "border-image: url(\":/systemicons/LedGrey.png\");";      // Grey
    ui->label_tag_present->setStyleSheet(szUndef);
    ui->label_reader->setStyleSheet(szUndef);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    QString szYellow    = "border-image: url(\":/systemicons/LedYellow.png\");";     // Yellow
    QString szRed       = "border-image: url(\":/systemicons/LedOff.png\");";        // Rosso
    QString szGreen     = "border-image: url(\":/systemicons/LedOn.png\");";         // Verde
    QString szNewStyle;

    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();

    // pushButtonText
    if (ui->pushButtonText->text() != QString(currentRecipeName))  {
        ui->pushButtonText->setText(QString(currentRecipeName));
    }

    // Step 0: Searching for Serial Port
    if (firstTime)  {
        firstTime = false;
        // Allocate alphanumpad object only once for speed
        if (PLC_MS_VERSION >= 0x030401)  {
            // Create alphanumpad object with Extended Chars and password masking enabled
            myKeyboard = new alphanumpad(currentRecipeName, true, NULL);
        }
        else  {
            myKeyboard = 0;
        }
        int     i = 0;
        // Searching Serial Device
        if (QFile::exists(THE_DEVICE))  {
            ui->label_Tag->setText(QString("Searching Device [%1]") .arg(THE_DEVICE));
                //            foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                //                QCoreApplication::processEvents();
                //                qDebug("Serial Port [%d/%d] - Name: [%s] Location: [%s] Description: [%s] Manufacturer: [%s]", i+1,
                //                                    QSerialPortInfo::availablePorts().count(),
                //                                    info.portName().toAscii().data(),
                //                                    info.systemLocation().toAscii().data(),
                //                                    info.description().toAscii().data(),
                //                                    info.manufacturer().toAscii().data());
                //                // Check Device raw file name from /dev
                //                if (info.systemLocation() == THE_DEVICE)  {
                //                    // tagReaderInfo = info;
                //                    serialPortFound = true;
                //                    serialPortName = info.portName();
                //                    qDebug("Tag Reader Device Found: [%s] Port Name[%s]", THE_DEVICE, serialPortName.toAscii().data());
                //                }
                //            }
                serialPortFound = true;
                serialPortName = QString("ttyUSB1");
        }
        else {
            ui->label_Tag->setText(QString("Device [%1] not Found!") .arg(THE_DEVICE));
            qCritical("setup(): Reader Raw Device [%s] not found - No Hope", THE_DEVICE);
        }
        goto endUpdateData;
    }
    // Step 1: Creation of Serial Reader Object and Serial Port Opening (only once in the Application Life)
    if (tagReader == 0 && serialPortFound && ! serialPortName.isEmpty())  {
        ui->label_Tag->setText(QString("Opening Device [%1]") .arg(THE_DEVICE));
        // serialThread = new QThread(this);
        // qDebug("Opening Device [%s] in Thread [0x%x]", THE_DEVICE, (u_int32_t) serialThread);
        qDebug("Opening Device [%s]", THE_DEVICE);
        tagReader = new SerialReader(serialPortName);
        // tagReader->openSerialPort();
        // tagReader->moveToThread(serialThread);
        // QObject::connect(serialThread, SIGNAL(started()), tagReader, SLOT(openSerialPort()));
        // serialThread->start();
        tagReader->openSerialPort();
        // int nLoop = 0;
        // while (! serialOpened && nLoop < 30)  {
        //    sleep(1);
        goto endUpdateData;
    }
    // Step 2: Checking Serial Port
    if (tagReader != 0 && ! serialOpened)  {
        serialOpened = tagReader->isOpen();
        if (serialOpened)  {
            ui->label_Tag->setText(QString("TAG Code: [NONE]"));
            int nDevtty = tagReader->getSerialDeviceID();
            qDebug("Current Serial Port handle [%d] for Device [%s]", nDevtty, THE_DEVICE);
            beginWrite();
            addWrite_readerFound(true);
            addWrite_rawttyDevice((u_int16_t) nDevtty);
            endWrite();
        }
//        else  {
//            qCritical("setup(): Error opening device [%s] - No Hope", THE_DEVICE);
//            tagReader->deleteLater();
//            tagReader = 0;
//            serialPortFound = false;
//        }
        goto endUpdateData;
    }
    // Step 3: No hope to read Cards
    if (tagReader == 0)     {
        ui->atcmButtonRead->setEnabled(false);
        ui->atcmButtonWrite->setEnabled(false);
        goto endUpdateData;
    }
    // Step 4: Reader Connected Updating Interface
    if (readerFound)  {
        szNewStyle = szGreen;
    }
    else  {
        szNewStyle = szYellow;
    }
    // Updating Reader Led
    if (ui->label_reader->styleSheet() != szNewStyle)  {
        ui->label_reader->setStyleSheet(szNewStyle);
    }
    // Updating Tag Labled
    if (! readerFound)  {
        szNewStyle = szYellow;
    }
    else if (tagReader->isTagPresent())  {
        szNewStyle = szRed;
        ui->label_Tag->setText(QString("Tag:[%1]") .arg(tagReader->lastTagID()));
    }
    else  {
        szNewStyle = szGreen;
        ui->label_Tag->setText(QString("Tag:[NONE]"));
    }
    // Updating Tag Led
    if (ui->label_tag_present->styleSheet() != szNewStyle)  {
        ui->label_tag_present->setStyleSheet(szNewStyle);
    }
    // Read / Write Buttons
    ui->atcmButtonRead->setEnabled(tagReader->isTagPresent());
    ui->atcmButtonWrite->setEnabled(tagReader->isTagPresent());
    // Communication Errors
    ui->labelErrors->setText(QString("Comm Errors: %1") .arg(tagReader->getCommErrors(), 10, 10));


endUpdateData:
    // Update Tag Label and Tag Led
    ui->label_reader->update();
    ui->label_Tag->update();
    QCoreApplication::processEvents();
    return;
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

void page100::on_pushButtonText_clicked()
{
    if (PLC_MS_VERSION >= 0x030401 && myKeyboard != 0)  {
        // Set Current value to be edited
        myKeyboard->setQStringValue(QString(currentRecipeName));
        // Set alphanumpad prompt label
        myKeyboard->setPrompt("Enter Recipe Name:");
        // Show alphanumpad object
        myKeyboard->showFullScreen();
        if (myKeyboard->exec() == QDialog::Accepted)  {
            myKeyboard->getValue(currentRecipeName);
        }
        // Hide alphanumpad object
        myKeyboard->hide();
    }
    else  {
        char value [MY_NAME_LEN + 1];
        alphanumpad tastiera_alfanum(value, true, currentRecipeName, false);
        tastiera_alfanum.showFullScreen();
        if (tastiera_alfanum.exec() == QDialog::Accepted)
        {
            strncpy(currentRecipeName, value, MY_NAME_LEN);
        }
    }
}

void page100::on_atcmButtonClear_clicked()
{
    clearVarsAndStruct();
}

void page100::on_atcmButtonRead_clicked()
{
    QElapsedTimer   readTimer;

    readTimer.start();
    memset(&RicettaTAG, 0, sizeof(RicettaTAG));
    if (tagReader->readTagMemory((char *) &RicettaTAG, sizeof(RicettaTAG)))  {
        qDebug("Read Tag: Elapsed[%lli]ms", readTimer.elapsed());
        // TODO: Eliminare questo setting perchè il valore di TAG_Controllo deve essere letto dal Tag
        RicettaTAG.TAG_Controllo = codiceDiControllo;
        struct2Vars();
    }
    else  {
        qCritical("Error Reading Tag: Elapsed[%lli]ms", readTimer.elapsed());
    }
}

void page100::on_atcmButtonWrite_clicked()
{

}
