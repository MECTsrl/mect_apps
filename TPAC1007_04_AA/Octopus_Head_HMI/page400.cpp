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
#include "page400.h"
#include "ui_page400.h"
#include "automation.h"

/**
 * @brief this macro is used to set the PAGE400 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE400_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
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
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page400::updateData()
{
    if (this->isVisible() == false) {
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

void page400::on_atcmComboBox_TEST_ID_currentIndexChanged(const QString &arg1)
{
    loadRecipe(ui->atcmComboBox_PRODUCT_ID->currentText(), arg1);
}
