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
    counter = -2;
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
    /* this define set the variables list to be to displayed in this page without using the ATCM plugins */
    /* Example:
       variableList.clear();
       variableList << "RET_REG_1" << "RET_REG_3" << "NRE_REG_1"
     */
    unsigned short int value = 0;

    if (getFormattedVar("RET_AnOutConf_1", &value)) {
        prepareWriteVar("PLC_AnOutConf_1", &value, NULL);
    }
    if (getFormattedVar("RET_AnOutConf_2", &value)) {
        prepareWriteVar("PLC_AnOutConf_2", &value, NULL);
    }
    if (getFormattedVar("RET_AnInConf_1", &value)) {
        prepareWriteVar("PLC_AnInConf_1", &value, NULL);
    }
    if (getFormattedVar("RET_AnInConf_2", &value)) {
        prepareWriteVar("PLC_AnInConf_2", &value, NULL);
    }
    if (getFormattedVar("RET_AnInConf_3", &value)) {
        prepareWriteVar("PLC_AnInConf_3", &value, NULL);
    }
    if (getFormattedVar("RET_AnInConf_4", &value)) {
        prepareWriteVar("PLC_AnInConf_4", &value, NULL);
    }
    writePendingInorder();
}

#define LIMIT 2
/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    static int divisor = 0;
    short int zero = 0, one = 1;
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    divisor++;
    if (divisor < LIMIT)
    {
        return;
    }
    divisor = 0;
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
    ui->label_USB->setEnabled(USBCheck());
    //ui->label_SD->setEnabled(SDCheck());

    if (ui->atcmButton_5->isChecked()) {
        if (counter < 0) { // was idle
            counter = 0;
        } else {
                switch (counter) {
                case 0:
                    writeVar("PLC_DigOut_1", &one);
                    break;
                case 1:
                    writeVar("PLC_DigOut_2", &one);
                    break;
                case 2:
                    writeVar("PLC_DigOut_3", &one);
                    break;
                case 3:
                    writeVar("PLC_DigOut_4", &one);
                    break;
                case 4:
                    writeVar("PLC_DigOut_5", &one);
                    break;
                case 5:
                    writeVar("PLC_DigOut_6", &one);
                    break;
                case 6:
                    writeVar("PLC_DigOut_7", &one);
                    break;
                case 7:
                    writeVar("PLC_DigOut_8", &one);
                    break;
                case 8:
                    writeVar("PLC_DigOut_9", &one);
                    break;
                case 9:
                    writeVar("PLC_DigOut_10", &one);
                    break;
                case 10:
                    writeVar("PLC_DigOut_11", &one);
                    break;
                case 11:
                    writeVar("PLC_DigOut_12", &one);
                    break;
                case 12:
                    writeVar("PLC_DigOut_1", &zero);
                    break;
                case 13:
                    writeVar("PLC_DigOut_2", &zero);
                    break;
                case 14:
                    writeVar("PLC_DigOut_3", &zero);
                    break;
                case 15:
                    writeVar("PLC_DigOut_4", &zero);
                    break;
                case 16:
                    writeVar("PLC_DigOut_5", &zero);
                    break;
                case 17:
                    writeVar("PLC_DigOut_6", &zero);
                    break;
                case 18:
                    writeVar("PLC_DigOut_7", &zero);
                    break;
                case 19:
                    writeVar("PLC_DigOut_8", &zero);
                    break;
                case 20:
                    writeVar("PLC_DigOut_9", &zero);
                    break;
                case 21:
                    writeVar("PLC_DigOut_10", &zero);
                    break;
                case 22:
                    writeVar("PLC_DigOut_11", &zero);
                    break;
                case 23:
                    writeVar("PLC_DigOut_12", &zero);
                    break;
                default:
                    ;
                }
                counter = (++counter) % (24);
        }
    } else {
        if (counter >= 0) { // was running
            counter = -1;
            prepareWriteVar("PLC_DigOut_1", &zero, NULL);
            prepareWriteVar("PLC_DigOut_2", &zero, NULL);
            prepareWriteVar("PLC_DigOut_3", &zero, NULL);
            prepareWriteVar("PLC_DigOut_4", &zero, NULL);
            prepareWriteVar("PLC_DigOut_5", &zero, NULL);
            prepareWriteVar("PLC_DigOut_6", &zero, NULL);
            prepareWriteVar("PLC_DigOut_7", &zero, NULL);
            prepareWriteVar("PLC_DigOut_8", &zero, NULL);
            prepareWriteVar("PLC_DigOut_9", &zero, NULL);
            prepareWriteVar("PLC_DigOut_10", &zero, NULL);
            prepareWriteVar("PLC_DigOut_11", &zero, NULL);
            prepareWriteVar("PLC_DigOut_12", &zero, NULL);
            writePendingInorder();
        }
    }

}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page100::~page100()
{
    delete ui;

}

static struct {
    unsigned short int value;
    unsigned short int point;
    char min[10];
    char max[10];

} xAnOutConf[] = {
    { 0, 0, "0", "0"}, // not configured
    { 1, 2, "0.00", "20.00"}, // 0.00 20.00 mA
    { 2, 2, "0.000", "10.00"}, // 0.000 10.00 V
};
void page100::on_atcmComboBox_AnOut_1_currentIndexChanged(int index)
{
    unsigned short int value;
    // unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 2) {
        value = xAnOutConf[index].value;
        // point = xAnOutConf[index].point;
        min = xAnOutConf[index].min;
        max = xAnOutConf[index].max;
    } else {
        value = xAnOutConf[0].value;
        min = xAnOutConf[0].min;
        max = xAnOutConf[0].max;
        // point = 0;
    }
    ui->atcmLabel_AnOut_1->setMin(min);
    ui->atcmLabel_AnOut_1->setMax(max);
    writeVar("RET_AnOutConf_1", &value);
}
void page100::on_atcmComboBox_AnOut_2_currentIndexChanged(int index)
{
    unsigned short int value;
    // unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 2) {
        value = xAnOutConf[index].value;
        // point = xAnOutConf[index].point;
        min = xAnOutConf[index].min;
        max = xAnOutConf[index].max;
    } else {
        value = xAnOutConf[0].value;
        min = xAnOutConf[0].min;
        max = xAnOutConf[0].max;
        // point = 0;
    }
    ui->atcmLabel_AnOut_2->setMin(min);
    ui->atcmLabel_AnOut_2->setMax(max);
    writeVar("RET_AnOutConf_2", &value);
}
static struct {
    unsigned short int value;
    unsigned short int point;
    char min[10];
    char max[10];

} xAnInConf[] = {
    { 0, 0, "0", "0"}, // not configured
    { 1, 3, "0.000", "20.000"}, // 0.000 20.000 mA
    { 2, 3, "0.000", "10.000"}, // 0.000 10.000 V
    { 3, 0, "0", "600"}, // 0 600 °C (TCJ)
    { 4, 0, "0", "1200"}, // 0 1200 °C (TCK)
    { 5, 0, "0", "400"}, // 0 400 °C (TCT)
    { 6, 0, "0", "800"}, // 0 800 °C (PT100 E)
    { 7, 1, "0.0", "200.0"}, // 0.0 200.0 °C (PT100 R)
};

void page100::on_atcmComboBox_AnIn_1_currentIndexChanged(int index)
{
    unsigned short int value;
    unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 7) {
        value = xAnInConf[index].value;
        point = xAnInConf[index].point;
        min = xAnInConf[index].min;
        max = xAnInConf[index].max;
    } else {
        value = xAnInConf[0].value;
        min = xAnInConf[0].min;
        max = xAnInConf[0].max;
        point = 0;
    }
    ui->atcmLabel_AnIn_1->setMin(min);
    ui->atcmLabel_AnIn_1->setMax(max);
    prepareWriteVar("RET_AnInConf_1", &value, NULL);
    prepareWriteVar("PLC_AnInPoint_1", &point, NULL);
    writePendingInorder();
}

void page100::on_atcmComboBox_AnIn_2_currentIndexChanged(int index)
{
    unsigned short int value;
    unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 7) {
        value = xAnInConf[index].value;
        point = xAnInConf[index].point;
        min = xAnInConf[index].min;
        max = xAnInConf[index].max;
    } else {
        value = xAnInConf[0].value;
        min = xAnInConf[0].min;
        max = xAnInConf[0].max;
        point = 0;
    }
    ui->atcmLabel_AnIn_2->setMin(min);
    ui->atcmLabel_AnIn_2->setMax(max);
    prepareWriteVar("RET_AnInConf_2", &value, NULL);
    prepareWriteVar("PLC_AnInPoint_2", &point, NULL);
    writePendingInorder();
}

void page100::on_atcmComboBox_AnIn_3_currentIndexChanged(int index)
{
    unsigned short int value;
    unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 7) {
        value = xAnInConf[index].value;
        point = xAnInConf[index].point;
        min = xAnInConf[index].min;
        max = xAnInConf[index].max;
    } else {
        value = xAnInConf[0].value;
        min = xAnInConf[0].min;
        max = xAnInConf[0].max;
        point = 0;
    }
    ui->atcmLabel_AnIn_3->setMin(min);
    ui->atcmLabel_AnIn_3->setMax(max);
    prepareWriteVar("RET_AnInConf_3", &value, NULL);
    prepareWriteVar("PLC_AnInPoint_3", &point, NULL);
    writePendingInorder();
}

void page100::on_atcmComboBox_AnIn_4_currentIndexChanged(int index)
{
    unsigned short int value;
    unsigned short int point;
    char * min;
    char * max;

    if (0 < index and index <= 7) {
        value = xAnInConf[index].value;
        point = xAnInConf[index].point;
        min = xAnInConf[index].min;
        max = xAnInConf[index].max;
    } else {
        value = xAnInConf[0].value;
        min = xAnInConf[0].min;
        max = xAnInConf[0].max;
        point = 0;
    }
    ui->atcmLabel_AnIn_4->setMin(min);
    ui->atcmLabel_AnIn_4->setMax(max);
    prepareWriteVar("RET_AnInConf_4", &value, NULL);
    prepareWriteVar("PLC_AnInPoint_4", &point, NULL);
    writePendingInorder();
}
