/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Generic page
 */
#include <QDir>
#include <QFileInfo>
#include "main.h"
#include "alphanumpad.h"
#include "app_logprint.h"
#include "item_selector.h"
#include "trend_option.h"
#include "ui_trend_option.h"

#define DEFAULT_YMIN -1000
#define DEFAULT_YMAX  1000

/* this define set the window title */
#define WINDOW_TITLE "TREND MANAGER"
/* this define set the window icon the file can have a path into resource file or into the file system */
#define WINDOW_ICON ""

/**
 * @brief this macro is used to set the TREND_OPTION style.
 * the syntax is html stylesheet-like
 */
#define SET_TREND_OPTION_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instanziation of the page.
 */
trend_option::trend_option(QWidget *parent) :
    page(parent),
    ui(new Ui::trend_option)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_super_admin_e,pwd_admin_e, pwd_service_e, pwd_operator_e), default is pwd_operator_e
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
    SET_TREND_OPTION_STYLE();
    
    /* connect the label that show the date and the time to the timer of the parent updateData */
    labelDataOra = ui->labelDataOra;
    /* connect the label that show the user name */
    //labelUserName = ui->labelUserName;
    
    QPalette pal = ui->comboBoxColor->palette(); // or comboBox->view()
    pal.setColor(QPalette::Highlight, Qt::transparent); // or partly transparent
    ui->comboBoxColor->setPalette(pal); // or comboBox->view()
    
    curve_palette << "FF0000" << "00FF00" << "0000FF" << "000000";
    
    //reload();
}

#undef WINDOW_TITLE
#undef WINDOW_ICON

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void trend_option::reload()
{
    ui->labelInfo->setText("");
    ui->labelInfo->repaint();
    if (_layout_ == PORTRAIT)
    {
        ui->pushButtonLayout->setText(tr("Portrait"));
    }
    else
    {
        ui->pushButtonLayout->setText(tr("Landscape"));
    }
    
    ui->labelTrendName->setText(_actual_trend_);
    ui->labelPenName->setText(pens[actualPen].tag);
    ui->checkBoxVisible->setChecked(pens[actualPen].visible == 1);
    
    if (strlen(pens[actualPen].description) == 0)
    {
        ui->pushButtonDescription->setText("-");
    }
    else
    {
        ui->pushButtonDescription->setText(pens[actualPen].description);
    }
    
    int decimal =  getVarDecimalByName(pens[actualPen].tag);
    ui->pushButtonYmin->setText(QString().setNum(pens[actualPen].yMin,'f',decimal));
    ui->pushButtonYmax->setText(QString().setNum(pens[actualPen].yMax,'f',decimal));
    
    QPixmap pixmap(25, 25);
    
    ui->comboBoxColor->clear();
    ui->comboBoxColor->addItem("");
    for (int i = 0; i < curve_palette.count(); i++)
    {
        ui->comboBoxColor->addItem("");
        pixmap.fill(QColor(QString("#%1").arg(curve_palette.at(i))));
        ui->comboBoxColor->setItemData(i + 1, pixmap, Qt::DecorationRole);
    }
    ui->comboBoxColor->addItem("");
    pixmap.fill(QColor(QString("#%1").arg(pens[actualPen].color)));
    ui->comboBoxColor->setItemData(curve_palette.count(), pixmap, Qt::DecorationRole);
    
    ui->comboBoxColor->setCurrentIndex(curve_palette.count());
    color[0] = '\0';
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void trend_option::updateData()
{
    page::updateData();
    ui->pushButtonSaveUSB->setEnabled(USBCheck());
}

#ifdef TRANSLATION
/**
 * @brief This is the event slot to detect new language translation.
 */
void trend_option::changeEvent(QEvent * event)
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
trend_option::~trend_option()
{
    delete ui;
}

void trend_option::on_pushButtonHome_clicked()
{
    go_home();
}

void trend_option::on_pushButtonBack_clicked()
{
    ui->labelInfo->setText(tr("loading..."));
    ui->labelInfo->setStyleSheet("color: rgb(255,0,0);");
    ui->labelInfo->repaint();
    /* force a online */
    actualVisibleWindowSec = 0;
    go_back();
}

void trend_option::on_pushButtonLayout_clicked()
{
    if (_layout_ == PORTRAIT)
    {
        ui->pushButtonLayout->setText(tr("Landscape"));
        _layout_ = LANDSCAPE;
    }
    else
    {
        ui->pushButtonLayout->setText(tr("Portrait"));
        _layout_ = PORTRAIT;
    }
}

void trend_option::on_pushButtonChangeTrend_clicked()
{
    item_selector * sel;
    QString value;
    
    /* select a new trend */
    QStringList trendList;
    
    QDir trendDir(CUSTOM_TREND_DIR, "*.csv");
    
    if (trendDir.entryList(QDir::AllDirs|QDir::NoDotAndDotDot).count() != 0)
    {
        trendList = trendDir.entryList(QDir::AllDirs|QDir::NoDotAndDotDot);
    }
    else if (trendDir.entryList(QDir::Files).count() != 0)
    {
        trendList = trendDir.entryList(QDir::Files);
    }
    else
    {
        LOG_PRINT(error_e, "No trend to show\n");
        return;
    }
    
    sel = new item_selector(trendList, &value, tr("TREND SELECTOR"));
    sel->showFullScreen();
    
    if (sel->exec() == QDialog::Accepted)
    {
        strcpy(_actual_trend_, QFileInfo(value).baseName().toAscii().data());
        /* force a online */
        actualVisibleWindowSec = 0;
        goto_page("trend");
    }
    else
    {
    }
    delete sel;
}

void trend_option::on_pushButtonChangePen_clicked()
{
    /* select a new item */
    item_selector * sel;
    QString value;
    QStringList list;
    
    for ( int i = 0; StoreArrayS[i].tag[0] != '\0'; i++)
    {
        list.append(StoreArrayS[i].tag);
    }
    for ( int i = 0; StoreArrayF[i].tag[0] != '\0'; i++)
    {
        list.append(StoreArrayF[i].tag);
    }
    
    sel = new item_selector(list, &value,tr("VARIABLE SELECTOR"));
    sel->showFullScreen();
    
    if (sel->exec() == QDialog::Accepted)
    {
        strcpy(pens[actualPen].tag, value.toAscii().data());
        ui->labelPenName->setText(value);
    }
    else
    {
    }
    delete sel;
}

void trend_option::on_pushButtonDeletePen_clicked()
{
    pens[actualPen].visible = 0;
    pens[actualPen].tag[0] = '\0';
    pens[actualPen].description[0] = '\0';
    reload();
}

void trend_option::on_checkBoxVisible_clicked(bool checked)
{
    pens[actualPen].visible = checked;
}

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

void trend_option::on_pushButtonYmin_clicked()
{
    numpad * dk;
    float value;
    float min = MIN(DEFAULT_YMIN, pens[actualPen].yMax);
    float max = MIN(DEFAULT_YMAX, pens[actualPen].yMax);
    
    dk = new numpad(&value, ui->pushButtonYmin->text().toFloat(), min, max,false);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (value < min || value > max)
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(value).arg(min).arg(max));
            delete dk;
            return;
        }
        pens[actualPen].yMin = value;
        int decimal =  getVarDecimalByName(pens[actualPen].tag);
        ui->pushButtonYmin->setText(QString().setNum(pens[actualPen].yMin,'f',decimal));
    }
    else
    {
    }
    delete dk;
}

void trend_option::on_pushButtonYmax_clicked()
{
    numpad * dk;
    float value;
    float min = MAX(DEFAULT_YMIN, pens[actualPen].yMin);
    float max = MAX(DEFAULT_YMAX, pens[actualPen].yMin);
    
    dk = new numpad(&value, ui->pushButtonYmax->text().toFloat(), min, max,false);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted)
    {
        if (value < min || value > max)
        {
            QMessageBox::critical(this,tr("Invalid data"), tr("The inserted value (%1) is invalid.\nThe value must ranging between %2 and %3").arg(value).arg(min).arg(max));
            delete dk;
            return;
        }
        pens[actualPen].yMax = value;
        int decimal =  getVarDecimalByName(pens[actualPen].tag);
        ui->pushButtonYmax->setText(QString().setNum(pens[actualPen].yMax,'f',decimal));
    }
    else
    {
    }
    delete dk;
}

void trend_option::on_pushButtonDescription_clicked()
{
    char value[DESCR_LEN];
    alphanumpad * dk;
    
    dk = new alphanumpad(value);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted && strlen(value) != 0)
    {
        LOG_PRINT(info_e, "Saving to '%s'\n", value);
        strcpy(pens[actualPen].description, value);
        ui->pushButtonDescription->setText(pens[actualPen].description);
    }
    else
    {
    }
    delete dk;
}

void trend_option::on_pushButtonSaveAs_clicked()
{
    /* Edit the selected item */
    char fullfilename[FILENAME_MAX];
    char value[DESCR_LEN];
    alphanumpad * dk;
    
    dk = new alphanumpad(value);
    dk->showFullScreen();
    
    if (dk->exec() == QDialog::Accepted && strlen(value) != 0)
    {
        LOG_PRINT(info_e, "Saving to '%s'\n", value);
        sprintf(fullfilename, "%s/%s.csv", CUSTOM_TREND_DIR, value);
        Save(fullfilename);
        ui->labelTrendName->setText(value);
    }
    else
    {
    }
    delete dk;
}

void trend_option::on_pushButtonSave_clicked()
{
    char fullfilename[FILENAME_MAX];
    sprintf(fullfilename, "%s/%s.csv", CUSTOM_TREND_DIR, _actual_trend_);
    Save(fullfilename);
    ui->labelTrendName->setText(_actual_trend_);
}

void trend_option::Save(const char * fullfilename)
{
    FILE * fp = fopen(fullfilename, "w");
    if (fp == NULL)
    {
        LOG_PRINT(error_e, "Cannot open '%s'\n", fullfilename);
    }
    else
    {
        /*
         * the file is formatted as
         * <Layout>
         * <Visible>;<Tag1>;<color>;<Ymin>;<Ymax>;<description>
         * <Visible>;<Tag2>;<color>;<Ymin>;<Ymax>;<description>
         * <Visible>;<Tag3>;<color>;<Ymin>;<Ymax>;<description>
         * <Visible>;<Tag4>;<color>;<Ymin>;<Ymax>;<description>
         */
        
        fprintf(fp, "%c\n", _layout_);
        
        if (strlen(color) > 0)
        {
            strcpy(pens[actualPen].color, color);
        }
        
        LOG_PRINT(error_e, "opened '%s'\n", fullfilename);
        for (int i = 0; i < PEN_NB; i++)
        {
            fprintf(fp, "%d;%s;%s;%f;%f;%s\n",
                    pens[i].visible,
                    pens[i].tag,
                    pens[i].color,
                    pens[i].yMin,
                    pens[i].yMax,
                    pens[i].description
                    );
        }
        fclose(fp);
        LOG_PRINT(error_e, "Saved '%s'\n", fullfilename);
        QMessageBox::information(this,tr("Save"), tr("the trend configuration %1 is saved to %2").arg(_actual_trend_).arg(fullfilename));
    }
    /* force a reload */
    _trend_data_reload_ = true;
    LOG_PRINT(info_e, "_trend_data_reload_ %d\n",  _trend_data_reload_);
}

void trend_option::on_comboBoxColor_currentIndexChanged(int index)
{
    if (index < 0)
    {
        return;
    }
    if (index > 0)
    {
        strcpy(color, curve_palette.at(index - 1).toAscii().data());
    }
    else
    {
        strcpy(color, pens[index].color);
    }
    LOG_PRINT(info_e, "New color at index %d '%s'\n", index, color);
}

void trend_option::on_pushButtonSaveUSB_clicked()
{
    /* save the trend description and the trend's screenshoot */
    
    /* Check USB key */
    if (USBCheck())
    {
        if (USBmount() == false)
        {
            LOG_PRINT(error_e, "Cannot mount the usb key\n");
            QMessageBox::critical(this,tr("USB error"), tr("Cannot mount the usb key"));
            return;
        }
        
        char dstfilename [MAX_LINE] = "";
        
        /* compose the source file name ans the destination file name */
        sprintf(dstfilename, "%s/%s_%s",
                usb_mnt_point,
                QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss").toAscii().data(),
                _actual_trend_);
        
        LOG_PRINT(info_e, "Save %s'\n", dstfilename);
        
        QStringList sourcelist;
        if (QFile::exists(QString("%1/%2.csv").arg(CUSTOM_TREND_DIR).arg(_actual_trend_)))
        {
            sourcelist << QString("%1/%2.csv").arg(CUSTOM_TREND_DIR).arg(_actual_trend_);
        }
        if (QDir().exists(QString("%1/%2").arg(SCREENSHOT_DIR).arg(_actual_trend_)))
        {
            sourcelist << QString("%1/%2").arg(SCREENSHOT_DIR).arg(_actual_trend_);
        }
        if (sourcelist.count() == 0)
        {
            QMessageBox::critical(this,tr("No data"), tr("Nothing to save for trend %1").arg(_actual_trend_));
            USBumount();
            return;
        }
        
        /* zip the file, the sign file and delete them */
        if (zipAndSave(sourcelist,QString("%1.zip").arg(dstfilename)) == false)
        {
            QMessageBox::critical(this,tr("USB error"), tr("Cannot create the zip file '%1'").arg(QString("%1.zip").arg(dstfilename)));
            USBumount();
            return;
        }
        
        /* unmount USB key */
        USBumount();
        LOG_PRINT(info_e, "DOWNLOADED\n");
        QMessageBox::information(this,tr("USB info"), tr("File '%1' saved.").arg(dstfilename));
    }
}


