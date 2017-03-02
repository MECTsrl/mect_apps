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
#include "page300.h"
#include "ui_page300.h"
#include "crosstable.h"

/**
 * @brief this macro is used to set the PAGE300 style.
 * the syntax is html stylesheet-like
 */
#define SET_PAGE300_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

/**
 * @brief This is the constructor. The operation written here, are executed only one time: at the instantiation of the page.
 */
page300::page300(QWidget *parent) :
    page(parent),
    ui(new Ui::page300)
{
    ui->setupUi(this);
    /* set here the protection level (pwd_admin_e, pwd_super_user_e, pwd_user_e, pwd_operator_e), default is pwd_operator_e
     * protection_level = pwd_operator_e;
     */
    
    /* set up the page style */
    //SET_PAGE_STYLE();
    /* set the style described into the macro SET_PAGE300_STYLE */
    SET_PAGE300_STYLE();
    translateFontSize(this);

    doCheckRecipe = false;
    ui->comboBox->addItem("AnOut/sine_wave");
    ui->comboBox->addItem("AnOut/up_and_down");
    ui->comboBox->addItem("DigOut/from_1_to_4");
    ui->comboBox->addItem("DigOut/from_1_to_8");
}

/**
 * @brief This is the reload member. The operation written here, are executed every time this page is shown.
 */
void page300::reload()
{
    /*
       H variables initalizations:
         variableList.clear();
         variableList << "VARIABLE1" << "VARIABLE2" << "VARIABLE3"
       alarm banner initialization in QLineEdit:
         rotateShowError(ui->myLineEdit, ERROR_LABEL_PERIOD_MS);
     */
}

/**
 * @brief This is the updateData member. The operation written here, are executed every REFRESH_MS milliseconds.
 */
void page300::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    /* To read the cross table variable UINT TEST1:
     *    uint_16 tmp = TEST1;
     */
    /* To write 5 into the the cross table variable UINT TEST1:
     *    doWrite_TEST1(5);
     */	

    if (doCheckRecipe)
    {
        int step = ui->spinBox->value();
        if (checkRecipe(step - 1, &recipeIndexes, recipeTable))
        {
            fprintf(stderr, "checkRecipe(%d) ok\n", step);
            doCheckRecipe = false;
        }
        else
        {
            fprintf(stderr, "checkRecipe(%d) failed, retrying\n", step);
        }
    }
}

/**
 * @brief This is the event slot to detect new language translation.
 */
void page300::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
}

/**
 * @brief This is the distructor member. The operation written here, are executed only one time when the page will be deleted.
 */
page300::~page300()
{
    delete ui;
}

void page300::on_spinBox_valueChanged(int step)
{
    ui->spinBox->setEnabled(false);
    if (step > 0)
    {
        if (writeRecipe(step - 1, &recipeIndexes, recipeTable))
        {
            fprintf(stderr, "writeRecipe(%d) failed, please retry\n", step);
        }
        else
        {
            doCheckRecipe = true;
        }
    }
    ui->spinBox->setEnabled(true);
}

void page300::on_comboBox_currentIndexChanged(const QString &recipe)
{
    char filename[84];
    snprintf(filename, 84, "%s/%s.csv", RECIPE_DIR, recipe.toAscii().data());

    ui->spinBox->setEnabled(false);
    steps_number = loadRecipe(filename, &recipeIndexes, recipeTable);

    if (steps_number > 0)
    {
        ui->label_min->setNum(1);
        ui->label_max->setNum(steps_number);

        ui->spinBox->setMinimum(1);
        ui->spinBox->setMaximum(steps_number);

        ui->spinBox->setValue(0);
        ui->spinBox->setReadOnly(false);
    }
    else
    {
        ui->label_min->setNum(0);
        ui->label_max->setNum(0);

        ui->spinBox->setMinimum(0);
        ui->spinBox->setMaximum(0);

        ui->spinBox->setValue(0);
        ui->spinBox->setReadOnly(true);
    }
    ui->spinBox->setEnabled(true);
}
