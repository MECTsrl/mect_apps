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
#include "tagreader.h"

/**
 * @brief this macro is used to set the PAGE100 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
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
    QString szUndef = "border-image: url(\":/systemicons/LedGrey.png\");";      // Grey
    ui->labelImg_01->setStyleSheet(szUndef);
    ui->labelImg_02->setStyleSheet(szUndef);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page100::updateData()
{
    QString szYellow    = "border-image: url(\":/systemicons/LedYellow.png\");";     // Yellow
    QString szRed       = "border-image: url(\":/systemicons/LedOff.png\");";        // Rosso
    QString szGreen     = "border-image: url(\":/systemicons/LedOn.png\");";         // Verde
    QString szNewStyle;

    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();

    // Lettore Collegato
    if (readerFound)  {
        szNewStyle = szGreen;
    }
    else  {
        szNewStyle = szYellow;
    }
    if (ui->labelImg_02->styleSheet() != szNewStyle)  {
        ui->labelImg_02->setStyleSheet(szNewStyle);
    }
    // Tag Letto
    if (! readerFound)  {
        szNewStyle = szYellow;
    }
    else if (! cardFound)  {
        szNewStyle = szGreen;
    }
    else if (cardFound)  {
        szNewStyle = szRed;
    }
    if (ui->labelImg_01->styleSheet() != szNewStyle)  {
        ui->labelImg_01->setStyleSheet(szNewStyle);
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


