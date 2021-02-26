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

#define nKEYS 11


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
    
signals:
    void hwKeyPressed(int nKey);
    void hwKeyReleased(int nKey);

public slots:
    void sendhwKeyPressed(int nKey);
    void sendhwKeyReleased(int nKey);


private slots:
    void KeyPressed(int nKey);
    void KeyReleased(int nKey);
    void changeEvent(QEvent * event);
    
private:
    Ui::page100 *ui;

    bool nKeysStatus[nKEYS];
};

#endif // PAGE100_H


