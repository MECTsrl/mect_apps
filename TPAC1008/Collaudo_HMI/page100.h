/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE100_H
#define PAGE100_H

#include "pagebrowser.h"

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
    void on_atcmComboBox_AnIn_1_currentIndexChanged(int index);

    void on_atcmComboBox_AnIn_2_currentIndexChanged(int index);

    void on_atcmComboBox_AnIn_3_currentIndexChanged(int index);

    void on_atcmComboBox_AnIn_4_currentIndexChanged(int index);

    void on_atcmComboBox_AnOut_1_currentIndexChanged(int index);

    void on_atcmComboBox_AnOut_2_currentIndexChanged(int index);
    
private:
    Ui::page100 *ui;
    int counter;
};

#endif // PAGE100_H

