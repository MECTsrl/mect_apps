/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief display the file SPLASH_FILE for SPLASH_TIMEOUT_MS milliseconds
 */
#ifndef PAGE0_H
#define PAGE0_H

#include "pagebrowser.h"

namespace Ui {
class page0;
}

class page0 : public page
{
    Q_OBJECT
    
public:
    explicit page0(QWidget *parent = 0);
    ~page0();
    virtual void reload(void);
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void changePage();
    
private:
    Ui::page0 *ui;
    bool first_time;
};

#endif // PAGE0_H

