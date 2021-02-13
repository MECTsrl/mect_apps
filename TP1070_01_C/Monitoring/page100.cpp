#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

page100::page100(QWidget *parent) :
    page(parent),
    ui(new Ui::page100)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    SET_PAGE100_STYLE();
    translateFontSize(this);

    ui->atcmButton_Heating_2->setEnabled(false);
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

void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();    
}

void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

page100::~page100()
{
    delete ui;
}


