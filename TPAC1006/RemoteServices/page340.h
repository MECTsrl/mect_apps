/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE340_H
#define PAGE340_H

#include "pagebrowser.h"

namespace Ui {
class page340;
}

class page340 : public page
{
    Q_OBJECT
    
public:
    explicit page340(QWidget *parent = 0);
    ~page340();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    
private:
    Ui::page340 *ui;
};

#endif // PAGE340_H

