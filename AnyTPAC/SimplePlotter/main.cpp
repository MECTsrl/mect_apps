#include "mainwindow.h"
#include <QApplication>
#include <QWSServer>

int main(int argc, char *argv[])
{ 

#ifdef Q_WS_QWS
    char vncString [64];
    sprintf(vncString,"Multi: VNC:0:size=%dx%d Transformed:rot%d", 480, 272, 0);

    int myargc = 4;
    char *myargv[] =
    {
        argv[0],
        strdup("-qws"),
        strdup("-display"),
        vncString
    };


    QApplication a(myargc, myargv);
#else
    QApplication a(argc, argv);
#endif


    MainWindow w;
    w.show();
    
    return a.exec();
}
