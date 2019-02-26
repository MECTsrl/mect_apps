#include "mainwindow.h"
#include <QApplication>

#if QT_VERSION < 0x050000
#include <QWSServer>
#endif

int main(int argc, char *argv[])
{ 

#ifdef Q_WS_QWS

    int myargc = 4;
    char *myargv[] =
    {
        argv[0],
        strdup("-qws"),
        strdup("-display"),
        strdup("VNC:LinuxFb")
    };
    QApplication a(myargc, myargv);
#else
    QApplication a(argc, argv);
#endif


    MainWindow w;
    w.show();
    
    return a.exec();
}
