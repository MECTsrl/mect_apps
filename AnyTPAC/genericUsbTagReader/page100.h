/**
 * @file
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE100_H
#define PAGE100_H

#include "pagebrowser.h"
#include "tagreader.h"

namespace Ui {
class page100;
}

class page100 : public page
{
    Q_OBJECT
    
public:
    explicit page100(QWidget *parent = 0);
    ~page100();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void changeEvent(QEvent * event);
    void updateTagData(QString currentTagID);
    
private:
    Ui::page100     *ui;
    tagReader       *myReader;
    int             myStatus;
    QString         serialDevice;
    QString         myMessage;
};

#endif // PAGE100_H


