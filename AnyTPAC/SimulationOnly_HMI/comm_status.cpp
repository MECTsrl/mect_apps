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
#include "main.h"
#include "comm_status.h"
#include "ui_comm_status.h"

#define LED_UNK "rgb(120,120,120)"
#define LED_ON  "rgb(  0,255,  0)"
#define LED_OFF "rgb(255,  0,  0)"

/**
 * @brief this macro is used to set the COMM_STATUS style.
 * the syntax is html stylesheet-like
 */
#define SET_COMM_STATUS_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
comm_status::comm_status(QWidget *parent) :
    page(parent),
    ui(new Ui::comm_status)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_COMM_STATUS_STYLE */
    SET_COMM_STATUS_STYLE();
    translateFontSize(this);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void comm_status::reload()
{
    ui->comboBoxTypeRTU->addItem(TAG_BLACKLIST);
    ui->comboBoxTypeRTU->addItem(TAG_OTHER);
    ui->comboBoxTypeTCP->addItem(TAG_BLACKLIST);
    ui->comboBoxTypeTCP->addItem(TAG_OTHER);
    ui->comboBoxTypeTCPRTU->addItem(TAG_BLACKLIST);
    ui->comboBoxTypeTCPRTU->addItem(TAG_OTHER);
    
    ui->pushButtonNodeTCP->setText("1");
    
    for (int i = 0; i < DB_SIZE_ELEM; i++)
    {
        if (varNameArray[i].node != 0 && varNameArray[i].node != INTERNAL_VARIABLE_FAKE_NODEID && ui->comboBoxNodeRTU->findText(QString("%1").arg(varNameArray[i].node)) < 0 && varNameArray[i].protocol == prot_rtu_e)
        {
            ui->comboBoxNodeRTU->addItem(QString("%1").arg(varNameArray[i].node));
        }
    }
    
    for (int i = 0; i < DB_SIZE_ELEM; i++)
    {
        if (varNameArray[i].node != 0 && varNameArray[i].node != INTERNAL_VARIABLE_FAKE_NODEID && ui->comboBoxNodeTCPRTU->findText(QString("%1").arg(varNameArray[i].node)) < 0 && varNameArray[i].protocol == prot_tcprtu_e)
        {
            ui->comboBoxNodeTCPRTU->addItem(QString("%1").arg(varNameArray[i].node));
        }
    }
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void comm_status::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    if (IS_TCP_ENABLED)
    {
        /* Error counters */
        ui->labelConuterTCPval->setText(QString("%1").arg(getErrorCounter(prot_tcp_e, ui->pushButtonNodeTCP->text().toInt())));
        /* Node status */
        switch(getErrorBitByName(TAG_TCP, ui->comboBoxTypeTCP->currentText().toAscii().data(), ui->pushButtonNodeTCP->text().toInt()))
        {
        case 0:
            ui->labelErrorBitTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorBitTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorBitTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
        /* Prootocol status */
        switch(getErrorStatusByName(TAG_TCP, ui->comboBoxTypeTCP->currentText().toAscii().data()))
        {
        case 0:
            ui->labelErrorStatusTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorStatusTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorStatusTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
    }
    else
    {
        /* Error counters */
        ui->labelConuterTCPval->setText("N/A");
        /* Node status */
        ui->labelErrorBitTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
        /* Prootocol status */
        ui->labelErrorStatusTCPval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
    }
    
    if (IS_RTU_ENABLED)
    {
        /* Error counters */
        ui->labelConuterRTUval->setText(QString("%1").arg(getErrorCounter(prot_rtu_e, ui->comboBoxNodeRTU->currentText().toInt())));
        /* Node status */
        switch(getErrorBitByName(TAG_RTU, ui->comboBoxTypeRTU->currentText().toAscii().data(),  ui->comboBoxNodeRTU->currentText().toInt()))
        {
        case 0:
            ui->labelErrorBitRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorBitRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorBitRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
        /* Prootocol status */
        switch(getErrorStatusByName(TAG_RTU, ui->comboBoxTypeRTU->currentText().toAscii().data()))
        {
        case 0:
            ui->labelErrorStatusRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorStatusRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorStatusRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
    }
    else
    {
        /* Error counters */
        ui->labelConuterRTUval->setText("N/A");
        /* Node status */
        ui->labelErrorBitRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
        /* Prootocol status */
        ui->labelErrorStatusRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
    }
    if (IS_TCPRTU_ENABLED)
    {
        /* Error counters */
        ui->labelConuterTCPRTUval->setText(QString("%1").arg(getErrorCounter(prot_tcprtu_e, ui->comboBoxNodeTCPRTU->currentText().toInt())));
        /* Node status */
        switch(getErrorBitByName(TAG_TCPRTU, ui->comboBoxTypeTCPRTU->currentText().toAscii().data(), ui->comboBoxNodeTCPRTU->currentText().toInt()))
        {
        case 0:
            ui->labelErrorBitTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorBitTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorBitTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
        /* Prootocol status */
        switch(getErrorStatusByName(TAG_TCPRTU, ui->comboBoxTypeTCPRTU->currentText().toAscii().data()))
        {
        case 0:
            ui->labelErrorStatusTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_ON";");
            break;
        case 1:
            ui->labelErrorStatusTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_OFF";");
            break;
        default:
            ui->labelErrorStatusTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
            break;
        }
    }
    else
    {
        /* Error counters */
        ui->labelConuterTCPRTUval->setText("N/A");
        /* Node status */
        ui->labelErrorBitTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
        /* Prootocol status */
        ui->labelErrorStatusTCPRTUval->setStyleSheet("border-radius: 10px; background-color: "LED_UNK";");
    }
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void comm_status::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}
#endif

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
comm_status::~comm_status()
{
    delete ui;
}



void comm_status::on_pushButtonResetTCP_clicked()
{
    resetError(prot_tcp_e);
}

void comm_status::on_pushButtonResetRTU_clicked()
{
    resetError(prot_rtu_e);
}

void comm_status::on_pushButtonResetTCPRTU_clicked()
{
    resetError(prot_tcprtu_e);
}

void comm_status::on_pushButtonNodeTCP_clicked()
{
    int min = 0, max = 32;
    numpad * dk;
    
    int node = 1;
    dk = new numpad(&node, ui->pushButtonNodeTCP->text().toInt(), min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (node < min || node > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(node).arg(min).arg(max));
            delete dk;
            return;
        }
        ui->pushButtonNodeTCP->setText(QString("%1").arg(node));
    }
    else
    {
    }
    delete dk;
}

void comm_status::on_pushButtonHome_clicked()
{
    go_home();
}

void comm_status::on_pushButtonBack_clicked()
{
    goto_page("data_manager");
}


