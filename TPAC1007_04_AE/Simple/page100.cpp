/**
 * @file
 *
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

#include <QDebug>
#include <QString>

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
    if (NODE_01_STATUS == 1) {
        ui->atcmRTU_Start->setChecked(true);
    }
    else  {
        ui->atcmRTU_Start->setChecked(false);
    }
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

    // Abilitazione interfaccia se NODE_01 è collegato
    if (PLC_EngineStatus >= 2)  {
        ui->atcmButton_PLC_DigDir_1->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_1->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_2->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_2->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_3->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_3->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_4->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_4->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_5->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_5->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_6->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_6->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_7->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_7->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigDir_8->setEnabled(NODE_01_STATUS == 1);
        ui->atcmButton_PLC_DigOut_8->setEnabled(NODE_01_STATUS == 1);
    }

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

void page100::on_atcmRTU_Start_toggled(bool checked)
{
    qDebug("Node_01_Status: %d",  NODE_01_STATUS);
    if (checked)  {
        // Force Node_01 Start
        if (NODE_01_STATUS != 0)  {
            qDebug("NODE [%d] Start Required", NODE_01_DEV_NODE);
            doWrite_NODE_01_STATUS(1);
        }
        usleep(800);
    }
    else {
        // Force Node_01 Stop
        qDebug("Richiesto Stop NODO");
        usleep(800);
        if (NODE_01_STATUS != 0) {
            qDebug("NODE [%d] Stop Required", NODE_01_DEV_NODE);
            doWrite_NODE_01_STATUS(0);
        }
    }
}

