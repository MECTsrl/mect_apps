/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE330_H
#define PAGE330_H

#include "pagebrowser.h"

namespace Ui {
class page330;
}

class page330 : public page
{
    Q_OBJECT
    
public:
    explicit page330(QWidget *parent = 0);
    ~page330();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page330 *ui;
};

#endif // PAGE330_H

