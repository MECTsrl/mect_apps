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
#include "page200.h"
#include "ui_page200.h"
#include <QFile>
#include <QMessageBox>

/**
 * @brief this macro is used to set the PAGE200 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE200_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page200::page200(QWidget *parent) :
    page(parent),
    ui(new Ui::page200)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE200_STYLE */
    SET_PAGE200_STYLE();
    translateFontSize(this);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page200::reload()
{
    /* this define set the variables list to be to displayed in this page without using the ATCM plugins */
    /* Example:
       variableList.clear();
       variableList << "RET_REG_1" << "RET_REG_3" << "NRE_REG_1"
     */
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page200::updateData()
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
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page200::~page200()
{
    delete ui;
}

void page200::on_atcmButton_2_clicked()
{
    QFile::remove("/local/etc/sysconfig/application.conf");
    if (QFile::copy("/local/etc/sysconfig/application_can1_on.conf", "/local/etc/sysconfig/application.conf") == false)
    {
        QMessageBox::critical(0,"ERROR", "NON RIESCO A COPIARE IL FILE DICONFIGURAZIONE!");
    }
    sync();
    //system("/etc/rc.d/init.d/autoexec restart");
    system("reboot");
}

void page200::on_atcmButton_3_clicked()
{
    QFile::remove("/local/etc/sysconfig/application.conf");
    if (QFile::copy("/local/etc/sysconfig/application_can1_off.conf", "/local/etc/sysconfig/application.conf") == false)
    {
        QMessageBox::critical(0,"ERROR", "NON RIESCO A COPIARE IL FILE DICONFIGURAZIONE!");
    }
    sync();
    //system("/etc/rc.d/init.d/autoexec restart");
    system("reboot");
}
