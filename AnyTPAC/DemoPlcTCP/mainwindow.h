#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

class mectComm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
      void timerEvent(QTimerEvent *event);

private slots:
      void on_theLED_button_clicked();

private:
    Ui::MainWindow *ui;
    mectComm * theMectCommPtr;
    int timerId;
    QMediaPlayer *videoPlayer;
    QVideoWidget *videoWidget;

    QStringList lstSlides;
    int slide;
    int tempo_ds;
};

#endif // MAINWINDOW_H
