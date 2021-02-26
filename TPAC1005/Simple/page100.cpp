/**
 * @file
 *
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

#include "ntpclient.h"

page100 *TheKeyPage;       // Pointer alla pagina che gestisce i Segnali per hwKeys



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
    TheKeyPage = this;
    connect(this, SIGNAL(hwKeyPressed(int)), this, SLOT(KeyPressed(int)));
    connect(this, SIGNAL(hwKeyReleased(int)), this, SLOT(KeyReleased(int)));

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
    QString szUndef = "border-image: url(\":/icons/icons/led_unk.png\");";
    ui->labelImg_01->setStyleSheet(szUndef);
    ui->labelImg_02->setStyleSheet(szUndef);
    ui->labelImg_03->setStyleSheet(szUndef);
    ui->labelImg_04->setStyleSheet(szUndef);
    ui->labelImg_05->setStyleSheet(szUndef);
    ui->labelImg_06->setStyleSheet(szUndef);
    ui->labelImg_07->setStyleSheet(szUndef);
    ui->labelImg_08->setStyleSheet(szUndef);
    ui->labelImg_09->setStyleSheet(szUndef);
    ui->labelImg_10->setStyleSheet(szUndef);
    for (int nKey = 1; nKey < nKEYS; nKey++)  {
        nKeysStatus[nKey] = false;
    }
    ui->label_TzDst->setText(QString("TZ+DST = %1").arg(ntpclient->getOffset_h()));

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
    // USB 0 Status
    if (Usb0_Status == USB_UNPLUGGED) {
        ui->labelUSB_0->setStyleSheet("background-color: rgb(127, 127, 127)");
    }
    else if (Usb0_Status == USB_INSERTED)  {
        ui->labelUSB_0->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    // USB 1 Status
    if (Usb1_Status == USB_UNPLUGGED) {
        ui->labelUSB_1->setStyleSheet("background-color: rgb(127, 127, 127)");
    }
    else if (Usb1_Status == USB_INSERTED)  {
        ui->labelUSB_1->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    // SD CARD
    if (SDCard_Status == SDCARD_EMPTY) {
        ui->labelSDCard->setStyleSheet("background-color: rgb(127, 127, 127)");
    }
    else if (SDCard_Status == SDCARD_INSERTED)  {
        ui->labelSDCard->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    /* call the parent updateData member */
    page::updateData();
    
    /* To read the cross table variable UINT TEST1:
     *    uint_16 tmp = TEST1;
     */
    /* To write 5 into the the cross table variable UINT TEST1:
     *    doWrite_TEST1(5);
     */
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

void page100::sendhwKeyPressed(int nKey)
{
    // qDebug() << QString("Emitted Key Pressed n:%1") .arg(nKey);
    if (this->isVisible())
        emit hwKeyPressed(nKey);
}
void page100::sendhwKeyReleased(int nKey)
{
    // qDebug() << QString("Emitted Key Released n:%1") .arg(nKey);
    if (this->isVisible())
        emit hwKeyReleased(nKey);
}

void page100::KeyPressed(int nKey)
{

    QString szPressed = "border-image: url(\":/icons/icons/led_pressed.png\");";
    if (this->isVisible())  {
        switch (nKey) {
        case 1:
            ui->labelImg_01->setStyleSheet(szPressed);
            break;
        case 2:
            ui->labelImg_02->setStyleSheet(szPressed);
            break;
        case 3:
            ui->labelImg_03->setStyleSheet(szPressed);
            break;
        case 4:
            ui->labelImg_04->setStyleSheet(szPressed);
            break;
        case 5:
            ui->labelImg_05->setStyleSheet(szPressed);
            break;
        case 6:
            ui->labelImg_06->setStyleSheet(szPressed);
            break;
        case 7:
            ui->labelImg_07->setStyleSheet(szPressed);
            break;
        case 8:
            ui->labelImg_08->setStyleSheet(szPressed);
            break;
        case 9:
            ui->labelImg_09->setStyleSheet(szPressed);
            break;
        case 10:
            ui->labelImg_10->setStyleSheet(szPressed);
            break;
        default:
            break;
        }
    }
}
void page100::KeyReleased(int nKey)
{
    QString szReleased;
    if (this->isVisible() && nKey > 0 && nKey < nKEYS)  {
        nKeysStatus[nKey] = ! nKeysStatus[nKey];
        if (nKeysStatus[nKey])  {
            szReleased = "border-image: url(\":/icons/icons/led_on.png\");";
        }
        else  {
            szReleased = "border-image: url(\":/icons/icons/led_off.png\");";
        }
        switch (nKey) {
        case 1:
            ui->labelImg_01->setStyleSheet(szReleased);
            break;
        case 2:
            ui->labelImg_02->setStyleSheet(szReleased);
            break;
        case 3:
            ui->labelImg_03->setStyleSheet(szReleased);
            break;
        case 4:
            ui->labelImg_04->setStyleSheet(szReleased);
            break;
        case 5:
            ui->labelImg_05->setStyleSheet(szReleased);
            break;
        case 6:
            ui->labelImg_06->setStyleSheet(szReleased);
            break;
        case 7:
            ui->labelImg_07->setStyleSheet(szReleased);
            break;
        case 8:
            ui->labelImg_08->setStyleSheet(szReleased);
            break;
        case 9:
            ui->labelImg_09->setStyleSheet(szReleased);
            break;
        case 10:
            ui->labelImg_10->setStyleSheet(szReleased);
            break;
        default:
            break;
        }
    }
}
