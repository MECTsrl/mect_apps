#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QList>
#include <QIntValidator>
#include <QRegExp>
#include <QRegExpValidator>
#include <QUrl>
#include <QMessageBox>
#if QT_VERSION < 0x050000
#include <QWSServer>
#endif
#include <QProgressBar>
#include <QDir>
#include <QFile>
#include <QColorDialog>
#include <QMenu>
#include "mectcomm.h"
#include "qcustomplot.h"
#include "timepopup.h"
#include "calendar.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void errorManager(QString errorCode);
    void on_getVarPushButton_clicked();
    void fillList();
    void getValue();
    void qCustomPlotSetUp();
    void plotData(QList <varPoint> valuesList , QString variableName);
    void progressBar(int progress);
    void fillTrendList();

    void contextMenuRequest(QPoint pos);

    void moveLegend();

    void on_getValuesPushButton_clicked();


    void on_radioDay_toggled(bool checked);

    void on_radioWeek_toggled(bool checked);

    void on_radioMonth_toggled(bool checked);

    void on_radioYear_toggled(bool checked);

    void on_alphapadButton_clicked();

    void on_numpadButton_clicked();

    void on_zoomInButton_toggled(bool checked);

    void legendClick();

    void on_resetZoomButton_clicked();

    void on_getTrendPushButton_clicked();

    void on_fromDataButton_clicked();

    void on_toDataButton_clicked();

private:
    Ui::MainWindow *ui;
    QString currentURL;
    QStringList variableList;
    QStringList trendList;
    QStringList trendVarList;
    QStringList colorList;

    int colorNumber;

    mectComm *mectPtr;
    TimePopup *timepopFrom;
    TimePopup *timepopTo;

    Calendar *calendarFrom;
    Calendar *calendarTo;

    QProgressBar *pb;

};

#endif // MAINWINDOW_H
