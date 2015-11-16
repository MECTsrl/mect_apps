/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS RTU option page
 */
#include <QMessageBox>

#include "app_logprint.h"
#include "commpar_rtu.h"
#include "main.h"
#include "numpad.h"
#include "ui_commpar_rtu.h"

/* this define set the window title */
#define WINDOW_TITLE "SETUP RTU"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_COMMPAR_RTU_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

commpar_rtu::commpar_rtu(QWidget *parent) :
    page(parent),
    ui(new Ui::commpar_rtu)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* if exist and is not empty enable the WINDOW_ICON */
    if (strlen(WINDOW_ICON) > 0)
    {
        /* enable this line, define the WINDOW_ICON and put a Qlabel named labelIcon in your ui file if you want have a window icon */
        labelIcon = ui->labelIcon;
    }
    /* if exist and is not empty enable the WINDOW_TITLE */
    if (strlen(WINDOW_TITLE) > 0)
    {
        /* enable this line, define the WINDOW_TITLE and put a Qlabel named labelTitle in your ui file if you want have a window title */
        labelTitle = ui->labelTitle;
    }
    
    /* set up the page style */
    SET_PAGE_STYLE();
    /* set the style described into the macro SET_COMMPAR_RTU_STYLE */
    SET_COMMPAR_RTU_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

void commpar_rtu::reload()
{
    int i;
    
    if (loadModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot read communication option. Using default value\n");
    }
    
    /* RTU */
    
    /* load possible baud rate value */
    ui->comboBoxBaudRate->clear();
    for (i = 0; i < BAUDRATE_NB; i++)
    {
        ui->comboBoxBaudRate->addItem(QString("%1").arg(BaudRateArray[i]));
    }
    /* show the baud rate from the configuration file */
    for (i = 0; i < BAUDRATE_NB; i++)
    {
        if (BaudRateArray[i] == BaudRate)
        {
            ui->comboBoxBaudRate->setCurrentIndex(i);
            break;
        }
    }
    
    /* load possible stop bit value */
    ui->comboBoxStopBit->clear();
    for (i = 0; i < STOPBIT_NB; i++)
    {
        ui->comboBoxStopBit->addItem(QString("%1").arg(StopBitArray[i]));
    }
    /* show the stop bit from the configuration file */
    for (i = 0; i < BITNB_NB; i++)
    {
        if (StopBitArray[i] == StopBit)
        {
            ui->comboBoxStopBit->setCurrentIndex(i);
            break;
        }
    }
    
    /* load possible bit number value */
    ui->comboBoxBitNb->clear();
    for (i = 0; i < BITNB_NB; i++)
    {
        ui->comboBoxBitNb->addItem(QString("%1").arg(BitNbArray[i]));
    }
    /* show the Number of bit from the configuration file */
    for (i = 0; i < BITNB_NB; i++)
    {
        if (BitNbArray[i] == DataBit)
        {
            ui->comboBoxBitNb->setCurrentIndex(i);
            break;
        }
    }
    
    /* load possible parity value */
    ui->comboBoxParity->clear();
    for (i = 0; i < PARITY_NB; i++)
    {
        ui->comboBoxParity->addItem(QString("%1").arg(ParityArray[i]));
    }
    /* show the parity from the configuration file */
    for (i = 0; i < PARITY_NB; i++)
    {
        if (ParityArrayShort[i] == Parity)
        {
            ui->comboBoxParity->setCurrentIndex(i);
            break;
        }
    }
    
    /* show the time min into the RTU protocol from the configuration file */
    ui->pushButtonQueryIntervalRTU->setText(QString("%1").arg(QueryIntervalRTU));
    
    /* show the time min into the RTU protocol from the configuration file */
    ui->pushButtonTimeOutRTU->setText(QString("%1").arg(TimeoutRTU));
}

void commpar_rtu::updateData()
{
    page::updateData();
}

commpar_rtu::~commpar_rtu()
{
    delete ui;
}


void commpar_rtu::on_pushButtonHome_clicked()
{
    go_home();
}

void commpar_rtu::on_pushButtonBack_clicked()
{
    go_back();
}

void commpar_rtu::on_pushButtonQueryIntervalRTU_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    int QueryIntervalRTU;
    dk = new numpad(&QueryIntervalRTU, QueryIntervalRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (QueryIntervalRTU < min || QueryIntervalRTU > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(QueryIntervalRTU).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonQueryIntervalRTU->setText(QString("%1").arg(QueryIntervalRTU));
    }
    else
    {
    }
    delete dk;
}

void commpar_rtu::on_pushButtonTimeOutRTU_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    int TimeOutRTU;
    
    dk = new numpad(&TimeOutRTU, TimeOutRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (TimeOutRTU < min || TimeOutRTU > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(TimeOutRTU).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonTimeOutRTU->setText(QString("%1").arg(TimeOutRTU));
    }
    else
    {
    }
    delete dk;
}

void commpar_rtu::on_pushButtonOk_clicked()
{
    BaudRate   = ui->comboBoxBaudRate->currentText().toInt();
    Parity     = ParityArrayShort[ui->comboBoxParity->currentIndex()];
    DataBit    = ui->comboBoxBitNb->currentText().toInt();
    StopBit    = ui->comboBoxStopBit->currentText().toInt();
    QueryIntervalRTU    = ui->pushButtonQueryIntervalRTU->text().toInt();
    TimeoutRTU = ui->pushButtonTimeOutRTU->text().toInt();
    
    if (saveModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot Save the Modbus option.\n");
        QMessageBox::critical(this,tr("Modbus Option"), tr("Impossible to save the Modbus options."));
    }
    else
    {
        QMessageBox::information(this,tr("Modbus Option"), tr("Modbus option saved.\nIt will be active to the next reboot."));
    }
    goto_page("option");
}

void commpar_rtu::on_pushButtonTCP_clicked()
{
    goto_page("commpar_tcp");
}

void commpar_rtu::on_pushButtonTCPRTU_clicked()
{
    goto_page("commpar_tcprtu");
}


