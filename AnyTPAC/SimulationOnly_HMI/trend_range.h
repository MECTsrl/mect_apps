/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef TREND_RANGE_H
#define TREND_RANGE_H

#include "pagebrowser.h"

namespace Ui {
class trend_range;
}

class trend_range : public page
{
    Q_OBJECT
    
public:
    explicit trend_range(QWidget *parent = 0);
    ~trend_range();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonOk_clicked();
    
private:
    Ui::trend_range *ui;
    QDateTime _Tzero;
    int _deltaT;
};

#endif // TREND_RANGE_H


