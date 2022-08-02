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
#include "page400.h"
#include "ui_page400.h"
#include "crosstable.h"
#include "automation.h"
#include "alphanumpad.h"

/**
 * @brief this macro is used to set the PAGE400 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE400_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page400::page400(QWidget *parent) :
    page(parent),
    ui(new Ui::page400)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE400_STYLE */
    SET_PAGE400_STYLE();
    translateFontSize(this);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page400::reload()
{
    ui->atcmButton_1->setText(listElements.at(0));
    ui->atcmButton_2->setText(listElements.at(1));
    ui->atcmButton_3->setText(listElements.at(2));
    ui->atcmButton_4->setText(listElements.at(3));
    ui->atcmButton_5->setText(listElements.at(4));
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page400::updateData()
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
void page400::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page400::~page400()
{
    delete ui;
}


void page400::on_atcmButton_SaveList_clicked()
{
    int nSaved = saveList();
    qDebug("Saved [%d] Items", nSaved);
}

void page400::on_atcmButton_1_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = listElements.at(0);

    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        listElements[0] = szCurrentValue;
        ui->atcmButton_1->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}

void page400::on_atcmButton_2_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = listElements.at(1);

    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        listElements[1] = szCurrentValue;
        ui->atcmButton_2->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}

void page400::on_atcmButton_3_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = listElements.at(2);

    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        listElements[2] = szCurrentValue;
        ui->atcmButton_3->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}

void page400::on_atcmButton_4_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = listElements.at(3);

    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        listElements[3] = szCurrentValue;
        ui->atcmButton_4->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}

void page400::on_atcmButton_5_clicked()
{
    char            value[STR_LEN];
    memset(value, 0, STR_LEN);
    alphanumpad     *userKeyboard;                   // User Keyboard Pointer
    QString         szCurrentValue = listElements.at(4);

    userKeyboard = new alphanumpad(value, true, szCurrentValue.toLatin1().data(), false, this);
    userKeyboard->showFullScreen();
    if(userKeyboard->exec() == QDialog::Accepted)
    {
        szCurrentValue = QString(value).trimmed();
        listElements[4] = szCurrentValue;
        ui->atcmButton_5->setText(szCurrentValue);
    }
    userKeyboard->deleteLater();
}
