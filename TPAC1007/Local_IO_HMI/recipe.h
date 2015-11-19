/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef RECIPE_H
#define RECIPE_H

#include "pagebrowser.h"

namespace Ui {
class recipe;
}

class recipe : public page
{
    Q_OBJECT
    
public:
    explicit recipe(QWidget *parent = 0);
    ~recipe();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
#ifdef TRANSLATION
    void changeEvent(QEvent * event);
#endif
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonEdit_clicked();
    
    void on_pushButtonRead_clicked();
    
    void on_pushButtonLoad_clicked();
    
    void on_pushButtonSave_clicked();
    
private:
    bool LoadRecipe(const char * filename);
private:
    Ui::recipe *ui;
    bool reading;
    bool writing;
    bool clean;
    bool back;
    bool writing_first;
    bool writing_continue;
    bool force_back;
    int readcounter;
};

#endif // RECIPE_H


