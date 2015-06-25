/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE500_H
#define PAGE500_H

#include "pagebrowser.h"

namespace Ui {
class page500;
}

class page500 : public page
{
    Q_OBJECT
    
public:
    explicit page500(QWidget *parent = 0);
    ~page500();
    virtual void reload(void);
    virtual void updateData();
    
private:
    Ui::page500 *ui;
};

#endif // PAGE500_H

