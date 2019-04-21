#include "app_logprint.h"
#include "atcmplugin.h"
#include "main.h"
#include "page100.h"
#include "ui_page100.h"
#include "crosstable.h"

#include "C:\Qt485\imx28\rootfs\usr\include\cross_table_utility.h"

#include <QDir>

const QString trendsPath =
#ifdef Q_WS_QWS
    "/local/data/customtrend"
#elif defined(Q_OS_LINUX)
    "customtrend"
#elif defined(Q_OS_WIN)
    "customtrend"
#else
    "customtrend"
#endif
;

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
    initVars();

    // datetime
    ui->label_datetime->setText(QDateTime::currentDateTime().toString("YYYY-MM-DD hh:mm:ss"));

    // trend
    trendList.clear();
    ui->comboBox_trend->clear();
    QDir trendsDirectory(trendsPath);
    if (trendsDirectory.exists()) {
        trendList = trendsDirectory.entryList(QStringList() << "trend_*.csv", QDir::Files);
        if (trendList.count()) {
            for (int i = 0; i < trendList.count(); ++i) {
                trendList[i].remove("trend_");
                trendList[i].remove(".csv", Qt::CaseInsensitive);
            }
            trendList.sort();
            trendList.removeDuplicates();
            ui->comboBox_trend->addItems(trendList);

            // eventuale recupero ultima selezione dalle ritentive
            if (SelezioneTrend < 0 || SelezioneTrend >= ui->comboBox_trend->count()) {
                doWrite_SelezioneTrend(0);
            } else {
                ui->comboBox_trend->setCurrentIndex(SelezioneTrend);
            }
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
    ui->label_datetime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    // vars
    for (int i = 0; i < MAX_VARS; ++i) {
        register unsigned id = vars[i].id;
        if (id && vars[i].labelValue) {
            int ivalue;
            register char status = readFromDbQuick(id, &ivalue);
            char svalue[42] = "";

            switch (status) {
            case DONE:
            case BUSY: {
                register int decimal = getVarDecimalByCtIndex(id);
                sprintf_fromValue(svalue, id, ivalue, decimal, 10);
            }   break;
            case ERROR:
                sprintf(svalue, "--");
                break;
            default:
                sprintf(svalue, "???");
            }
            vars[i].labelValue->setText(svalue);
        }
    }
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

void page100::initVars()
{
    for (int i = 0; i < MAX_VARS; ++i) {
        switch (i+1) {
        case 1: vars[i].labelName = ui->label_var_1; vars[i].labelValue = ui->label_value_1;  break;
        case 2: vars[i].labelName = ui->label_var_2; vars[i].labelValue = ui->label_value_2;  break;
        case 3: vars[i].labelName = ui->label_var_3; vars[i].labelValue = ui->label_value_3;  break;
        case 4: vars[i].labelName = ui->label_var_4; vars[i].labelValue = ui->label_value_4;  break;
        case 5: vars[i].labelName = ui->label_var_5; vars[i].labelValue = ui->label_value_5;  break;
        case 6: vars[i].labelName = ui->label_var_6; vars[i].labelValue = ui->label_value_6;  break;
        case 7: vars[i].labelName = ui->label_var_7; vars[i].labelValue = ui->label_value_7;  break;
        case 8: vars[i].labelName = ui->label_var_8; vars[i].labelValue = ui->label_value_8;  break;
        case 9: vars[i].labelName = ui->label_var_9; vars[i].labelValue = ui->label_value_9;  break;
        default: ;
        }
    }
    clearVars();
}

void page100::clearVars()
{
    for (int i = 0; i < MAX_VARS; ++i) {
        vars[i].name = "";
        vars[i].color = "#000000";
        vars[i].min = 0;
        vars[i].max = 0;
        vars[i].descr = "";
        vars[i].labelName->setText("");
        vars[i].labelValue->setText("");
        vars[i].labelName->hide();
        vars[i].labelValue->hide();
        vars[i].id = 0;
        vars[i].value = 0.0;
    }
}

void page100::on_comboBox_trend_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_trend->setEnabled(false);

    clearVars();

    // trend_xxxxx.csv file read
    QFile file(trendsPath + "/" + "trend_" + arg1 + ".csv");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical (this," Trends List ","Can't open the file:\n\t" + file.fileName());
    } else {
        QTextStream in(&file);
        bool firstLine = true;
        int nVars = 0;

        while (!in.atEnd()) {
            QString line = in.readLine();

            if (firstLine) {
                firstLine = false;
                // skip "L" or "P"
                continue;
            }
            QStringList columns = line.split(";", QString::KeepEmptyParts);

            if (columns.count() != 6 || columns[0].isEmpty() || columns[0] != "1") {
                // skip wrong or disabled variables
                continue;
            }
            if (nVars >= MAX_VARS) {
                // stop if over the limit
                break;
            }
            bool ok;
            QString name;
            QString color;
            float min;
            float max;
            QString descr;

            name = columns.at(1).trimmed();
            ok = ! name.isEmpty();
            if (ok) {
                color = columns.at(2).trimmed();
                ok = ! color.isEmpty();
                if (color == "000000") color = "FFFFFF";
            }
            if (ok) min = columns.at(3).trimmed().toFloat(&ok);
            if (ok) max = columns.at(4).trimmed().toFloat(&ok);
            if (ok) descr = columns.at(5).trimmed();

            if (ok) {
                vars[nVars].name = name;
                // vars[i].color = QColor(((color & 0xFF0000)>>16), ((color & 0xFF00)>>8), ((color & 0xFF)));
                vars[nVars].color = "#" + color;
                vars[nVars].min = min;
                vars[nVars].max = max;
                vars[nVars].descr = descr;
                vars[nVars].labelName->setText(descr);
                vars[nVars].labelValue->setText("0");
                vars[nVars].id = 0;
                for (int id = 1; id <= DB_SIZE_ELEM; ++id) {
                    if (varNameArray[id].tag[0] && name.compare(varNameArray[id].tag) == 0) {
                        vars[nVars].id = id;
                        break;
                    }
                }
                vars[nVars].value = 0;
                ++nVars;
            }
        }
        file.close();

        // adjust sizes and show
        for (int i = 0; i < nVars; ++i) {
            QString nameFontSize;
            QString valueFontSize;

            if (nVars == 1) {
                nameFontSize = "36pt";      // 1 colonna
                valueFontSize = "120pt";    // 1 riga
            } else if (nVars <= 2) {
                nameFontSize = "28pt";      // 2 colonne
                valueFontSize = "120pt";    // 1 riga
            } else if (nVars <= 4) {
                nameFontSize = "28pt";      // 2 colonne
                valueFontSize = "60pt";     // 2 righe
            } else if (nVars <= 6) {
                nameFontSize = "20pt";      // 3 colonne
                valueFontSize = "60pt";     // 2 righe
            } else {
                nameFontSize = "20pt";      // 3 colonne
                valueFontSize = "40pt";     // 3 righe
            }
            vars[i].labelName->setStyleSheet("color:" + vars[i].color + "; font: " + nameFontSize + " \"DejaVu Sans\";");
            vars[i].labelValue->setStyleSheet("color:" + vars[i].color + "; font: " + valueFontSize + " \"DejaVu Sans\";");

            vars[i].labelName->show();
            vars[i].labelValue->show();
        }

        doWrite_SelezioneTrend(ui->comboBox_trend->currentIndex());
    }

    ui->comboBox_trend->setEnabled(true);

}
