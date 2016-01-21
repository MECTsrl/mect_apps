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
#include "crosstable.h"
#include <QDir>

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
    recipeList.clear();
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page400::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       trend initialization:
         strncpy(_actual_trend_, "trend1.csv",FILENAME_MAX);
         _trend_data_reload_ = true;
       store initialization:
         strncpy(_actual_store_, "store1.csv",FILENAME_MAX);
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
    doWrite_DO_REMOTE(1);
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
    /* This code show how to connect
     * the cross table variable named "RET_REG_1" to the HMI label "label1val"
     * and if it is not NULL, set the Status led "led1" without using ATCM plugins
     *    WARNING: only MIRROR variable can be read or the variable listed
     *            into the active variable list variableList defined at the top of this file
     
     if (getFormattedVar("RET_REG_1", ui->label1val, ui->led1) == false)
     {
        LOG_PRINT(error_e, "cannot read variable '%s'","RET_REG_1" );
     }
     */
    /* This code show how to write a cross table variable named "NRE_REG_1"  without using ATCM plugins.
     * Usually this code is putted into a button slot.
     * The variable could be not present into the active variable list "variableList"
     if (writeVar("NRE_REG_1", &value) == true)
     {
         LOG_PRINT(info_e,"################### NRE_REG_1 %d\n", value);
     }
     */
    if (STATUS == 4) // DONE
    {
        ui->pushButtonNext->setEnabled(true);
        doWrite_DO_TEST(0);
        /* TODO: report */
        if ( ui->checkBoxAuto->isChecked() )
        {
            on_pushButtonNext_clicked();
        }
    }
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
void page400::on_atcmComboBox_PRODUCT_ID_currentIndexChanged(const QString &arg1)
{
    dirname = QString(RECIPE_DIR) + QString("/") + arg1;
    QDir recipeDir(dirname, "*.csv");
    recipeList = recipeDir.entryList(QDir::Files);
}

int page400::LoadRecipe(const QString filename)
{
    FILE * fp = fopen(filename.toAscii().data(), "r");
    if (fp == NULL)
    {
        LOG_PRINT(info_e, "Cannot open '%s'\n", filename.toAscii().data());
        return -1;
    }
    char varname[TAG_LEN] = "";
    char value[TAG_LEN] = "";
    char line[MAX_LINE] = "";
    char * p;
    int number_of_variables = 0;
    while (fgets(line, LINE_SIZE, fp) != NULL)
    {
        p = line;
        /* tag */
        p = mystrtok(p, varname, SEPARATOR);
        if (p == NULL || varname[0] == '\0')
        {
            LOG_PRINT(error_e, "Invalid tag '%s'\n", line);
            continue;
        }
        int decimal = getVarDecimalByName(varname);
        /* value */
        p = mystrtok(p, value, SEPARATOR);
        if (value[0] != '\0')
        {
            float val_f = 0;
            val_f = atof(value);
            sprintf(value, "%.*f", decimal, val_f );
            if (prepareFormattedVar(varname, value) == BUSY)
            {
                LOG_PRINT(warning_e, "busy, waiting to write the variable '%s' with the value '%s'\n", varname, value);
            }
            LOG_PRINT(info_e, "value '%s'\n", value);
            number_of_variables++;
        }
    }
    fclose(fp);
    if (number_of_variables > 0)
    {
        writePendingInorder();
    }
    return number_of_variables;
}

void page400::on_pushButtonNext_clicked()
{
    static int step = 0;
    if (step >= recipeList.count())
    {
        if (recipeList.count() == 0)
        {
            fprintf(stderr, "Nothing to load\n");
            return;
        }
        if (!ui->checkBoxRepeat->isChecked())
        {
            fprintf(stderr, "Step finished!\n");
            return;
        }
        else
        {
            step = 0;
        }
    }
    ui->pushButtonNext->setEnabled(false);
    if (LoadRecipe(dirname + QString("/") + recipeList.at(step)) < 0)
    {
        fprintf(stderr, "FAIL dirname '%s'\n",QString(dirname + QString("/") + recipeList.at(step)).toAscii().data() );
    }
    else
    {
        fprintf(stderr, "DO_TEST dirname '%s'\n",QString(dirname + QString("/") + recipeList.at(step)).toAscii().data() );
        step++;
        doWrite_DO_TEST(1);
    }
}

void page400::on_pushButton_PWR_toggled(bool checked)
{
    if (checked) {
        doWrite_PLC_DigDir_2(1);
        doWrite_PLC_DigDir_3(1);
        doWrite_PLC_DigOut_2(1);
        doWrite_PLC_DigOut_3(1);
    } else {
        doWrite_PLC_DigDir_2(1);
        doWrite_PLC_DigDir_3(1);
        doWrite_PLC_DigOut_2(0);
        doWrite_PLC_DigOut_3(0);
    }
}
