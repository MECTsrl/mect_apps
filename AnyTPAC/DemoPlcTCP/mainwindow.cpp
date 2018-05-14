#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mectcomm.h"

#include <QGraphicsVideoItem>
#include <QGraphicsView>

#define ID_theHEARTBEAT 193
#define ID_theLED 194
#define ID_theBUTTON 195

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<uint16_t> IDs;
    IDs << ID_theHEARTBEAT;
    IDs << ID_theLED;
    IDs << ID_theBUTTON;
    theMectCommPtr = new mectComm(IDs, this);

//    videoPlayer = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);

//    videoWidget = new QVideoWidget(ui->video_widget);
//    videoPlayer->setVideoOutput(videoWidget);

//    videoPlayer->setMedia(QUrl::fromLocalFile("/sdcard/Movies/video.m4v"));
//    videoWidget->show();
//    videoPlayer->setVolume(50);
//    videoPlayer->play();

    slide = 0;
    tempo_ds = 0;

    timerId = startTimer(500);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != timerId) {
        qDebug() << "got spurious timerEvent ID:" << event->timerId();
        return;
    }

    // the HEARTBEAT
    ui->theHEARTBEAT_label->setText(QString::number(theMectCommPtr->getValue(ID_theHEARTBEAT)));

    // the red BUTTON
    if (theMectCommPtr->getValue(ID_theBUTTON) != 0) {
        ui->theBUTTON_button->setText("red ON");
        ui->theBUTTON_button->setStyleSheet("color: rgb(0, 0, 0);\nbackground-color: rgb(255, 0, 0);\n");
    } else {
        ui->theBUTTON_button->setText("red off");
        ui->theBUTTON_button->setStyleSheet("color: rgb(0, 0, 0);\nbackground-color: rgb(127, 127, 127);\n");
    }

    // the blue LED
    // ui->theLED_button->setText(" <---= ");
    if (theMectCommPtr->getValue(ID_theLED) != 0) {
        //ui->theLED_button->setIcon(QIcon(":/icons/resources/LedOn.png"));
        ui->theLED_button->setText("blue ON");
        ui->theLED_button->setStyleSheet("color: rgb(0, 0, 0);\nbackground-color: rgb(0, 0, 255);\n");
    } else {
        //ui->theLED_button->setIcon(QIcon(":/icons/resources/LedOff.png"));
        ui->theLED_button->setText("blue off");
        ui->theLED_button->setStyleSheet("color: rgb(0, 0, 0);\nbackground-color: rgb(127, 127, 127);\n");
    }

    // the msg
    quint64 reads, writes, commands, errors;
    theMectCommPtr->getStatistics(reads, writes, commands, errors);
    ui->statistics_label->setText(
        "status=" + theMectCommPtr->getStatusString() + "\n"
        + QString("reads=%1, writes=%2, commands=%3, errors=%4").arg(reads).arg(writes).arg(commands).arg(errors));

    // the slide show
    tempo_ds += 5;
    if (tempo_ds >= 50) {
        slide = (slide + 1) % 5;
        tempo_ds = 0;
        ui->video_widget->setText("");
        ui->video_widget->setStyleSheet(QString("border-image: url(:/icons/resources/%1.png);").arg(slide + 1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_theLED_button_clicked()
{
    if (theMectCommPtr->getValue(ID_theLED) == 0) {
        theMectCommPtr->doWrite(ID_theLED, 1);
    } else {
        theMectCommPtr->doWrite(ID_theLED, 0);
    }
}
