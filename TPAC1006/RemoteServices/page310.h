/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE310_H
#define PAGE310_H

#include "pagebrowser.h"

namespace Ui {
class page310;
}

class page310 : public page
{
    Q_OBJECT
    
public:
    explicit page310(QWidget *parent = 0);
    ~page310();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page310 *ui;
};

#endif // PAGE310_H

