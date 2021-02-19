#include "crosstable.h"
#include "automation.h"
#include <QElapsedTimer>

#include <QScreen>

#define SILENCE     0x00000000

// 100%; ON  50 cs (0.5 s); off 25 cs (0.25 s); count = 3; total = 3*(0.50+0.25)=2.25 s
#define SOUND_A     0x03193264
#define PERIOD_A_ms 3000 // 3 s

// 100%; ON 100 cs (1.0 s); off 50 cs (0.50 s); count = 5; total = 5*(1.0+0.5)=7,5s
#define SOUND_B     0x05326464
#define PERIOD_B_ms 8000 // 8 s

enum status { QUIET = 0, RINGING_A, RINGING_B };
static status buzzer_status;
QElapsedTimer timer;

/* put here the initalization */
void setup(void)
{
    logStart();
    buzzer_status = QUIET;
    doWrite_PLC_BUZZER(SILENCE);
}

/* put here the operation made every 100ms */
void loop(void)
{
    switch (buzzer_status) {
    case QUIET:
        if (TCP_Alarm) {
            doWrite_PLC_BUZZER(SOUND_A);
            timer.restart();
            buzzer_status = RINGING_A;
        }
        break;
    case RINGING_A:
        if (not TCP_Alarm) {
            doWrite_PLC_BUZZER(SILENCE);
            buzzer_status = QUIET;
        } else if (timer.elapsed() > PERIOD_A_ms) {
            doWrite_PLC_BUZZER(SOUND_B);
            timer.restart();
            buzzer_status = RINGING_B;
        }
        break;
    case RINGING_B:
        if (not TCP_Alarm) {
            doWrite_PLC_BUZZER(SILENCE);
            buzzer_status = QUIET;
        } else if (timer.elapsed() > PERIOD_B_ms) {
            doWrite_PLC_BUZZER(SOUND_A);
            timer.restart();
            buzzer_status = RINGING_A;
        }
        break;
    default:
        doWrite_PLC_BUZZER(SILENCE);
        buzzer_status = QUIET;
    }
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

bool setupVars(trendVariable vars[], const QString trendName)
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
        QString nameFontSize;
        QString valueFontSize;
        QScreen *qScreen = QScreen::instance();
        int width = qScreen->width();
        int height = qScreen->height();

        switch (nVars) {
        //
        // | 1 . . | 1 . . | 1 3 . | 1 3 . | 1 3 7 |
        // | . . . | 2 . . | 2 4 . | 2 4 . | 2 4 8 |
        // | . . . | . . . | . . . | 5 6 . | 5 6 9 |
        //
        case 1:
            // 1 row x 1 column
            if (width > 272) {
                nameFontSize = "36pt";
                valueFontSize = "120pt";
            } else {
                nameFontSize = "36pt";
                valueFontSize = "80pt";
            }
            break;
        case 2:
            // 2 rows x 1 column
            if (height > 272 and width > 272) {
                nameFontSize  = "28pt";
                valueFontSize = "120pt";
            } else {
                nameFontSize  = "28pt";
                valueFontSize = "80pt";
            }
            break;
        case 3:
        case 4:
            // 2 rows x 2 columns
            if (width > 272) {
                nameFontSize = "28pt";
                valueFontSize = "60pt";
            } else {
                nameFontSize = "20pt";
                valueFontSize = "40pt";
            }
            break;
        case 5:
        case 6:
            // 3 rows x 2 columns
            if (height > 272 and width > 272) {
                nameFontSize = "20pt";
                valueFontSize = "60pt";
            } else {
                nameFontSize = "20pt";
                valueFontSize = "40pt";
            }
            break;
        case 7:
        case 8:
        case 9:
            // 3 rows x 3 columns
            if (height > 272 and width > 272) {
                nameFontSize = "20pt";
                valueFontSize = "40pt";
            } else if (width > 272) {
                nameFontSize = "18pt";
                valueFontSize = "28pt";
            } else {
                nameFontSize = "18pt";
                valueFontSize = "26pt";
            }
        }
        for (int i = 0; i < nVars; ++i) {
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

