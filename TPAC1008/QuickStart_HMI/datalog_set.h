#ifndef DATALOG_SET_H
#define DATALOG_SET_H

#include "pagebrowser.h"

namespace Ui {
class datalog_set;
}

class datalog_set : public page
{
    Q_OBJECT
    
public:
    explicit datalog_set(QWidget *parent = 0);
    ~datalog_set();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonOk_clicked();
    
    void on_pushButtonLogFreqS_clicked();
    
    void on_pushButtonLogFreqF_clicked();
    
    void on_pushButtonSpace_clicked();
    
private:
    Ui::datalog_set *ui;
};

#endif // DATALOG_SET_H


