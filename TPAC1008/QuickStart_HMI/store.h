/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef STORE_H
#define STORE_H

#include "pagebrowser.h"

#define TMPDIR "/tmp"

namespace Ui {
class store;
}

class store : public page
{
    Q_OBJECT
    
public:
    explicit store(QWidget *parent = 0);
    ~store();
    virtual void reload(void);
    virtual void updateData();
    
private slots:
    void on_pushButtonHome_clicked();
    
    void on_pushButtonBack_clicked();
    
    void on_pushButtonUp_clicked();
    
    void on_pushButtonDown_clicked();
    
    void on_pushButtonLeft_clicked();
    
    void on_pushButtonRight_clicked();
    
    void on_pushButtonSaveUSB_clicked();
    
#if 0
    void on_pushButtonPrevious_clicked();
    
    void on_pushButtonNext_clicked();
#endif
    
    void on_pushButtonFilter_clicked();
    
private:
    bool LoadStore(const char * filename);
    bool LoadStore(int fileNb);
    bool LoadStore(QDateTime init, QDateTime final);
    bool LoadStoreFilter(const char * filename);
    int getLogColumnNb(const char * filename);
    bool readLine();
private:
    Ui::store *ui;
    bool force_back;
    int * actual_filter;
    int sizeof_filter;
    QStringList headerList;
    QStringList logFileList;
    int current_row;
    int current_column;
    FILE * logfp;
    int _current;
    int _file_nb;
    char outputfile[FILENAME_MAX];
private:
};

#endif // STORE_H



