/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef TREND_OPTION_H
#define TREND_OPTION_H

#include "pagebrowser.h"

namespace Ui {
class trend_option;
}

class trend_option : public page
{
    Q_OBJECT
    
public:
    explicit trend_option(QWidget *parent = 0);
    ~trend_option();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonLayout_clicked();
    
    void on_pushButtonChangeTrend_clicked();
    
    void on_checkBoxVisible_clicked(bool checked);
    
    void on_pushButtonYmin_clicked();
    
    void on_pushButtonYmax_clicked();
    
    void on_pushButtonDescription_clicked();
    
    void on_pushButtonChangePen_clicked();
    
    void on_pushButtonDeletePen_clicked();
    
    void on_pushButtonSaveAs_clicked();
    
    void on_pushButtonSave_clicked();
    
    void on_comboBoxColor_currentIndexChanged(int index);
    
    void on_pushButtonSaveUSB_clicked();
    
private:
    void Save(const char * fullfilename);
    
private:
    Ui::trend_option *ui;
    char color[TAG_LEN];
    QStringList curve_palette;
};

#endif // TREND_OPTION_H



