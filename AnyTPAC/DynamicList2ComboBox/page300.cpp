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
#include "automation.h"
#include "alphanumpad.h"


/**
 * @brief this macro is used to set the PAGE300 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
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
    /* set the style described into the macro SET_PAGE300_STYLE */
    SET_PAGE300_STYLE();
    translateFontSize(this);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page300::reload()
{
    ui->atcmComboBox->clear();
    for (int nItem = 0; nItem < requiredItems; nItem++)  {
        QString textItem = QString("Elemento [%1]") .arg(nItem + 1);
        ui->atcmComboBox->addItem(textItem);
    }
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


void page300::on_atcmComboBox_currentIndexChanged(int index)
{
    doWrite_selectedItem(index);
    if (index >= 0 && index < listElements.count())  {
        ui->pushButton->setText(listElements.at(index));
    }
    else  {
        ui->pushButton->setText(NO_VALUE);
    }
}

void page300::on_pushButton_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = QString(NO_VALUE);

    // Retrieve current value from list for alphanumpad
    if (selectedItem >= 0 && selectedItem < listElements.count())  {
        szCurrentValue = listElements.at(selectedItem);
    }
    else  {
        // Index out of range of list items
        return;
    }
    qDebug("Calling alphanumpad - Def.Value:[%s]", szCurrentValue.toLatin1().data());
    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        qDebug("Label for index:[%d] changed to:[%s]", selectedItem, value);
        listElements[selectedItem] = szCurrentValue;
        ui->pushButton->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}

void page300::on_atcmButton_SaveList_clicked()
{
    int nSaved = saveList();
    qDebug("Saved [%d] Items", nSaved);
}
