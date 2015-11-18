/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Configuration page
 */
#include "app_logprint.h"
#include "main.h"
#include "options.h"
#include "ui_options.h"
#ifdef TRANSLATION
#include "item_selector.h"
#include <QDirIterator>
#include <QHash>
#define LANGUAGE_MAP_FILE "/local/etc/sysconfig/lang_table.csv"
#endif

/* this define set the window title */
#define WINDOW_TITLE "CONFIGURATION"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the current page style.
 * the syntax is html stylesheet-like
 */
#define SET_OPTION_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
options::options(QWidget *parent) :
    page(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* if exist and is not empty enable the WINDOW_ICON */
    if (strlen(WINDOW_ICON) > 0)
    {
        /* enable this line, define the WINDOW_ICON and put a Qlabel named labelIcon in your ui file if you want have a window icon */
        labelIcon = ui->labelIcon;
    }
    /* if exist and is not empty enable the WINDOW_TITLE */
    if (strlen(WINDOW_TITLE) > 0)
    {
        /* enable this line, define the WINDOW_TITLE and put a Qlabel named labelTitle in your ui file if you want have a window title */
        labelTitle = ui->labelTitle;
    }
    
    /* set up the page style */
    SET_PAGE_STYLE();
    /* set the style described into the macro SET_OPTION_STYLE */
    SET_OPTION_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void options::reload()
{
    if (active_password == pwd_operator_e)
    {
        ui->pushButtonPasswords->setEnabled(false);
    }
    else
    {
        ui->pushButtonPasswords->setEnabled(true);
    }
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void options::updateData()
{
    /* call the parent updateData member */
    page::updateData();
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void options::changeEvent(QEvent * event)
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
options::~options()
{
    delete ui;
}


void options::on_pushButtonDateAndTime_clicked()
{
    goto_page("time_set");
}

void options::on_pushButtonPasswords_clicked()
{
    int min = 0, max = 999999;
    numpad * dk;
    
    int password;
    dk = new numpad(&password, NO_DEFAULT, min, max,true);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (password < min || password > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value is invalid.\nThe value must ranging between %2 and %3").arg(min).arg(max));
            delete dk;
            return;
        }
        
        passwords[active_password] = password;
        if (dumpPasswords())
        {
            QMessageBox::information(this,tr("Password changed"), tr("The password is succesfully changed."));
        }
        else
        {
            QMessageBox::critical(this,tr("Saving error"), tr("Cannot save the new password."));
        }
    }
    else
    {
    }
    delete dk;
}

void options::on_pushButtonModbus_clicked()
{
    goto_page("commpar_rtu");
}

void options::on_pushButtonErrorsStrategy_clicked()
{
    goto_page("sgdd");
}

void options::on_pushButtonDatalog_clicked()
{
    goto_page("datalog_set");
}

void options::on_pushButtonHomePage_clicked()
{
    if (setAsStartPage(HomePage))
    {
        QMessageBox::information(this,tr("Intal page"), tr("The initial page is resetted."));
    }
}

void options::on_pushButtonHome_clicked()
{
    go_home();
}

void options::on_pushButtonBack_clicked()
{
    go_back();
}


void options::on_pushButtonDisplaySettings_clicked()
{
    goto_page("display_settings");
}

void options::on_pushButtonBuzzerSettings_clicked()
{
    goto_page("buzzer_settings");
}



void options::on_pushButtonLanguage_clicked()
{
#ifdef TRANSLATION
    /* load the map of the language and his locale abbreviation */
    QHash<QString, QString> LanguageMap;
    FILE * fp = fopen(LANGUAGE_MAP_FILE, "r");
    if (fp)
    {
        char line[32];
        while (fgets(line, LINE_SIZE, fp) != NULL)
        {
            char * key, * value;
            key = strchr(line, ';') + 1;
            *strchr(line, ';') = '\0';
            value = line;
            LanguageMap.insert(QString(key).trimmed(),QString(value).trimmed());
            LOG_PRINT(info_e, "tag %s item %s\n", key, value);
        }
        fclose(fp);
    }
    
    /* load the translations file list */
    item_selector * sel;
    QString value;
    QDirIterator it(":/translations", QDirIterator::Subdirectories);
    QStringList languageList;
    while (it.hasNext()) {
        QString item = it.next();
        LOG_PRINT(error_e, " %s\n", item.toAscii().data());
        if (item.endsWith (".qm") == true)
        {
            if(LanguageMap.count() > 0)
            {
                languageList << LanguageMap.value(item.mid(item.indexOf("languages_") + strlen("languages_"), 2));
            }
            else
            {
                languageList << item.mid(item.indexOf("languages_") + strlen("languages_"), 2);
            }
        }
    }
    
    /* prepare the language selector page */
    if (languageList.count() > 1)
    {
        sel = new item_selector(languageList, &value, tr("LANGUAGE SELECTOR"));
        sel->showFullScreen();
        
        if (sel->exec() == QDialog::Accepted)
        {
            if(LanguageMap.count() > 0)
            {
                strcpy(_language_, (LanguageMap.key(value)).toAscii().data());
            }
            else
            {
                strcpy(_language_, value.toAscii().data());
            }
            LOG_PRINT(error_e, "_language_ '%s'\n", _language_);
            if(translator->load(QString(":/translations/languages_%1.qm").arg(_language_)))
            {
                /* install the selected language */
                qApp->installTranslator(translator);
                QMessageBox::information(this,tr("Language"), tr("The language selected is '%1'").arg(value));
            }
            else
            {
                QMessageBox::critical(this,tr("Language"), tr("Error lading translation file '%1'").arg(QString(":/translations/languages_%1.qm").arg(_language_)));
                LOG_PRINT(error_e, "loading language file\n");
            }
        }
        else
        {
            LOG_PRINT(error_e, "No language selected\n");
        }
        delete sel;
    }
    else
    {
        QMessageBox::critical(this,tr("Language"), tr("No language translation are available"));
        LOG_PRINT(error_e, "No language to show\n");
    }
#else
    QMessageBox::critical(this,tr("Language"), tr("No language translation are available"));
#endif
}

