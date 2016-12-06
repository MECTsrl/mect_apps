/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE402_H
#define PAGE402_H

#include "pagebrowser.h"

namespace Ui {
class page402;
}

class page402 : public page
{
    Q_OBJECT
    
public:
    explicit page402(QWidget *parent = 0);
    ~page402();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page402 *ui;
};

#endif // PAGE402_H

