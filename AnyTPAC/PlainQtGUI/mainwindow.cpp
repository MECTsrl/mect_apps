#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWSServer>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
#ifdef Q_WS_QWS
  QMainWindow::showFullScreen();
  QWSServer::setCursorVisible( false );
#endif

ui->label->setText("Hello World");
}


MainWindow::~MainWindow()
{
  delete ui;
}
