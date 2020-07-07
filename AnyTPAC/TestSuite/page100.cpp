/**
 * @file
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

#include "automation.h"

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

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(-1);

    colorDisabled = QColor(128, 128, 128);
    colorTesting  = QColor(255, 255,   0);
    colorPassed   = QColor(  0, 255,   0);
    colorFailed   = QColor(255,   0,   0);

    // update the color legend
    ui->test_label_DISABLED->setBgColor(colorDisabled);
    ui->test_label_TESTING->setBgColor(colorTesting);
    ui->test_label_PASSED->setBgColor(colorPassed);
    ui->test_label_FAILED->setBgColor(colorFailed);
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

    switch (Status) {
    case STATUS_ZERO:
        ui->comboBoxLogLevel->setEnabled(false);
        ui->buttonSTART->setVisible(false);
        ui->buttonSTOP->setVisible(false);
        ui->buttonRESET->setVisible(false);
        break;
    case STATUS_IDLE:
        ui->comboBoxLogLevel->setEnabled(true);
        ui->buttonSTART->setVisible(true);
        ui->buttonSTOP->setVisible(false);
        ui->buttonRESET->setVisible(false);
        break;
    case STATUS_RUNNING:
        ui->comboBoxLogLevel->setEnabled(false);
        ui->buttonSTART->setVisible(false);
        ui->buttonSTOP->setVisible(true);
        ui->buttonRESET->setVisible(false);
        break;
    case STATUS_DONE:
        ui->comboBoxLogLevel->setEnabled(true);
        ui->buttonSTART->setVisible(true);
        ui->buttonSTOP->setVisible(false);
        ui->buttonRESET->setVisible(true);
        break;
    default:
        ;
    }

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(Target);
    ui->progressBar->setValue(Loops);

    updateTestLabel(ui->test_label_01, test_level_01);
    updateTestLabel(ui->test_label_02, test_level_02);
    updateTestLabel(ui->test_label_03, test_level_03);
    updateTestLabel(ui->test_label_04, test_level_04);
    updateTestLabel(ui->test_label_05, test_level_05);
    updateTestLabel(ui->test_label_06, test_level_06);
    updateTestLabel(ui->test_label_07, test_level_07);
    updateTestLabel(ui->test_label_08, test_level_08);
    updateTestLabel(ui->test_label_09, test_level_09);
    updateTestLabel(ui->test_label_10, test_level_10);
    updateTestLabel(ui->test_label_11, test_level_11);
    updateTestLabel(ui->test_label_12, test_level_12);
    updateTestLabel(ui->test_label_13, test_level_13);
    updateTestLabel(ui->test_label_14, test_level_14);
    updateTestLabel(ui->test_label_15, test_level_15);
    updateTestLabel(ui->test_label_16, test_level_16);
    updateTestLabel(ui->test_label_17, test_level_17);
    updateTestLabel(ui->test_label_18, test_level_18);
    updateTestLabel(ui->test_label_19, test_level_19);
    updateTestLabel(ui->test_label_20, test_level_20);
    updateTestLabel(ui->test_label_21, test_level_21);
    updateTestLabel(ui->test_label_22, test_level_22);
    updateTestLabel(ui->test_label_23, test_level_23);
    updateTestLabel(ui->test_label_24, test_level_24);
    updateTestLabel(ui->test_label_25, test_level_25);
    updateTestLabel(ui->test_label_26, test_level_26);
    updateTestLabel(ui->test_label_27, test_level_27);
    updateTestLabel(ui->test_label_28, test_level_28);
    updateTestLabel(ui->test_label_29, test_level_29);
    updateTestLabel(ui->test_label_30, test_level_30);
    updateTestLabel(ui->test_label_31, test_level_31);
    updateTestLabel(ui->test_label_32, test_level_32);
    updateTestLabel(ui->test_label_33, test_level_33);
    updateTestLabel(ui->test_label_34, test_level_34);
    updateTestLabel(ui->test_label_35, test_level_35);
    updateTestLabel(ui->test_label_36, test_level_36);
    updateTestLabel(ui->test_label_37, test_level_37);
    updateTestLabel(ui->test_label_38, test_level_38);
    updateTestLabel(ui->test_label_39, test_level_39);
    updateTestLabel(ui->test_label_40, test_level_40);
    updateTestLabel(ui->test_label_41, test_level_41);
    updateTestLabel(ui->test_label_42, test_level_42);
    updateTestLabel(ui->test_label_43, test_level_43);
    updateTestLabel(ui->test_label_44, test_level_44);
    updateTestLabel(ui->test_label_45, test_level_45);
    updateTestLabel(ui->test_label_46, test_level_46);
    updateTestLabel(ui->test_label_47, test_level_47);
    updateTestLabel(ui->test_label_48, test_level_48);
    updateTestLabel(ui->test_label_49, test_level_49);
    updateTestLabel(ui->test_label_50, test_level_50);
    updateTestLabel(ui->test_label_51, test_level_51);
    updateTestLabel(ui->test_label_52, test_level_52);
    updateTestLabel(ui->test_label_53, test_level_53);
    updateTestLabel(ui->test_label_54, test_level_54);
    updateTestLabel(ui->test_label_55, test_level_55);
    updateTestLabel(ui->test_label_56, test_level_56);
    updateTestLabel(ui->test_label_57, test_level_57);
    updateTestLabel(ui->test_label_58, test_level_58);
    updateTestLabel(ui->test_label_59, test_level_59);
    updateTestLabel(ui->test_label_60, test_level_60);
}

void page100::updateTestLabel(ATCMlabel *test_label, unsigned test_level)
{
    switch (test_level) {
    case TEST_DISABLED:
        test_label->setBgColor(colorDisabled);
        break;
    case TEST_TESTING:
        test_label->setBgColor(colorTesting);
        break;
    case TEST_PASSED:
        test_label->setBgColor(colorPassed);
        break;
    case TEST_FAILED:
        test_label->setBgColor(colorFailed);
        break;
    default:
        test_label->setBgColor(colorDisabled);
    }
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


