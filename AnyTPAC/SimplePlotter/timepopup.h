#ifndef TIMEPOPUP_H
#define TIMEPOPUP_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QTabWidget>
#include <QListWidgetItem>
#include <QTimeEdit>

class QVBoxLayout;
class QHBoxLayout;
class QDialogButtonBox;
class QTimeEdit;

class TimePopup :public QDialog
{
  Q_OBJECT
public:
  TimePopup(QWidget *parent=0);
  
signals:

public:


public slots:

QTime getTime();
void setTime(QTime currentTime);

private slots:

  void setUpTableHours();
  void setUpTableMinutes();
  void setUpTableSeconds();


  void on_itemClickedHours(int row, int col);
  void on_itemClickedMin(int row,int col);
  void on_itemClickedSec(int row, int col);


  void tableWidgetSetup(QTableWidget *tableWidgetXX);

  void populateTableMinSec(QTableWidget *tableWidget00,QTableWidget *tableWidget15,
                           QTableWidget *tableWidget30,QTableWidget *tableWidget45);


private:
  QWidget *widget;
  QDialogButtonBox* buttonOkCancel;
  QVBoxLayout *verticalLayout;
  QHBoxLayout *horizontalLayout;
  QTableWidget *tableWidgetHours;
  QTabWidget *tabWidget;
  QTimeEdit *te;
  int hour,min,sec;
  QString colorStringSelection;
  QString colorStringBackgroundTab;
  QColor ColorTextItem;

  QTableWidget *tableWidgetMin[4];
  QTableWidget *tableWidgetSec[4];
  QString subTabName[4];

  QTabWidget *tabMinWidget;
  QTabWidget *tabSecWidget;

  
};

#endif // TIMEPOPUP_H
