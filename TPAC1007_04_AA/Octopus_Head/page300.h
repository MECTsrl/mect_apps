/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef PAGE300_H
#define PAGE300_H

#include "pagebrowser.h"

namespace Ui {
class page300;
}

class page300 : public page
{
    Q_OBJECT
    
public:
    explicit page300(QWidget *parent = 0);
    ~page300();
    virtual void reload(void);
    virtual void updateData();
    // Octopus
    void messageBox(const int result, const char *text);
    void setMessage(const char *msg);

private slots:
    void changeEvent(QEvent * event);
    // Octopus
    void on_atcmComboBox_PRODUCT_ID_currentIndexChanged(int index);
    void on_atcmComboBox_TEST_ID_currentIndexChanged(int index);

    void on_atcmButton_message_toggled(bool checked);

private:
    Ui::page300 *ui;
    // Octopus
    QString qtitle;
    QString qtext;
    QColor qcolor;
};

#endif // PAGE300_H

