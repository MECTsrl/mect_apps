/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE444_H
#define PAGE444_H

#include "pagebrowser.h"

namespace Ui {
class page444;
}

class page444 : public page
{
    Q_OBJECT
    
public:
    explicit page444(QWidget *parent = 0);
    ~page444();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page444 *ui;
};

#endif // PAGE444_H

