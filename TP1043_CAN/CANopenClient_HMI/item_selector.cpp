/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Item selector dialog
 */
#include <QDir>
#include <QFileInfo>

#include "app_logprint.h"
#include "main.h"
#include "item_selector.h"
#include "ui_item_selector.h"

#define WINDOW_TITLE "ITEM SELECTOR"

/**
 * @brief this macro is used to set the item_selector style.
 * the syntax is html stylesheet-like
 */
#define SET_SELECT_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
item_selector::item_selector(QStringList list, QString * selection, QString title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::item_selector)
{
    ui->setupUi(this);
    SET_DIALOG_STYLE();
    SET_SELECT_STYLE();
    
    if (title.length() > 0)
    {
        ui->labelTitle->setText(title);
    }
    else
    {
        ui->labelTitle->setText(WINDOW_TITLE);
    }
    
    _selection = selection;
    _list = & list;
    reload();
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void item_selector::reload()
{
    /* show the trend present into the file system */
    ui->listWidget->clear();
    
    if (_list->count() > 0)
    {
        for (int i = 0; i < _list->count(); i++)
        {
            ui->listWidget->addItem(_list->at(i));
            LOG_PRINT(info_e, "trend '%s'\n", _list->at(i).toAscii().data());
        }
    }
    else
    {
        LOG_PRINT(error_e, "No trend to show\n");
        reject();
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
item_selector::~item_selector()
{
    delete ui;
}

void item_selector::on_pushButtonView_clicked()
{
    if ( ui->listWidget->currentIndex().isValid())
    {
        *_selection = ui->listWidget->currentItem()->text();
        accept();
    }
}

void item_selector::on_pushButtonBack_clicked()
{
    reject();
}

