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
#include "page300.h"
#include "ui_page300.h"
#include "crosstable.h"

#include "automation.h"

/**
 * @brief this macro is used to set the PAGE300 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page300::page300(QWidget *parent) :
    page(parent),
    ui(new Ui::page300)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE300_STYLE */
    SET_PAGE300_STYLE();
    translateFontSize(this);
    qtitle.clear();
    qtext.clear();
    setTheWidget(this);
}

void page300::messageBox(char *title, char *text)
{
    qtitle = QString(title);
    qtext = QString(text);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page300::reload()
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
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page300::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    if (! qtitle.isEmpty() ) {
        QMessageBox box(this);
        box.setWindowTitle(qtitle);
        box.setText(qtext);
        box.exec();
        qtitle.clear();
        qtext.clear();
    }
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
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page300::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page300::~page300()
{
    delete ui;
}

void page300::on_atcmComboBox_PRODUCT_ID_currentIndexChanged(int index)
{
    index = index;
    doWrite_DO_RELOAD(1);
}

void page300::on_atcmComboBox_TEST_ID_currentIndexChanged(int index)
{
    index = index;
    doWrite_DO_RELOAD(1);
}
