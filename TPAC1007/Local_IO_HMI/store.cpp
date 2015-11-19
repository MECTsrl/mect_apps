/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#include <QMessageBox>
#include <QTableWidget>
#include <QDir>
#include <errno.h>

#include "app_logprint.h"
#include "app_usb.h"
#include "main.h"
#include "store.h"
#include "store_extract.h"
#include "app_usb.h"
#include "ui_store.h"

#define LINE_BUFFER_SIZE 5

/* this define set the variables list to be to displayed in this page */
#undef VAR_TO_DISPLAY
/* Example:
#define VAR_TO_DISPLAY "RET_REG_1" << "RET_REG_3" << "NRE_REG_1"
 */
/* this define set the window title */
#define WINDOW_TITLE "STORE"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the store style.
 * the syntax is html stylesheet-like
 */
#define SET_STORE_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
store::store(QWidget *parent) :
    page(parent),
    ui(new Ui::store)
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
    
    SET_PAGE_STYLE();
    SET_STORE_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    actual_filter = NULL;
    logfp = NULL;
    
    /* set as default current day */
    StoreInit = QDateTime(QDate::currentDate(), QTime(0,0,0));
    StoreFinal = QDateTime(QDate::currentDate(), QTime(23,59,59));
    
    //reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void store::reload()
{
    force_back = false;
    
    if (logfp != NULL)
    {
        fclose(logfp);
        logfp = NULL;
    }
    
    char filename[FILENAME_MAX];
    if (QFileInfo(_actual_store_).suffix().compare("csv") == 0)
    {
        sprintf(filename, "%s/%s", CUSTOM_STORE_DIR, _actual_store_);
    }
    else
    {
        sprintf(filename, "%s/%s.csv", CUSTOM_STORE_DIR, _actual_store_);
    }
    
    /* load the actual store filter  */
    if (LoadStoreFilter(filename) == false)
    {
        QMessageBox::critical(this,tr("Malformed view"), tr("The view '%1' is malformed.").arg(_actual_store_));
        force_back = true;
        return;
    }
    LOG_PRINT(info_e, "_actual_store_ %s\n", _actual_store_);
    ui->labelName->setText(_actual_store_);
    
    /* get the file list */
    QDir logDir(STORE_DIR);
    logFileList = logDir.entryList(QDir::Files|QDir::NoDotAndDotDot, QDir::Reversed);
    
    ui->labelFilter->setText(QString("Filter: [%1 - %2]")
                             .arg(StoreInit.toString("yyyy/MM/dd hh:mm:ss"))
                             .arg(StoreFinal.toString("yyyy/MM/dd hh:mm:ss")));
    
    _current = 0;
    /* no logfile found */
    _file_nb = logFileList.count();
    if (_file_nb == 0)
    {
        LOG_PRINT(error_e, "No file to load\n");
        return;
    }
    
    /* load the current log file */
    LOG_PRINT(info_e, "_current %d\n",_current);
    
    /* load the actual daily store */
    if (LoadStore(StoreInit, StoreFinal) == false)
    {
        QMessageBox::critical(this,tr("Loading problem"), tr("Cannot load the log between %1 and %2.").arg(StoreInit.toString("yyyy/MM/dd hh:mm:ss")).arg(StoreFinal.toString("yyyy/MM/dd hh:mm:ss")));
        LOG_PRINT(info_e, "cannot load store, force back\n");
        force_back = true;
        go_back();
        return;
    }
    
    /* set the arrow button status in funtion of the visible items */
    ui->pushButtonLeft->setEnabled(current_column > 0);
    ui->pushButtonRight->setEnabled(current_column < sizeof_filter);
    ui->pushButtonUp->setEnabled(current_row > 0);
    ui->pushButtonDown->setEnabled(logfp != NULL || (current_row < ui->tableWidget->rowCount()));
    
    
}

/** @brief count the column of a csv file
 */
int store::getLogColumnNb(const char * filename)
{
    FILE * fp;
    char line[LINE_SIZE] = "";
    
    headerList.clear();
    
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", filename);
        return 0;
    }
    LOG_PRINT(info_e, "opened '%s'\n", filename);
    
    if (fgets(line, LINE_SIZE, fp) != NULL)
    {
        headerList = QString(line).simplified().replace(QString(" "), QString("")).split(SEPARATOR);
#if 0
        for (int i = 0; i < headerList.count(); i++)
        {
            LOG_PRINT(info_e, "%d - '%s'\n", i, headerList.at(i).toAscii().data());
        }
#endif
        fclose(fp);
    }
    else
    {
        return 0;
    }
    
    return headerList.count();
}

bool store::LoadStoreFilter(const char * filename)
{
    int rownb = 0;
    int columnnb = 0;
    FILE * fp;
    char line[LINE_SIZE] = "";
    char token[LINE_SIZE] = "";
    char * p;
    
    sprintf(line, "%s/%s", STORE_DIR, QDate::currentDate().toString("yyyy_MM_dd.log").toAscii().data());
    sizeof_filter = getLogColumnNb(line);
    if (sizeof_filter == 0)
    {
        return false;
    }
    
    if (actual_filter != NULL)
    {
        free(actual_filter);
    }
    actual_filter = (int*)calloc(sizeof_filter, sizeof(int));
    
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", filename);
        return false;
    }
    LOG_PRINT(info_e, "opened '%s'\n", line);
    /*
     * the file is formatted as
     * <Tag1>
     * ...
     * <TagN>
     */
    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        p = line;
        /* tag */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL && token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        
        columnnb = headerList.indexOf(token);
        if (columnnb>=0 && columnnb <= sizeof_filter)
        {
            actual_filter[columnnb] = 1;
        }
        LOG_PRINT(verbose_e, "tag '%s' actual_filter[%d] = %d\n", token, columnnb, actual_filter[columnnb]);
        rownb++;
    }
    fclose(fp);
    return (rownb > 0);
}

bool store::LoadStore(QDateTime init, QDateTime final)
{
    outputfile[0] = '\0';
    
    LOG_PRINT(info_e, "outputfile '%s'\n", outputfile);
    
    /* remove TMPDIR */
    if (StoreFilter(
                outputfile,
                STORE_DIR,
                TMPDIR,
                QString("%1/%2").arg(CUSTOM_STORE_DIR).arg(_actual_store_).toAscii().data(),
                init.date().toString("yyyy/MM/dd").toAscii().data(),
                init.time().toString("hh:mm:ss").toAscii().data(),
                final.date().toString("yyyy/MM/dd").toAscii().data(),
                final.time().toString("hh:mm:ss").toAscii().data()
                ) != 0)
    {
        LOG_PRINT(info_e, "outputfile '%s'\n", outputfile);
        return false;;
    }
    LOG_PRINT(info_e, "outputfile '%s'\n", outputfile);
    return LoadStore(QString("%1/%2").arg(TMPDIR).arg(outputfile).toAscii().data());
}
bool store::LoadStore(int fileNb)
{
    if (fileNb < 0 || fileNb > logFileList.count())
    {
        return false;
    }
    LOG_PRINT(info_e, "fileNb %d < %d\n", fileNb, logFileList.count());
    LOG_PRINT(info_e, "logFileList '%s'\n", logFileList.at(fileNb).toAscii().data());
    return LoadStore(QString(STORE_DIR + logFileList.at(fileNb)).toAscii().data());
}

bool store::LoadStore(const char * filename)
{
    char line[LINE_SIZE] = "";
    char token[LINE_SIZE] = "";
    char * p;
    QTableWidgetItem * item;
    
    ui->tableWidget->clear();
    current_row = 0;
    current_column = 0;
    
    int i ,j = 0;
    for (i = 0; i <= sizeof_filter; i++)
    {
        if (actual_filter[i] == 1)
        {
            ui->tableWidget->insertColumn(j);
            LOG_PRINT(info_e, "Inserted column '%d'\n", j);
            j++;
        }
    }
    
    ui->tableWidget->verticalHeader()->hide();
    
    //sprintf(line, "%s/%s", STORE_DIR, filename);
    strcpy(line,filename);
    logfp = fopen(line, "r");
    if (logfp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", line);
        return false;
    }
    LOG_PRINT(info_e, "opened '%s'\n", line);
    
    int rownb = 0;
    int colfilternb = 0;
    int colnb = 0;
    while (rownb < LINE_BUFFER_SIZE && fgets(line, LINE_SIZE, logfp) != NULL)
    {
        LOG_PRINT(info_e, "LINE %s\n", line);
        ui->tableWidget->insertRow(rownb);
        colnb = 0;
        colfilternb = 0;
        
        p = line;
        while (p != NULL)
        {
            /* tag */
            p = mystrtok(p, token, SEPARATOR);
            if (p == NULL && token[0] == '\0')
            {
                LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
                continue;
            }
            
            if (actual_filter[colfilternb] == 1)
            {
                item = new QTableWidgetItem(token);
                if (rownb == 0)
                {
                    ui->tableWidget->setHorizontalHeaderItem(colnb, item);
                }
                else
                {
                    ui->tableWidget->setItem(rownb - 1,colnb,item);
                }
                
                LOG_PRINT(info_e, "showing tag %d '%s' actual_filter[%d] = %d\n", colnb, token, colfilternb, actual_filter[colfilternb]);
                colnb++;
            }
            else
            {
                LOG_PRINT(info_e, "filtererd tag %d '%s' actual_filter[%d] = %d\n", colnb, token, colfilternb, actual_filter[colfilternb]);
            }
            colfilternb++;
        }
        if (colnb > 0)
        {
            LOG_PRINT(verbose_e, "ROW %d\n", rownb);
            rownb++;
        }
    }
    if (feof(logfp))
    {
        fclose(logfp);
        logfp = NULL;
    }
    
    for (int i = ui->tableWidget->rowCount() - 1; i >= rownb - 1; i--)
    {
        ui->tableWidget->removeRow(i);
    }
    
    for (int i = ui->tableWidget->columnCount() - 1; i >= colnb; i--)
    {
        ui->tableWidget->removeColumn(i);
    }
    
    if (rownb <= 0)
    {
        ui->labelName->setText(QString("invalid format"));
    }
    if (rownb > 0 && colnb > 2)
    {
        ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
        LOG_PRINT(info_e, "DONE ROW %d COLUMN %d\n", rownb, colnb);
        return true;
    }
    else
    {
        LOG_PRINT(error_e, "EMPTY FILE ROW %d COLUMN %d\n", rownb, colnb);
        return false;
    }
}

bool store::readLine()
{
    char line[LINE_SIZE] = "";
    char token[LINE_SIZE] = "";
    char * p;
    QTableWidgetItem * item;
    
    if (logfp == NULL)
    {
        return false;
    }
    
    if (fgets(line, LINE_SIZE, logfp) != NULL)
    {
        LOG_PRINT(verbose_e, "LINE %s\n", line);
        int colnb = 0;
        int colfilternb = 0;
        
        p = line;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        while (p != NULL)
        {
            /* tag */
            p = mystrtok(p, token, SEPARATOR);
            if (p == NULL && token[0] == '\0')
            {
                LOG_PRINT(verbose_e, "Invalid tag '%s'\n", line);
                continue;
            }
            
            if (actual_filter[colfilternb] == 1)
            {
                item = new QTableWidgetItem(token);
                ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,colnb,item);
                
                LOG_PRINT(verbose_e, "showing tag %d '%s' actual_filter[%d] = %d\n", colnb, token, colfilternb, actual_filter[colfilternb]);
                colnb++;
            }
            else
            {
                LOG_PRINT(verbose_e, "filtererd tag %d '%s' actual_filter[%d] = %d\n", colnb, token, colfilternb, actual_filter[colfilternb]);
            }
            colfilternb++;
        }
        LOG_PRINT(verbose_e, "ROW %d\n", ui->tableWidget->rowCount() - 1);
        //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        return true;
    }
    else
    {
        fclose(logfp);
        logfp = NULL;
        return false;
    }
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void store::updateData()
{
    if (force_back == true)
    {
        go_back();
        return;
    }
    if (abs(ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, 0)).x()) + ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).x() + ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).width() < ui->tableWidget->width())
    {
        ui->pushButtonLeft->setEnabled(false);
        ui->pushButtonRight->setEnabled(false);
    }
    ui->pushButtonSaveUSB->setEnabled(USBCheck());
    
    page::updateData();
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void store::changeEvent(QEvent * event)
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
store::~store()
{
    delete ui;
}

void store::on_pushButtonHome_clicked()
{
    go_home();
}

void store::on_pushButtonBack_clicked()
{
    go_back();
}

void store::on_pushButtonUp_clicked()
{
    LOG_PRINT(info_e, "current_row %d\n", current_row);
    if (current_row > 0)
    {
        /* if we are at the last one correct the index */
        current_row=((current_row == ui->tableWidget->rowCount() - 1) ? current_row - 1 : current_row);
        /* decrement */
        current_row-=1;
        /* if we are the first one, reset the decrement */
        current_row = (current_row < 0) ? 0 : current_row;
        /* go to actual item */
        ui->tableWidget->scrollToItem(ui->tableWidget->item(current_row,current_column),QAbstractItemView::PositionAtTop);
        LOG_PRINT(info_e, "UP current_row %d\n", current_row);
    }
    if (current_row > 0)
    {
        ui->pushButtonDown->setEnabled(true);
    }
    else
    {
        ui->pushButtonUp->setEnabled(false);
    }
}

void store::on_pushButtonDown_clicked()
{
    LOG_PRINT(info_e, "current_row %d rowCount %d logfp %p\n", current_row, ui->tableWidget->rowCount(), logfp);
    
    if (current_row >= ui->tableWidget->rowCount() - 2 && logfp != NULL)
    {
        LOG_PRINT(info_e, "Reading a new line current_row %d rowCount %d\n", current_row, ui->tableWidget->rowCount());
        readLine();
    }
    
    if (current_row < ui->tableWidget->rowCount() - 1)
    {
        /* if we are at the first one correct the index */
        current_row=((current_row == 0) ? current_row + 1 : current_row);
        /* increment */
        current_row+=1;
        /* if we are the last one, reset the decrement */
        current_row=((current_row > ui->tableWidget->rowCount() - 1) ? ui->tableWidget->rowCount() - 1 : current_row);
        /* go to actual item */
        ui->tableWidget->scrollToItem(ui->tableWidget->item(current_row,current_column),QAbstractItemView::PositionAtTop);
        LOG_PRINT(info_e, "DOWN current_row %d\n", current_row);
    }
    if (current_row < ui->tableWidget->rowCount() - 1)
    {
        ui->pushButtonUp->setEnabled(true);
    }
    else
    {
        ui->pushButtonDown->setEnabled(false);
    }
}

void store::on_pushButtonLeft_clicked()
{
    QRect lastview;
    do
    {
        if (current_column > 0)
        {
            /* if we are at the last one correct the index */
            current_column=((current_column == ui->tableWidget->columnCount() - 1) ? current_column - 1 : current_column);
            /* decrement */
            current_column-=1;
            lastview = ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,current_column));
            /* if we are the first one, reset the decrement */
            current_column = (current_column < 0) ? 0 : current_column;
            /* go to actual item */
            ui->tableWidget->scrollToItem(ui->tableWidget->item(current_row,current_column),QAbstractItemView::PositionAtCenter);
            LOG_PRINT(info_e, "LEFT current_column %d\n", current_column);
        }
    } while(
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,current_column)).x() == lastview.x() &&
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).x() + ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).width() > ui->tableWidget->width());
    
    if (ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,0)).x() < 0)
    {
        ui->pushButtonLeft->setEnabled(true);
    }
    else
    {
        ui->pushButtonLeft->setEnabled(false);
    }
    if (
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,ui->tableWidget->columnCount() - 1)).x() +
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,ui->tableWidget->columnCount() - 1)).width() - ui->tableWidget->width() > 0
            )
    {
        ui->pushButtonRight->setEnabled(true);
    }
    else
    {
        ui->pushButtonRight->setEnabled(false);
    }
}

void store::on_pushButtonRight_clicked()
{
    LOG_PRINT(info_e, "current_column %d columnCount %d\n", current_column, ui->tableWidget->columnCount());
    QRect lastview;
    do
    {
        if (current_column <= ui->tableWidget->columnCount() - 1)
        {
            /* increment */
            current_column+=1;
            lastview = ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,current_column));
            /* if we are the last one, reset the decrement */
            current_column=((current_column > ui->tableWidget->columnCount()) ? ui->tableWidget->columnCount() : current_column);
            /* go to actual item */
            ui->tableWidget->scrollToItem(ui->tableWidget->item(current_row,current_column),QAbstractItemView::PositionAtCenter);
            LOG_PRINT(info_e, "RIGHT current_column %d\n", current_column);
        }
    } while(
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,current_column)).x() == lastview.x() &&
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).x() + ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row, ui->tableWidget->columnCount() - 1)).width() > ui->tableWidget->width());
    
    if (ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,0)).x() < 0)
    {
        ui->pushButtonLeft->setEnabled(true);
    }
    else
    {
        ui->pushButtonLeft->setEnabled(false);
    }
    if (
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,ui->tableWidget->columnCount() - 1)).x() +
            ui->tableWidget->visualItemRect(ui->tableWidget->item(current_row,ui->tableWidget->columnCount() - 1)).width() - ui->tableWidget->width() > 0
            )
    {
        ui->pushButtonRight->setEnabled(true);
    }
    else
    {
        ui->pushButtonRight->setEnabled(false);
    }
}

#if 0
void store::on_pushButtonPrevious_clicked()
{
    if (_file_nb == 0) return;
    
    LOG_PRINT(info_e, "_current %d\n", _current);
    if (_current == 0)
    {
        _current = _file_nb - 1;
    }
    else
    {
        _current--;
    }
    ui->comboBoxDate->setCurrentIndex(_current);
}

void store::on_pushButtonNext_clicked()
{
    if (_file_nb == 0) return;
    LOG_PRINT(info_e, "_current %d\n", _current);
    if (_current == _file_nb - 1)
    {
        _current = 0;
    }
    else
    {
        _current++;
    }
    ui->comboBoxDate->setCurrentIndex(_current);
}
#endif

void store::on_pushButtonSaveUSB_clicked()
{
    /* Check USB key */
    if (USBCheck())
    {
        if (USBmount() == false)
        {
            LOG_PRINT(error_e, "Cannot mount the usb key\n");
            QMessageBox::critical(this,tr("USB error"), tr("Cannot mount the usb key"));
            return;
        }
        
        char srcfilename[FILENAME_MAX];
        char dstfilename[FILENAME_MAX];
        /* compose the source file name ans the destination file name */
        sprintf(srcfilename, "%s/%s", TMPDIR, outputfile);
        sprintf(dstfilename, "%s/%s_%s.zip",
                usb_mnt_point,
                QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss").toAscii().data(),
                outputfile);
        
        /* zip the file, the sign file and delete them */
        if (zipAndSave(QStringList() << srcfilename << QString("%1.sign").arg(srcfilename), QString(dstfilename), true) == false)
        {
            QMessageBox::critical(this,tr("USB error"), tr("Cannot create the signature '%1.sign'").arg(srcfilename));
            USBumount();
            return;
        }
        
        QFile::remove(srcfilename);
        QFile::remove(QString("%1.sign").arg(srcfilename));
        
        /* unmount USB key */
        USBumount();
        LOG_PRINT(info_e, "DOWNLOADED\n");
        QMessageBox::information(this,tr("USB info"), tr("File '%1' saved.").arg(dstfilename));
    }
}

void store::on_pushButtonFilter_clicked()
{
    goto_page("store_filter");
}


