/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE434_H
#define PAGE434_H

#include "pagebrowser.h"

namespace Ui {
class page434;
}

class page434 : public page
{
    Q_OBJECT
    
public:
    explicit page434(QWidget *parent = 0);
    ~page434();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page434 *ui;
};

#endif // PAGE434_H

