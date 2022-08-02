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
#include "page200.h"
#include "ui_page200.h"
#include "crosstable.h"
#include "automation.h"

/**
 * @brief this macro is used to set the PAGE200 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE200_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stylesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page200::page200(QWidget *parent) :
    page(parent),
    ui(new Ui::page200)
{
    ui->setupUi(this);
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE200_STYLE */
    SET_PAGE200_STYLE();
    translateFontSize(this);
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page200::reload()
{
    ui->atcmComboBox->clear();
    // Load only the values managed in the retentive, ignore any other values
    for (int nItem = 0; nItem < requiredItems; nItem++)  {
        if (nItem < listElements.count())  {
            ui->atcmComboBox->addItem(listElements.at(nItem));
        }
        else  {
            ui->atcmComboBox->addItem(NO_VALUE);
        }
    }
    ui->atcmComboBox->setCurrentIndex(0);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page200::updateData()
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
void page200::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page200::~page200()
{
    delete ui;
}


void page200::on_atcmComboBox_currentIndexChanged(int index)
{
    doWrite_selectedItem(index);
}
