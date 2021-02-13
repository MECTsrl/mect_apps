#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page200.h"
#include "ui_page200.h"
#include "crosstable.h"

#define SET_PAGE200_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

page200::page200(QWidget *parent) :
    page(parent),
    ui(new Ui::page200)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    SET_PAGE200_STYLE();
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

void page200::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
}

void page200::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
}

void page200::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

page200::~page200()
{
    delete ui;
}

void page200::on_pushButton_clicked(bool checked)
{
    u_int32_t value;

    if (checked) {
        value = 0;
    } else {
        value = 1;
    }
    beginWrite();

    // RTU0:
    // addWrite_NODE_01_STATUS(value); // MPNC005

    // RTU3:
    // addWrite_NODE_02_STATUS(value); // SCAMBIO ENEL
    // addWrite_NODE_03_STATUS(value); // FOTOVOLTAICO
    addWrite_NODE_04_STATUS(value); // ESTERNI
    addWrite_NODE_05_STATUS(value); // PIANO SOPRA
    addWrite_NODE_06_STATUS(value); // PIANO TERRA
    addWrite_NODE_07_STATUS(value); // PIANO SOTTO
    addWrite_NODE_08_STATUS(value); // AUTO ELETTRICA
    // addWrite_NODE_09_STATUS(value); // PUFFER 500 W
    addWrite_NODE_10_STATUS(value); // LAVANDERIA
    // addWrite_NODE_11_STATUS(value); // UPS
    // addWrite_NODE_12_STATUS(value); // PUFFER 1500 W
    // addWrite_NODE_13_STATUS(value); // CALDAIA

    endWrite();
}
