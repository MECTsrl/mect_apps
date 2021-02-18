#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#define SET_PAGE100_STYLE() { \
    QString mystyle; \
    mystyle.append(this->styleSheet()); \
    /* add there the page stilesheet customization */ \
    mystyle.append(""); \
    this->setStyleSheet(mystyle); \
    }

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

    // vars
    QLabel *names[MAX_VARS];
    QLabel *values[MAX_VARS];
    names[1 - 1] = ui->label_var_1; values[1 - 1] = ui->label_value_1;
    names[2 - 1] = ui->label_var_2; values[2 - 1] = ui->label_value_2;
    names[3 - 1] = ui->label_var_3; values[3 - 1] = ui->label_value_3;
    names[4 - 1] = ui->label_var_4; values[4 - 1] = ui->label_value_4;
    names[5 - 1] = ui->label_var_5; values[5 - 1] = ui->label_value_5;
    names[6 - 1] = ui->label_var_6; values[6 - 1] = ui->label_value_6;
    names[7 - 1] = ui->label_var_7; values[7 - 1] = ui->label_value_7;
    names[8 - 1] = ui->label_var_8; values[8 - 1] = ui->label_value_8;
    names[9 - 1] = ui->label_var_9; values[9 - 1] = ui->label_value_9;
    initVars(vars, names, values);

    // datetime
    ui->label_datetime->setText(QDateTime::currentDateTime().toString("hh:mm")); // "YYYY-MM-DD hh:mm:ss"

    // trend
    ui->comboBox_trend->clear();
    trendList = getTrendList();
    if (trendList.count()) {
        ui->comboBox_trend->blockSignals(true);
        ui->comboBox_trend->addItems(trendList);
        ui->comboBox_trend->blockSignals(false);
        // eventuale recupero ultima selezione dalle ritentive
        if (SelezioneTrend < 0 || SelezioneTrend >= ui->comboBox_trend->count()) {
            doWrite_SelezioneTrend(0);
        } else {
            ui->comboBox_trend->setCurrentIndex(SelezioneTrend);
        }
    }
}

void page100::reload()
{
}

void page100::updateData()
{
    if (this->isVisible() == false)
    {
        return;
    }
    /* call the parent updateData member */
    page::updateData();
    
    // datetime
    ui->label_datetime->setText(QDateTime::currentDateTime().toString("hh:mm")); // "YYYY-MM-DD hh:mm:ss"
    // vars
    updateVars(vars);
}

void page100::changeEvent(QEvent * event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}

page100::~page100()
{
    delete ui;
}

void page100::on_comboBox_trend_currentIndexChanged(const QString &arg1)
{   
    ui->comboBox_trend->setEnabled(false);

    clearVars(vars);
    if (setupVars(vars, arg1)) {
        doWrite_SelezioneTrend(ui->comboBox_trend->currentIndex());
    } else {
        QMessageBox::critical (this," Trends List ","Wrong trend:\n\t" + arg1);
    }
    ui->comboBox_trend->setEnabled(true);
}
