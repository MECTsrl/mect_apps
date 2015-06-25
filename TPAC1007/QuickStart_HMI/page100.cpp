/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
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
       trend initialization:
         strncpy(_actual_trend_, "trend1.csv",FILENAME_MAX);
         _trend_data_reload_ = true;
       store initialization:
         strncpy(_actual_store_, "store1.csv",FILENAME_MAX);
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
    int value;
     // DIGITAL 1-4 AS OUTPUT
    value = 1;
    writeVar("PLC_DigDir_1", &value);
    writeVar("PLC_DigDir_2", &value);
    writeVar("PLC_DigDir_3", &value);
    writeVar("PLC_DigDir_4", &value);
    // DIGITAL 5-8 AS INPUT
    value = 0;
    writeVar("PLC_DigDir_5", &value);
    writeVar("PLC_DigDir_6", &value);
    writeVar("PLC_DigDir_7", &value);
    writeVar("PLC_DigDir_8", &value);
    // ANALOG 1 OUTPUT AS 0-10V
    value = 2;
    writeVar("PLC_AnOutConf_1", &value);
    // ANALOG 1-2 INPUT AS 0-10V
    value = 2;
    writeVar("PLC_AnInConf_1", &value);
    writeVar("PLC_AnInConf_2", &value);
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
    /* This code show how to connect
     * the cross table variable named "RET_REG_1" to the HMI label "label1val"
     * and if it is not NULL, set the Status led "led1" without using ATCM plugins
     *    WARNING: only MIRROR variable can be read or the variable listed
     *            into the active variable list variableList defined at the top of this file
     
     if (getFormattedVar("RET_REG_1", ui->label1val, ui->led1) == false)
     {
        LOG_PRINT(error_e, "cannot read variable '%s'","RET_REG_1" );
     }
     */
    /* This code show how to write a cross table variable named "NRE_REG_1"  without using ATCM plugins.
     * Usually this code is putted into a button slot.
     * The variable could be not present into the active variable list "variableList"
     if (writeVar("NRE_REG_1", &value) == true)
     {
        LOG_PRINT(info_e,"################### NRE_REG_1 %d\n", value);
     }
     */
    float AnIn_1, AnIn_2, AnOut_1;
    if (getFormattedVar("PLC_AnIn_1", &AnIn_1, NULL) && getFormattedVar("PLC_AnIn_2", &AnIn_2, NULL))
    {
        AnOut_1 = AnIn_1 * AnIn_2 / 10.0;
        writeVar("PLC_AnOut_1", &AnOut_1);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page100::~page100()
{
    delete ui;
}

