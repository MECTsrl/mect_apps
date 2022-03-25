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

const u_int32_t minMSVersion = 0x03030B;        // MS Version 3.3.11


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
    uModel = PLC_PRODUCT_ID >> 8;

    ui->lblProtection->setText(QString("Page Prot.Level: [%1]") .arg(protection_level));
    ui->lblPasswordLevel->setText(QString("Active Level: [%1]") .arg(active_password));
    ui->lblAdmin->setText(QString("Pwd Admin:\t[%1] / [%2]") .arg(passwords[pwd_admin_e]) .arg(pwd_admin_e));
    ui->lblSuper->setText(QString("Pwd Super:\t[%1] / [%2]") .arg(passwords[pwd_super_user_e]) .arg(pwd_super_user_e));
    ui->lblUser->setText(QString("Pwd User:\t[%1] / [%2]") .arg(passwords[pwd_user_e]) .arg(pwd_user_e));
    ui->lblLevel->setText(QString("Level: [%1]") .arg(PasswordsString[active_password]));
    ui->lblMSVersion->setText(QString("MS Version: [%1]") .arg(msVersion, 6, 16, QChar('0')));
    ui->lblModel->setText(QString("Model Family: [%1]") .arg(uModel, 6, 16, QChar('0')));
    // Check MS Version
    ui->atcmButtonPassword->setEnabled(msVersion >= minMSVersion);
    ui->atcmButtonSetPwd->setEnabled(msVersion >= minMSVersion);
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


