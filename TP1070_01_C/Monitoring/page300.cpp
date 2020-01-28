#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page300.h"
#include "ui_page300.h"
#include "crosstable.h"

#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

page300::page300(QWidget *parent) :
    page(parent),
    ui(new Ui::page300)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */

    SET_PAGE300_STYLE();
    translateFontSize(this);

    ui->atcmButton_XX_01->setEnabled(false);
    ui->atcmButton_XX_02->setEnabled(false);
    ui->atcmButton_XX_03->setEnabled(false);
    ui->atcmButton_XX_04->setEnabled(false);
    ui->atcmButton_XX_05->setEnabled(false);
    ui->atcmButton_XX_06->setEnabled(false);
    ui->atcmButton_XX_07->setEnabled(false);
    ui->atcmButton_XX_08->setEnabled(false);
    ui->atcmButton_XX_09->setEnabled(false);
    ui->atcmButton_XX_10->setEnabled(false);
    ui->atcmButton_XX_11->setEnabled(false);
    ui->atcmButton_XX_12->setEnabled(false);
    ui->atcmButton_XX_13->setEnabled(false);
    ui->atcmButton_XX_14->setEnabled(false);
    ui->atcmButton_XX_15->setEnabled(false);
    ui->atcmButton_XX_16->setEnabled(false);
}

void page300::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
}

void page300::updateData()
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

void page300::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

page300::~page300()
{
    delete ui;
}
