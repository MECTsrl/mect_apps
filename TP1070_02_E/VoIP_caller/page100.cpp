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

#include <QCoreApplication>

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append("QPushButton:checked  { background-color: rgb(255, 170,   0); }"); \
    mystyle.append("QPushButton:disabled { background-color: rgb(170, 170, 127); }"); \
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

    busy = true;
    enableDisableButtons();
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

void page100::enableDisableButtons()
{
    busy = ! busy;
    ui->pushButton_AudioCenter->setEnabled(!busy);
    ui->pushButton_AudioLeft->setEnabled(!busy);
    ui->pushButton_AudioRight->setEnabled(!busy);
    ui->pushButton_Call_5010->setEnabled(!busy);
    ui->pushButton_Call_5030->setEnabled(!busy);
    ui->label_BusyReady->setText(busy ? "BUSY" : "READY");
    QCoreApplication::processEvents();
}

void page100::on_pushButton_AudioLeft_clicked()
{
    if (! busy) {
        enableDisableButtons();
        system("amixer sset Playback 85%,0% ; aplay /local/root/Front_Left.wav");
        enableDisableButtons();
    }
}

void page100::on_pushButton_AudioCenter_clicked()
{
    if (! busy) {
        enableDisableButtons();
        system("amixer sset Playback 85%,85% ; aplay /local/root/Front_Center.wav");
        enableDisableButtons();
    }
}

void page100::on_pushButton_AudioRight_clicked()
{
    if (! busy) {
        enableDisableButtons();
        system("amixer sset Playback 0%,85% ; aplay /local/root/Front_Right.wav");
        enableDisableButtons();
    }
}


void page100::on_pushButton_Call_5010_toggled(bool checked)
{
    if (! busy) {
        if (checked) {
            ui->pushButton_Call_5030->setChecked(false);
            enableDisableButtons();
            system("/root/call_5010.sh");
            enableDisableButtons();
        } else {
            system("killall pjsua");
        }
    }
}

void page100::on_pushButton_Call_5030_toggled(bool checked)
{
    if (! busy) {
        if (checked) {
            ui->pushButton_Call_5010->setChecked(false);
            enableDisableButtons();
            system("/root/call_5030.sh");
            enableDisableButtons();
        } else {
            system("killall pjsua");
        }
    }
}
