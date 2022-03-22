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

#include "global_functions.h"


#include <QDebug>
#include <QProcess>
#include <QHostAddress>

#include <arpa/inet.h>

const QString  szBorderImage =  "border-image: url(\":/systemicons/%1.png\");";
const u_int32_t minMSVersion = 0x03030A;

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
    msVersion = getMSVersion();
    doWrite_mectsuiteVersion(msVersion);
    uModel = PLC_PRODUCT_ID >> 8;
    qDebug("Model is: [%6X]", uModel);
    ui->lblWiFiConn->setStyleSheet(QString(szBorderImage) .arg("LedGrey"));
    ui->lblWiFi->setStyleSheet(QString(szBorderImage) .arg("WifiOff"));
    ui->lblWanConn->setStyleSheet(QString(szBorderImage) .arg("LedGrey"));
    ui->lblWanStatus->setStyleSheet(QString(szBorderImage) .arg("GprsOff"));
    ui->lblMSVersion->setText(ui->lblMSVersion->text() + QString("%1 - %2") .arg(msVersion, 6, 16, QChar('0')) .arg(HMIversion));
    logStart();
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    static int nLoop = 0;

    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    // Refresh ogni 3s
    if ((++nLoop % 6) == 0)  {
        nLoop = 0;
        // Check MS Version
        if (msVersion >= minMSVersion)  {
            // All above functions are available since Mect Suite 3.3.9
            int nSignalLevel = 0;
            int nQuality = 0;
            QString szWifiStyle;
            QString szWifiConnStyle;
            QString szWanStyle;
            QString szWanConnStyle;

            // Check Board Presence
            bool    wifiPresent = check_wifi_board();
            bool    wanPresent = check_usb_wan_board();

            // Check wifi connection
            if (wifiPresent)  {
                if (get_wifi_signal_level(nQuality, nSignalLevel))  {
                    szWifiStyle = QString(szBorderImage) .arg("WifiOn");
                }
                if (isWlanOn())  {
                    szWifiConnStyle = QString(szBorderImage) .arg("LedOn");
                }
                else {
                    szWifiConnStyle = QString(szBorderImage) .arg("LedYellow");
                }
            }
            else {
                szWifiStyle = QString(szBorderImage) .arg("WifiOff");
                szWifiConnStyle = QString(szBorderImage) .arg("LedGrey");
            }

            // Check Wan Connection
            if (wanPresent)  {
                if (isWanOn())  {
                    szWanStyle = QString(szBorderImage) .arg("GprsOn");
                    szWanConnStyle = QString(szBorderImage) .arg("LedOn");
                }
                else  {
                    szWanStyle = QString(szBorderImage) .arg("GprsOff");
                    szWanConnStyle = QString(szBorderImage) .arg("LedYellow");
                }
            }
            else {
                szWanStyle = QString(szBorderImage) .arg("GprsOff");
                szWanConnStyle = QString(szBorderImage) .arg("LedGrey");
            }
            // Updating Label Stylesheet only if needed
            if (ui->lblWiFiConn->styleSheet() != szWifiConnStyle)  {
                ui->lblWiFiConn->setStyleSheet(szWifiConnStyle);
            }
            if (ui->lblWiFi->styleSheet() != szWifiStyle)  {
                ui->lblWiFi->setStyleSheet(szWifiStyle);
            }
            if (ui->lblWanConn->styleSheet() != szWanConnStyle)  {
                ui->lblWanConn->setStyleSheet(szWanConnStyle);
            }
            if (ui->lblWanStatus->styleSheet() != szWanStyle)  {
                ui->lblWanStatus->setStyleSheet(szWanStyle);
            }
            ui->txtQuality->setText(QString("%1%") .arg(nQuality, 3, 10));
            ui->txtLevel->setText(QString("%1 dBm") .arg(nSignalLevel, 3, 10));
            ui->optWLan->setEnabled(wifiPresent);
            ui->optWan->setEnabled(wanPresent);
            // CT Update
            beginWrite();
            addWrite_wifiON(wifiPresent);
            addWrite_wifiQuality((int16_t) nQuality);
            addWrite_wifiLevel((int16_t) nSignalLevel);
            addWrite_wanON(wanPresent);
            endWrite();
        }
        else {
            ui->cmdGW->setEnabled(false);
        }
    }
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

void page100::on_cmdGW_clicked()
{
    QString szBoard;

    unsigned myGW = 0;

    if (ui->optLan->isChecked())  {
        szBoard = "eth0";
    }
    else if (ui->optWLan->isChecked())  {
        szBoard = "wlan0";
    }
    else if (ui->optWan->isChecked())  {
        szBoard = "ppp0";
    }
    if (! szBoard.isEmpty())  {
        // MAC Address
        if (szBoard != "ppp0")  {
            ui->txtMAC->setText(getMacAddr(szBoard));
        }
        else  {
            ui->txtMAC->setText(NO_IP);
        }
        // IP Address
        ui->txtIP->setText(getIPAddr(szBoard));
        if (getBoardGateway(szBoard.toLatin1().data(), myGW))  {
            QString szGwIP = QHostAddress(ntohl(myGW)).toString();
            qDebug("Gateway found for Board:[%s] Address:[%s]", szBoard.toLatin1().data(), szGwIP.toLatin1().data());
            ui->txtGW->setText(szGwIP);
            if (checkNetAddr(szGwIP.toLatin1().data()))  {
                qDebug("GW Net Address is Ok: [%s]", szGwIP.toLatin1().data());
            }
            else {
                qWarning("Malformed GW Net Address: [%s]", szGwIP.toLatin1().data());
            }
        }
        else  {
            ui->txtGW->setText("--- NONE ---");
            qWarning("Gateway NOT found for Board:[%s]", szBoard.toLatin1().data());
        }
    }
}
