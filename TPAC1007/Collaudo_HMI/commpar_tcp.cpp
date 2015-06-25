/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Setup MODBUS TCP option page
 */
#include <QMessageBox>

#include "app_logprint.h"
#include "commpar_tcp.h"
#include "main.h"
#include "numpad.h"
#include "ui_commpar_tcp.h"

/* this define set the window title */
#define WINDOW_TITLE "SETUP TCP"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the page 400  style.
 * the syntax is html stylesheet-like
 */
#define SET_COMMPAR_TCP_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

commpar_tcp::commpar_tcp(QWidget *parent) :
    page(parent),
    ui(new Ui::commpar_tcp)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_super_admin_e,pwd_admin_e, pwd_service_e, pwd_operator_e), default is pwd_operator_e
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
    SET_COMMPAR_TCP_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

void commpar_tcp::reload()
{
    if (loadModbusOption() != 0)
    {
        LOG_PRINT(error_e, "Cannot read communication option. Using default value\n");
    }
    
    /* TCP */
    /* show the IP into the TCP protocol from the configuration file */
    ui->pushButtonIpTCP->setText(IpTCP);
    
    /* show the Port into the TCP protocol from the configuration file */
    ui->pushButtonPortTCP->setText(QString("%1").arg(PortTCP));
    
    /* show the time min into the TCP protocol from the configuration file */
    ui->pushButtonTimeMinTCP->setText(QString("%1").arg(QueryIntervalTCP));
    
    /* show the time min into the TCP protocol from the configuration file */
    ui->pushButtonTimeOutTCP->setText(QString("%1").arg(TimeoutTCP));
    
}

void commpar_tcp::updateData()
{
    page::updateData();
}

commpar_tcp::~commpar_tcp()
{
    delete ui;
}

void commpar_tcp::on_pushButtonIpTCP_clicked()
{
    char min[32] = "127.0.0.1", max[32] = "255.255.255.255";
    numpad * dk;
    
    dk = new numpad(IpTCP, IpTCP, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        ui->pushButtonIpTCP->setText(QString("%1").arg(IpTCP));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcp::on_pushButtonPortTCP_clicked()
{
    int min = 1000, max = 9999;
    numpad * dk;
    
    dk = new numpad(&PortTCP, PortTCP, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (PortTCP < min || PortTCP > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(PortTCP).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonPortTCP->setText(QString("%1").arg(PortTCP));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcp::on_pushButtonTimeMinTCP_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    dk = new numpad(&QueryIntervalTCP, QueryIntervalTCP, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (QueryIntervalTCP < min || QueryIntervalTCP > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(QueryIntervalTCP).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonTimeMinTCP->setText(QString("%1").arg(QueryIntervalTCP));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcp::on_pushButtonTimeOutTCP_clicked()
{
    int min = 0, max = 9999;
    numpad * dk;
    
    dk = new numpad(&TimeoutTCP, TimeoutTCP, min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (TimeoutTCP < min || TimeoutTCP > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(TimeoutTCP).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonTimeOutTCP->setText(QString("%1").arg(TimeoutTCP));
    }
    else
    {
    }
    delete dk;
}

void commpar_tcp::on_pushButtonRTU_clicked()
{
    goto_page("commpar_rtu");
}

void commpar_tcp::on_pushButtonTCPRTU_clicked()
{
    goto_page("commpar_tcprtu");
}

void commpar_tcp::on_pushButtonOk_clicked()
{
    strcpy(IpTCP, ui->pushButtonIpTCP->text().toAscii().data());
    PortTCP = ui->pushButtonPortTCP->text().toInt();
    QueryIntervalTCP    = ui->pushButtonTimeMinTCP->text().toInt();
    TimeoutTCP = ui->pushButtonTimeOutTCP->text().toInt();
    
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

void commpar_tcp::on_pushButtonHome_clicked()
{
    go_home();
}

void commpar_tcp::on_pushButtonBack_clicked()
{
    go_back();
}


