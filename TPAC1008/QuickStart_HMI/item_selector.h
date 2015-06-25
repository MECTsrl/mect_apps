/**
 * @file
 * @author Emiliano Bergamaschini <ebergamaschini@mect.it>
 *
 * @section LICENSE
 * Copyright Mect s.r.l. 2013
 *
 * @brief Main page
 */
#ifndef SELECT_H
#define SELECT_H

#include <QDialog>

#include "common.h"

namespace Ui {
class item_selector;
}

class item_selector : public QDialog
{
    Q_OBJECT
    
public:
    explicit item_selector(QStringList list, QString * selection, QString title = "", QWidget *parent = 0);
    ~item_selector();
    virtual void reload(void);
    
private slots:
    void on_pushButtonView_clicked();
    
    void on_pushButtonBack_clicked();
    
private:
    Ui::item_selector *ui;
    QString * _selection;
    QStringList * _list;
};

#endif // SELECT_H

