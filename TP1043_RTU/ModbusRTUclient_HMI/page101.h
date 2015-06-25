/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE101_H
#define PAGE101_H

#include "pagebrowser.h"

namespace Ui {
class page101;
}

class page101 : public page
{
    Q_OBJECT
    
public:
    explicit page101(QWidget *parent = 0);
    ~page101();
    virtual void reload(void);
    virtual void updateData();
    
private:
    Ui::page101 *ui;
};

#endif // PAGE101_H

