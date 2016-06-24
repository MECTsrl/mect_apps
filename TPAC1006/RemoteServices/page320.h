/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE320_H
#define PAGE320_H

#include "pagebrowser.h"

namespace Ui {
class page320;
}

class page320 : public page
{
    Q_OBJECT
    
public:
    explicit page320(QWidget *parent = 0);
    ~page320();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page320 *ui;
};

#endif // PAGE320_H

