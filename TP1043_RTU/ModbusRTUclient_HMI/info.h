/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Info page
 */
#ifndef INFO_H
#define INFO_H

#include "pagebrowser.h"

namespace Ui {
class info;
}

class info : public page
{
    Q_OBJECT
    
public:
    explicit info(QWidget *parent = 0);
    ~info();
    virtual void reload(void);
    virtual void updateData();
    bool getVersion(const char * command, char * version, int maxsize);
    
private slots:
    void on_pushButtonHome_clicked();
    
private:
    Ui::info *ui;
};

#endif // INFO_H


