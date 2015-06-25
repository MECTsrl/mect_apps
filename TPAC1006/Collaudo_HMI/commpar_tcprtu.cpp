/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS TCPRTU option page
 */
#include <QMessageBox>

#include "app_logprint.h"
#include "commpar_tcprtu.h"
#include "main.h"
#include "numpad.h"
#include "ui_commpar_tcprtu.h"

/* this define set the window title */
#define WINDOW_TITLE "SETUP TCPRTU"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the page 400  style.
 * the syntax is html stylesheet-like
 */
#define SET_COMMPAR_TCPRTU_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

commpar_tcprtu::commpar_tcprtu(QWidget *parent) :
    page(parent),
    ui(new Ui::commpar_tcprtu)
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
    SET_COMMPAR_TCPRTU_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

void commpar_tcprtu::reload()
{
    if (loadModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot read communication option. Using default value\n");
    }
    
    /* TCPRTU */
    /* show the IP into the TCPRTU protocol from the configuration file */
    ui->pushButtonIpTCPRTU->setText(IpTCPRTU);
    
    /* show the Port into the TCPRTU protocol from the configuration file */
    ui->pushButtonPortTCPRTU->setText(QString("%1").arg(PortTCPRTU));
    
    /* show the time min into the TCPRTU protocol from the configuration file */
    ui->pushButtonTimeMinTCPRTU->setText(QString("%1").arg(QueryIntervalTCPRTU));
    
    /* show the time out into the TCPRTU protocol from the configuration file */
    ui->pushButtonTimeOutTCPRTU->setText(QString("%1").arg(TimeoutTCPRTU));
}

void commpar_tcprtu::updateData()
{
    page::updateData();
}

commpar_tcprtu::~commpar_tcprtu()
{
    delete ui;
}

void commpar_tcprtu::on_pushButtonTimeOutTCPRTU_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    dk = new numpad(&TimeoutTCPRTU, TimeoutTCPRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (TimeoutTCPRTU < min || TimeoutTCPRTU > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(TimeoutTCPRTU).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonTimeOutTCPRTU->setText(QString("%1").arg(TimeoutTCPRTU));
    }
    else
    {
    }
    delete dk;
}


void commpar_tcprtu::on_pushButtonRTU_clicked()
{
    goto_page("commpar_rtu");
}

void commpar_tcprtu::on_pushButtonTCP_clicked()
{
    goto_page("commpar_tcp");
}

void commpar_tcprtu::on_pushButtonIpTCPRTU_clicked()
{
    char min[32] = "127.0.0.1", max[32] = "255.255.255.255";
    numpad * dk;
    
    dk = new numpad(IpTCPRTU, IpTCPRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        ui->pushButtonIpTCPRTU->setText(QString("%1").arg(IpTCPRTU));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcprtu::on_pushButtonPortTCPRTU_clicked()
{
    int min = 1000, max = 9999;
    numpad * dk;
    
    dk = new numpad(&PortTCPRTU, PortTCPRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (PortTCPRTU < min || PortTCPRTU > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(TimeoutTCPRTU).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonPortTCPRTU->setText(QString("%1").arg(PortTCPRTU));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcprtu::on_pushButtonOk_clicked()
{
    strcpy(IpTCPRTU, ui->pushButtonIpTCPRTU->text().toAscii().data());
    PortTCPRTU     = ui->pushButtonPortTCPRTU->text().toInt();
    QueryIntervalTCPRTU     = ui->pushButtonTimeMinTCPRTU->text().toInt();
    TimeoutTCPRTU  = ui->pushButtonTimeOutTCPRTU->text().toInt();
    
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

void commpar_tcprtu::on_pushButtonTimeMinTCPRTU_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    dk = new numpad(&QueryIntervalTCPRTU, QueryIntervalTCPRTU, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (QueryIntervalTCPRTU < min || QueryIntervalTCPRTU > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(QueryIntervalTCPRTU).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonTimeMinTCPRTU->setText(QString("%1").arg(QueryIntervalTCPRTU));
    }
    else
    {
    }
    delete dk;
    
}

void commpar_tcprtu::on_pushButtonHome_clicked()
{
    go_home();
}

void commpar_tcprtu::on_pushButtonBack_clicked()
{
    go_back();
}


