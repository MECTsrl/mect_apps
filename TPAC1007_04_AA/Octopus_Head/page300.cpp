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
#include "page300.h"
#include "ui_page300.h"
#include "crosstable.h"

// Octopus
#include "automation.h"

/**
 * @brief this macro is used to set the PAGE300 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page300::page300(QWidget *parent) :
    page(parent),
    ui(new Ui::page300)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE300_STYLE */
    SET_PAGE300_STYLE();
    translateFontSize(this);

    // Octopus
    qtitle.clear();
    qtext.clear();
    setTheWidget(this);
}

// Octopus
void page300::messageBox(const int result, const char *text)
{
    switch (result) {
    case RESULT_OK:
        qtitle = QString("OK :)");
        qcolor = QColor(170, 255, 255, 192);
        doWrite_PLC_BUZZER(0x02281464);
        break;
    case RESULT_NG:
        qtitle = QString("NG :(");
        qcolor = QColor(255, 127, 127, 192);
        doWrite_PLC_BUZZER(0x03281464); // in plc
        break;
    case RESULT_UNKNOWN:
    default:
        qtitle = QString("?? :|");
        qcolor = QColor(255, 255, 170, 192);
        doWrite_PLC_BUZZER(0x05281464);
    }
    qtext = QString(text);
}

// Octopus
void page300::setMessage(const char *msg)
{
    ui->label_msg->setText(msg);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page300::reload()
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
void page300::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    ui->label_versions->setText(QString("%1 / %2").arg((PLC_HMI_Version / 1000.0), 0, 'f', 3).arg((PLC_PLC_Version / 1000.0), 0, 'f', 3));

    // Octopus
    ui->label->setText(QString("A=%1 R=%2") .arg(AUTOMATIC) .arg(DO_REPEAT));
    if (! qtitle.isEmpty() ) {

        ui->atcmButton_message->setText(QString("%1\n\n%2").arg(qtitle).arg(qtext));
        ui->atcmButton_message->setBgColor(qcolor);
//        doWrite_PLC_buzzerOn(1);
        doWrite_MESSAGE_BOX(1);

        qtitle.clear();
        qtext.clear();
    }
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page300::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page300::~page300()
{
    delete ui;
}


void page300::on_atcmComboBox_PRODUCT_ID_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    doWrite_DO_RELOAD(1);
}

void page300::on_atcmComboBox_TEST_ID_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    doWrite_DO_RELOAD(1);
}

void page300::on_atcmButton_message_toggled(bool checked)
{
    if (checked) {
//        doWrite_PLC_buzzerOn(0);
    }
}
