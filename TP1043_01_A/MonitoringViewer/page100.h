/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE100_H
#define PAGE100_H

#include "pagebrowser.h"

namespace Ui {
class page100;
}

#define MAX_VARS 9

struct trendVariable {
    // file trend.csv
    QString name;
    QString color;
    double min;
    double max;
    QString descr;
    // ui
    QLabel *labelName;
    QLabel *labelValue;
    // crosstable
    unsigned id;
    double value;
};

class page100 : public page
{
    Q_OBJECT
    
public:
    explicit page100(QWidget *parent = 0);
    ~page100();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
    void on_comboBox_trend_currentIndexChanged(const QString &arg1);

private:
    Ui::page100 *ui;
    QStringList trendList;
    struct trendVariable vars[MAX_VARS];
    void initVars();
    void clearVars();

};

#endif // PAGE100_H


