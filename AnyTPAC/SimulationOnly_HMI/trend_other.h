/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef TREND_OTHER_H
#define TREND_OTHER_H

#include <QMouseEvent>

#include "pagebrowser.h"

#include "common.h"

namespace Ui {
class trend_other;
}

class trend_other : public page
{
    Q_OBJECT
    
public:
    explicit trend_other(QWidget *parent = 0);
    ~trend_other();
    virtual void reload(void);
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonBack_clicked();
    
    void on_pushButtonHome_clicked();
    
    void on_pushButtonTime_clicked();
    
    void on_pushButtonOnline_clicked();
    
    void on_pushButtonScreenshot_clicked();
    
    void on_pushButtonPan_clicked();
    
private:
    void mouseMoveEvent(QMouseEvent * e);
    
private:
    Ui::trend_other *ui;
    QWidget * tp;
};

#endif // TREND_OTHER_H

