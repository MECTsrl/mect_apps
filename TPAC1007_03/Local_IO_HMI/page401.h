/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE401_H
#define PAGE401_H

#include "pagebrowser.h"

namespace Ui {
class page401;
}

class page401 : public page
{
    Q_OBJECT
    
public:
    explicit page401(QWidget *parent = 0);
    ~page401();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page401 *ui;
};

#endif // PAGE401_H

