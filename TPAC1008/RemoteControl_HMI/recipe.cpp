/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#include <QTableWidget>
#include <QFileInfo>

#include "main.h"
#include "app_logprint.h"
#include "recipe.h"
#include "ui_recipe.h"

#define RETRY_NB 4
#define WAIT_CYCLES   6000 //we wait 10 minute = 60 sec = 60000 ms --> 600 loop @ 100ms

enum columns_e
{
    tag_column_e,
    value_column_e,
#ifdef MIN_MAX
    min_column_e,
    max_column_e,
#endif
    column_nb
};

/* this define set the variables list to be to displayed in this page */
#undef VAR_TO_DISPLAY
/* Example:
#define VAR_TO_DISPLAY "RET_REG_1" << "RET_REG_3" << "NRE_REG_1"
*/
/* this define set the window title */
#define WINDOW_TITLE "RECIPE"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ":/systemicons/img/Script.png"

/**
 * @brief this macro is used to set the RECIPE style.
 * the syntax is html stylesheet-like
 */
#define SET_RECIPE_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
recipe::recipe(QWidget *parent) :
    page(parent),
    ui(new Ui::recipe)
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
    //SET_RECIPE_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void recipe::reload()
{
    reading = false;
    force_back = false;
    writing = false;
    writing_first = false;
    writing_continue = false;
    clean = false;
    
    ui->labelStatus->setText(tr(""));
    ui->labelStatus->repaint();
    ui->progressBarStatus->setVisible(false);
    ui->progressBarStatus->setMaximum(ui->tableWidget->rowCount());
    ui->progressBarStatus->setMinimum(0);
    
    /* load the actual receipt  */
    if (strlen(_actual_recipe_) == 0)
    {
        QMessageBox::critical(this,tr("Empty recipe name"), tr("No recipe is selected."));
        force_back = true;
    }
    else if (LoadRecipe(_actual_recipe_) == false)
    {
        QMessageBox::critical(this,tr("Malformed recipe"), tr("The recipe '%1' is malformed.").arg(_actual_recipe_));
        force_back = true;
    }
}

bool recipe::LoadRecipe(const char * filename)
{
    FILE * fp;
    char line[LINE_SIZE] = "";
    char token[LINE_SIZE] = "";
    char tokenNormalized[LINE_SIZE] = "";
    char * p;
    QTableWidgetItem * item;
    
    ui->tableWidget->clear();
    
    /* column tag */
    ui->tableWidget->insertColumn(tag_column_e);
    /* column value */
    ui->tableWidget->insertColumn(value_column_e);
#ifdef MIN_MAX
    /* column min */
    ui->tableWidget->insertColumn(min_column_e);
    /* column max */
    ui->tableWidget->insertColumn(max_column_e);
#endif
    ui->tableWidget->verticalHeader()->hide();
    
    ui->tableWidget->setHorizontalHeaderItem(tag_column_e, new QTableWidgetItem("Tag"));
    ui->tableWidget->setHorizontalHeaderItem(value_column_e, new QTableWidgetItem("Value"));
#ifdef MIN_MAX
    ui->tableWidget->setHorizontalHeaderItem(min_column_e, new QTableWidgetItem("Min"));
    ui->tableWidget->setHorizontalHeaderItem(max_column_e, new QTableWidgetItem("Max"));
#endif
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", filename);
        ui->labelName->setText("NONE");
        return false;
    }
    LOG_PRINT(info_e, "opened '%s'\n", line);
    /*
     * the file is formatted as
     * <Tag>;<value>;<min>;<max>
     */
    int rownb = 0;
    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        p = line;
        /* tag */
        p = mystrtok(p, token, SEPARATOR);
        if (p == NULL || token[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        ui->tableWidget->insertRow(rownb);
        
        item = new QTableWidgetItem(token);
        ui->tableWidget->setItem(rownb,tag_column_e,item);
        
        int decimal = getVarDecimalByName(token);
        
        LOG_PRINT(info_e, "tag '%s'\n", token);
        
        /* value */
        token[0] = '\0';
        p = mystrtok(p, token, SEPARATOR);
        if (token[0] != '\0')
        {
            /*Check for the number of decimals to be used for that particular token*/
            float val_f = atof(token);
            sprintf(tokenNormalized, "%.*f",decimal,val_f );
            item = new QTableWidgetItem(tokenNormalized);
            ui->tableWidget->setItem(rownb,value_column_e,item);
            LOG_PRINT(info_e, "value '%s'\n", tokenNormalized);
        }
#ifdef MIN_MAX
        /* min */
        token[0] = '\0';
        p = mystrtok(p, token, SEPARATOR);
        if (token[0] != '\0')
        {
            item = new QTableWidgetItem(token);
            ui->tableWidget->setItem(rownb,min_column_e,item);
            LOG_PRINT(info_e, "min '%s'\n", token);
        }
        /* max */
        token[0] = '\0';
        p = mystrtok(p, token, SEPARATOR);
        if (token[0] != '\0')
        {
            item = new QTableWidgetItem(token);
            ui->tableWidget->setItem(rownb,max_column_e,item);
            LOG_PRINT(info_e, "max '%s'\n", token);
        }
#endif
        rownb++;
    }
    fclose(fp);
    
    for (int i = ui->tableWidget->rowCount() - 1; i >= rownb; i--)
    {
        ui->tableWidget->removeRow(i);
    }
    
    for (int i = ui->tableWidget->columnCount() - 1; i >= column_nb; i--)
    {
        ui->tableWidget->removeColumn(i);
    }
#if 0
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget->resizeColumnToContents(0);
#endif
    
#ifdef MIN_MAX
    ui->tableWidget->setColumnWidth(tag_column_e,200);
    ui->tableWidget->setColumnWidth(value_column_e,66);
    ui->tableWidget->setColumnWidth(min_column_e,66);
    ui->tableWidget->setColumnWidth(max_column_e,66);
#else
    ui->tableWidget->setColumnWidth(tag_column_e,200);
    //ui->tableWidget->setColumnWidth(value_column_e,80);
#endif
    
    if (rownb > 0)
    {
        ui->labelName->setText(filename);
    }
    else
    {
        ui->labelName->setText(QString("invalid format for '%1'").arg(filename));
    }
    
    return (rownb > 0);
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void recipe::updateData()
{
    static int retry_nb = 0;
    static bool busy = false;
    static int j = 0;
    LOG_PRINT(info_e, "busy %d clean %d writing %d reading %d\n", busy, clean, writing, reading);
    
    if(busy)
    {
        return;
    }
    
    if(writing == false && clean == true)
    {
        cleanRecipeWriting();
        j=0;
        ui->pushButtonEdit->setEnabled(true);
        ui->pushButtonLoad->setEnabled(true);
        ui->pushButtonRead->setEnabled(true);
        ui->pushButtonSave->setEnabled(true);
        ui->labelStatus->setText(tr(""));
        ui->labelStatus->repaint();
        ui->progressBarStatus->setVisible(false);
        ui->progressBarStatus->setValue(1);
        busy = false;
        clean = false;
        if(back == true)
        {
            go_back();
        }
        else
        {
            go_home();
        }
        return;
    }
    
    if ( force_back )
    {
        go_back();
        return;
    }
    page::updateData();
    LOG_PRINT(info_e, "Update data flags: reading %d  first %d writing %d continue %d \n", reading, writing_first, writing, writing_continue);
    
    if (reading)
    {
        QString value;
        readcounter = 0;
        LOG_PRINT(info_e, "Reading '%d' variables\n", ui->tableWidget->rowCount());
        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            if (ui->tableWidget->item(i,tag_column_e) != NULL)
            {
                char msg[TAG_LEN];
                getFormattedVar(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data(), &value, NULL);
                switch (getStatusVar(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data(), msg))
                {
                case BUSY:
                    //retry_nb = 0;
                    LOG_PRINT(info_e, "BUSY: %s\n", msg);
                    if (msg[0] == '\0')
                    {
                        strcpy(msg, VAR_PROGRESS);
                    }
                    break;
                case ERROR:
                    LOG_PRINT(info_e, "ERROR: %s\n", msg);
                    if (msg[0] == '\0')
                    {
                        strcpy(msg, VAR_COMMUNICATION);
                    }
                    break;
                case DONE:
                    strcpy(msg, value.toAscii().data());
                    LOG_PRINT(info_e, "DONE %s\n", msg);
                    readcounter++;
                    break;
                default:
                    LOG_PRINT(info_e, "OTHER: %s\n", msg);
                    if (msg[0] == '\0')
                    {
                        strcpy(msg, VAR_UNKNOWN);
                    }
                    break;
                }
                if (msg[0] != '\0')
                {
                    ui->tableWidget->item(i,value_column_e)->setText(msg);
                    LOG_PRINT(info_e, "Reading %d - '%s'\n", i, ui->tableWidget->item(i,tag_column_e)->text().toAscii().data());
                }
            }
            else
            {
                LOG_PRINT(error_e, "cannot read %d variable\n", i);
            }
        }
        retry_nb++;
        if (retry_nb > RETRY_NB || readcounter == ui->tableWidget->rowCount())
        {
            retry_nb = 0;
            reading = false;
            ui->pushButtonEdit->setEnabled(true);
            ui->pushButtonLoad->setEnabled(true);
            ui->pushButtonRead->setEnabled(true);
            ui->pushButtonSave->setEnabled(true);
            ui->labelStatus->setText("");
        }
    }
    if(writing)
    {
        int static wait_cycle_nb = 0;
        
        refresh_timer->start(70);
        ui->progressBarStatus->setVisible(true);
        ui->progressBarStatus->setMaximum(ui->tableWidget->rowCount());
        if( j < ui->tableWidget->rowCount() )
        {
            
            if ( (ui->tableWidget->item(j,tag_column_e)->text().toAscii().data()) != NULL &&
                 (ui->tableWidget->item(j,value_column_e)->text().toAscii().data()) != NULL )
            {
                LOG_PRINT(info_e, "Processing  j (%d) '%s' '%s'\n",j,
                          ui->tableWidget->item(j,tag_column_e)->text().toAscii().data(),
                          ui->tableWidget->item(j,value_column_e)->text().toAscii().data());
                char msg[TAG_LEN];
                int Status = getStatusVar(ui->tableWidget->item(j,tag_column_e)->text().toAscii().data(), msg);
                if (Status == DONE)
                {
                    LOG_PRINT(info_e, "DONE %s\n", msg);
                    /*Go on with recipe writing*/
                    ui->progressBarStatus->setValue(j);
                    j++;
                    wait_cycle_nb = 0;
                }
                else if (Status == BUSY && wait_cycle_nb < WAIT_CYCLES)
                {
                    LOG_PRINT(info_e, "BUSY: %s going to retry\n", msg);
                    wait_cycle_nb++;
                }
                else // we are BUSY with max WAIT_CYCLES or ERROR
                {
                    busy = true;
                    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, tr("Recipe Error"), tr("Error in writing Recipe Variable %1 .Continue writing Recipe anyway? ").arg(ui->tableWidget->item(j,tag_column_e)->text().toAscii().data()),
                                                        QMessageBox::Yes|QMessageBox::No).exec())
                    {
                        //if we want to go on
                        wait_cycle_nb = 0;
                        ui->progressBarStatus->setValue(j);
                        j++;
                        LOG_PRINT(info_e, "GOING ON: processing'%d' \n", j);
                        busy = false;
                    }
                    else
                    {
                        //if we want to stop with recipe write
                        LOG_PRINT(info_e, "STOPPING\n");
                        QMessageBox::critical(this,tr("Recipe Error"), tr("Recipe writing Aborted due to previous errors"));
                        writing=false;
                        ui->pushButtonEdit->setEnabled(true);
                        ui->pushButtonLoad->setEnabled(true);
                        ui->pushButtonRead->setEnabled(true);
                        ui->pushButtonSave->setEnabled(true);
                        ui->labelStatus->setText(tr(""));
                        ui->labelStatus->repaint();
                        ui->progressBarStatus->setVisible(false);
                        ui->progressBarStatus->setValue(1);
                        j =0;
                        busy = false;
                        refresh_timer->start(REFRESH_MS);
                        return;
                    }
                }
            }
            else
            {
                LOG_PRINT(info_e, "cannot read %d variable\n", j);
                QMessageBox::critical(this,tr("Recipe Error"), tr("Recipe writing Aborted due to previous errors"));
                writing=false;
                /*prepare everything to exit recipe writing process*/
                ui->pushButtonEdit->setEnabled(true);
                ui->pushButtonLoad->setEnabled(true);
                ui->pushButtonRead->setEnabled(true);
                ui->pushButtonSave->setEnabled(true);
                ui->labelStatus->setText(tr(""));
                ui->labelStatus->repaint();
                ui->progressBarStatus->setVisible(false);
                ui->progressBarStatus->setValue(1);
                j =0;
                refresh_timer->start(REFRESH_MS);
                return;
            }
            
        }
        if (j == ( ui->tableWidget->rowCount()))
        {
            
            writing = false;
            j = 0;
            ui->progressBarStatus->setValue(ui->tableWidget->rowCount());
            QMessageBox::information(this,tr("Recipe"), tr("Recipe writing Successfully Completed"));
            ui->pushButtonEdit->setEnabled(true);
            ui->pushButtonLoad->setEnabled(true);
            ui->pushButtonRead->setEnabled(true);
            ui->pushButtonSave->setEnabled(true);
            ui->labelStatus->setText(tr(""));
            ui->labelStatus->repaint();
            ui->progressBarStatus->setVisible(false);
            ui->progressBarStatus->setValue(1);
            refresh_timer->start(REFRESH_MS);
            return;
        }
        
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
recipe::~recipe()
{
    delete ui;
}

void recipe::on_pushButtonHome_clicked()
{
    if(writing)
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, tr("Recipe"), tr("You pressed the Home button.Ignore and continue writing Recipe? "),
                                            QMessageBox::Yes|QMessageBox::No).exec())
        {
            clean= false;
            return;
        }
        else
        {
            
            writing = false;
            clean = true;
            back = false;
        }
    }
    else
    {
        go_home();
    }
}

void recipe::on_pushButtonBack_clicked()
{
    if(writing)
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, tr("Recipe"), tr("You pressed the Back button.Ignore and continue writing Recipe? "),
                                            QMessageBox::Yes|QMessageBox::No).exec())
        {
            clean= false;
            return;
        }
        else
        {
            
            writing = false;
            clean = true;
            back = true;
            LOG_PRINT(info_e, "writing %d clean %d\n", writing, clean);
            
        }
    }
    else
    {
        go_back();
    }
}

void recipe::on_pushButtonEdit_clicked()
{
    if (ui->tableWidget->selectedItems().count() == 0)
    {
        LOG_PRINT(info_e, "No item selected\n");
        return;
    }
    /* Edit the selected item */
    float value, min = 0, max = 0;
#ifdef MIN_MAX
    if (ui->tableWidget->item(ui->tableWidget->currentRow(), min_column_e))
    {
        min = ui->tableWidget->item(ui->tableWidget->currentRow(), min_column_e)->text().toFloat();
    }
    if (ui->tableWidget->item(ui->tableWidget->currentRow(), max_column_e))
    {
        max = ui->tableWidget->item(ui->tableWidget->currentRow(), max_column_e)->text().toFloat();
    }
    LOG_PRINT(info_e, "min %f max %f\n", min, max);
#endif
    numpad * dk;
    dk = new numpad(&value, ui->tableWidget->item(ui->tableWidget->currentRow(), value_column_e)->text().toFloat(), min, max);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (min < max && (value < min || value > max))
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(value).arg(min).arg(max));
            delete dk;
            return;
        }
        char token[LINE_SIZE]="";
        int decimal = getVarDecimalByName(ui->tableWidget->item(ui->tableWidget->currentRow(),tag_column_e)->text().toAscii().data());
        sprintf(token, "%.*f",decimal,value);
        ui->tableWidget->item(ui->tableWidget->currentRow(), value_column_e)->setText(token);
    }
    else
    {
    }
    delete dk;
}

void recipe::on_pushButtonRead_clicked()
{
    ui->pushButtonEdit->setEnabled(false);
    ui->pushButtonLoad->setEnabled(false);
    ui->pushButtonRead->setEnabled(false);
    ui->pushButtonSave->setEnabled(false);
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        if (ui->tableWidget->item(i,tag_column_e) != NULL)
        {
            if (activateVar(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data()) != 0)
            {
                LOG_PRINT(error_e, "cannot activate the variable '%s'\n", ui->tableWidget->item(i,tag_column_e)->text().toAscii().data());
                QMessageBox::critical(this,tr("Invalid data"), tr("The variable (%1) doesn't exist.").arg(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data()));
                ui->pushButtonEdit->setEnabled(true);
                ui->pushButtonLoad->setEnabled(true);
                ui->pushButtonRead->setEnabled(true);
                ui->pushButtonSave->setEnabled(true);
                return;
            }
        }
    }
    reading = true;
    ui->labelStatus->setText(tr("Reading..."));
    ui->labelStatus->repaint();
}

void recipe::on_pushButtonLoad_clicked()
{
    char counter = 0;
    char ret = 0;
    ui->pushButtonEdit->setEnabled(false);
    ui->pushButtonLoad->setEnabled(false);
    ui->pushButtonRead->setEnabled(false);
    ui->pushButtonSave->setEnabled(false);
    ui->pushButtonHome->setEnabled(false);
    ui->pushButtonBack->setEnabled(false);
    ui->labelStatus->setText(tr("Preparing..."));
    ui->labelStatus->setStyleSheet("color: rgb(255,0,0);");
    ui->labelStatus->repaint();
    
    
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        if (ui->tableWidget->item(i,tag_column_e) == NULL)
        {
            QMessageBox::critical(this,tr("Malformed recipe"), tr("The recipe '%1' is malformed.").arg(ui->labelName->text().toAscii().data()));
            ui->pushButtonEdit->setEnabled(true);
            ui->pushButtonLoad->setEnabled(true);
            ui->pushButtonRead->setEnabled(true);
            ui->pushButtonSave->setEnabled(true);
            return;
        }
        if (ui->tableWidget->item(i,value_column_e) == NULL)
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The variable (%1) have an unexpected value.").arg(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data()));
            ui->pushButtonEdit->setEnabled(true);
            ui->pushButtonLoad->setEnabled(true);
            ui->pushButtonRead->setEnabled(true);
            ui->pushButtonSave->setEnabled(true);
            return;
        }
        
        do
        {
            ret = prepareFormattedVar(ui->tableWidget->item(i,tag_column_e)->text().toAscii().data(), ui->tableWidget->item(i,value_column_e)->text().toAscii().data());
            usleep(IOLAYER_PERIOD_ms * 1000);
            counter++;
            if (ret == BUSY)
            {
                LOG_PRINT(warning_e, "busy, waiting to write the variable '%s' with the value '%s'\n", ui->tableWidget->item(i, tag_column_e)->text().toAscii().data(), ui->tableWidget->item(i,value_column_e)->text().toAscii().data());
            }
        } while ( ret == BUSY && counter < RETRY_NB);
        
        if (ret == ERROR)
        {
            LOG_PRINT(error_e, "cannot write the variable '%s' with the value '%s'\n", ui->tableWidget->item(i, tag_column_e)->text().toAscii().data(), ui->tableWidget->item(i,value_column_e)->text().toAscii().data());
        }
        else if (ret == DONE)
        {
            LOG_PRINT(info_e, "write the variable '%s' with the value '%s'\n", ui->tableWidget->item(i, tag_column_e)->text().toAscii().data(), ui->tableWidget->item(i,value_column_e)->text().toAscii().data());
        }
        else
        {
            LOG_PRINT(warning_e, "busy, waiting to write the variable '%s' with the value '%s'\n", ui->tableWidget->item(i, tag_column_e)->text().toAscii().data(), ui->tableWidget->item(i,value_column_e)->text().toAscii().data());
        }
    }
    writePendingInorder();
    usleep(500000);
    ui->labelStatus->setText(tr("Downloading..."));
    ui->labelStatus->setStyleSheet("color: rgb(255,0,0);");
    ui->labelStatus->repaint();
    ui->progressBarStatus->setVisible(true);
    ui->progressBarStatus->setValue(1);
    ui->pushButtonHome->setEnabled(true);
    ui->pushButtonBack->setEnabled(true);
    writing = true;
}

void recipe::on_pushButtonSave_clicked()
{
    /* Edit the selected item */
    char fullfilename[FILENAME_MAX];
    FILE * fp;
    char value[DESCR_LEN];
    alphanumpad * dk;
    dk = new alphanumpad(value, QFileInfo(_actual_recipe_).baseName().toAscii().data());
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted && strlen(value) != 0)
    {
        LOG_PRINT(info_e, "Saving to '%s'\n", value);
        sprintf(fullfilename, "%s/%s.csv", QFileInfo(_actual_recipe_).absolutePath().toAscii().data(), value);
        fp = fopen(fullfilename, "w");
        if (fp == NULL)
        {
            LOG_PRINT(error_e, "Cannot open '%s'\n", fullfilename);
        }
        else
        {
            LOG_PRINT(error_e, "opened '%s'\n", fullfilename);
            for (int i = 0; i < ui->tableWidget->rowCount(); i++)
            {
                if (ui->tableWidget->item(i,tag_column_e) != NULL)
                {
#ifdef MIN_MAX
                    fprintf(fp, "%s;%s;%s;%s\n",
                            ui->tableWidget->item(i,tag_column_e)->text().toAscii().data(),
                            (ui->tableWidget->item(i,value_column_e) != NULL) ? ui->tableWidget->item(i,value_column_e)->text().toAscii().data() : "",
                            (ui->tableWidget->item(i,min_column_e) != NULL) ? ui->tableWidget->item(i,min_column_e)->text().toAscii().data() : "",
                            (ui->tableWidget->item(i,max_column_e) != NULL) ? ui->tableWidget->item(i,max_column_e)->text().toAscii().data() : ""
                                                                              );
#else
                    fprintf(fp, "%s;%s\n",
                            ui->tableWidget->item(i,tag_column_e)->text().toAscii().data(),
                            (ui->tableWidget->item(i,value_column_e) != NULL) ? ui->tableWidget->item(i,value_column_e)->text().toAscii().data() : ""
                                                                                );
#endif
                }
            }
            fclose(fp);
            LOG_PRINT(error_e, "Saved '%s'\n", fullfilename);
            ui->labelName->setText(fullfilename);
        }
    }
    else
    {
    }
    delete dk;
}

