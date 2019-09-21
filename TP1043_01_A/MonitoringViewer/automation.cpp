#include "crosstable.h"
#include "automation.h"

/* put here the initalization */
void setup(void)
{
    logStart();
}

/* put here the operation made every 100ms */
void loop(void)
{
    
}

// ----------------------------------------------

#include "C:\Qt485\imx28\rootfs\usr\include\cross_table_utility.h"
#include <QDir>

QStringList getTrendList()
{
    QStringList trendList;

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
        }
    }
    return trendList;
}

void initVars(trendVariable vars[], QLabel *names[], QLabel *values[])
{
    for (int i = 0; i < MAX_VARS; ++i) {
        vars[i].labelName = names[i];
        vars[i].labelValue = values[i];
    }
    clearVars(vars);
}

void clearVars(trendVariable vars[])
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

bool setupVars(trendVariable vars[], const QString trendName, bool isHorizontal)
{
    bool retval = false;
    QFile file(trendsPath + "/" + "trend_" + trendName + ".csv");

    // trend_xxxxx.csv file read
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
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

            if (isHorizontal) {
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
            } else {
                if (nVars == 1) {
                    nameFontSize = "30pt";      // 1 colonna
                    valueFontSize = "100pt";    // 1 riga
                } else if (nVars <= 2) {
                    nameFontSize = "28pt";      // 1 colonna
                    valueFontSize = "100pt";    // 2 riga
                } else if (nVars <= 4) {
                    nameFontSize = "18pt";      // 1 colonne
                    valueFontSize = "50pt";     // 4 righe
                } else if (nVars <= 5) {
                    nameFontSize = "18pt";      // 1 colonna
                    valueFontSize = "36pt";     // 5 righe
                } else {
                    nameFontSize = "16pt";      // 2 colonne
                    valueFontSize = "36pt";     // 5 righe
                }
            }
            vars[i].labelName->setStyleSheet("color:" + vars[i].color + "; font: " + nameFontSize + " \"DejaVu Sans\";");
            vars[i].labelValue->setStyleSheet("color:" + vars[i].color + "; font: " + valueFontSize + " \"DejaVu Sans\";");

            vars[i].labelName->show();
            vars[i].labelValue->show();
        }

        retval = (nVars > 0) ? true : false;
    }
    return retval;
}

void updateVars(trendVariable vars[])
{
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

