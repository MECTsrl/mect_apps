/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief display the file SPLASH_FILE for SPLASH_TIMEOUT_MS milliseconds
 */
#include "main.h"
#include "page0.h"
#include "app_logprint.h"
#include "ui_page0.h"

#include <QTimer>
#include <QFile>
#include <QMessageBox>
#ifdef TARGET
#ifdef ENABLE_SCREENSAVER
#include "screensaver.h"
#endif
#endif

page0::page0(QWidget *parent) :
    page(parent),
    ui(new Ui::page0)
{
    ui->setupUi(this);
    
    /* load and show the splash screen*/
    QPixmap splash;
    if (splash.load(SPLASH_FILE))
    {
        LOG_PRINT(info_e, "Splash file: '%s'\n", SPLASH_FILE);
        ui->label->setPixmap(splash);
        ui->label->update();
    }
    else
    {
        LOG_PRINT(info_e, "Cannot load splash file: '%s'\n", SPLASH_FILE);
    }
    
    first_time = true;
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void page0::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}
#endif

page0::~page0()
{
    delete ui;
}

void page0::reload()
{
    /* stop the unused refresh timer */
    refresh_timer->stop();
    
    /* prepare the splash screen time out */
    QTimer::singleShot(10, this, SLOT(changePage()));
}

void page0::changePage()
{
    if (first_time == true)
    {
        /* load the tag table if it is present */
        loadTagTable();
        if(CommStart() == false)
        {
            exit(0);
        }
        first_time = false;
    }
    
    LOG_PRINT(info_e, "CHANGE PAGE\n");
    /* go to the home page */
    if (goto_page(StartPage) == false && goto_page(STARTPAGE) == false && goto_page(HomePage) == false && goto_page(HOMEPAGE) == false )
    {
        QMessageBox::critical(0,QApplication::tr("Invalid Page"), QApplication::tr("Cannot show any of Default pages '%1', '%2' and home pages '%3'. '%4'").arg(StartPage).arg(STARTPAGE).arg(HomePage).arg(HOMEPAGE));
    }
    this->hide();
}



