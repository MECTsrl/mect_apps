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
#include <qwt_color_map.h>

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

    // Thermometers colors
    QwtLinearColorMap *colorMap = new QwtLinearColorMap();
    colorMap->setColorInterval( Qt::blue, Qt::red );
    ui->Thermo_1->setColorMap( colorMap );
    ui->Thermo_2->setColorMap( colorMap );
    ui->Thermo_3->setColorMap( colorMap );
    ui->Thermo_4->setColorMap( colorMap );
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
    
    static unsigned counter = 0;
    ++counter;
    if (counter % 2 == 0) {

        // every 1 second: update the Qwt widgets
        double value;

        value = PLC_AnIn_1 / 10.0;
        ui->Thermo_1->setValue(value);

        value = PLC_AnIn_2 / 10.0;
        ui->Thermo_2->setValue(value);

        value = PLC_AnIn_3 / 10.0;
        ui->Thermo_3->setValue(value);

        value = PLC_AnIn_4 / 10.0;
        ui->Thermo_4->setValue(value);
    }

    if (counter % 3 == 0) {

        // every 1.5 seconds: update the network status

        if (isUP_wlan0()) {
            ui->label_WiFi->setText("WiFi ON");
            ui->label_WiFi->setStyleSheet("background-color: rgb(0, 255, 0);");
        } else {
            ui->label_WiFi->setText("WiFi off");
            ui->label_WiFi->setStyleSheet("background-color: rgb(255, 0, 0);");
        }
        if (isUP_ppp0()) {
            ui->label_Mobile->setText("Mobile ON");
            ui->label_Mobile->setStyleSheet("background-color: rgb(0, 255, 0);");
        } else {
            ui->label_Mobile->setText("Mobile off");
            ui->label_Mobile->setStyleSheet("background-color: rgb(255, 0, 0);");
        }
        if (isUP_tun0()) {
            ui->label_VPN->setText("VPN ON");
            ui->label_VPN->setStyleSheet("background-color: rgb(0, 255, 0);");
        } else {
            ui->label_VPN->setText("VPN off");
            ui->label_VPN->setStyleSheet("background-color: rgb(255, 0, 0);");
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


