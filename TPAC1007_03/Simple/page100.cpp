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
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#include <qwt.h>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>

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

    // Creating Needle for qwtDial1
    QwtDialSimpleNeedle *needle1 = new QwtDialSimpleNeedle(
                QwtDialSimpleNeedle::Arrow, true, Qt::red,
                QColor(Qt::gray).light(130));
    // Setting Needle for qwtDial1
    ui->qwtDial1->setNeedle(needle1);

    // Creating Needle for qwtDial2
    QwtDialSimpleNeedle *needle2 = new QwtDialSimpleNeedle(
                QwtDialSimpleNeedle::Arrow, true, Qt::blue,
                QColor(Qt::gray).light(130));
    // Setting Needle for qwtDial2
    ui->qwtDial2->setNeedle(needle2);

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
    // Reading Analog Input 1 and setting to Dial 1
    ui->qwtDial1->setValue(PLC_AnIn_1 / 1000);

    // Reading Analog Input 2 and setting to Dial 2
    ui->qwtDial2->setValue(PLC_AnIn_2 / 1000);

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



void page100::on_atcmButton_Log_clicked(bool checked)
{
    if (checked)
        logStart();
    else
        logStop();
}
