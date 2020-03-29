#include "login.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
//    QDesktopWidget dw;
//    double x=dw.width()*0.5;
//    double y=dw.height()*0.5;
//    int xw = static_cast<int>(x);
//    int yw = static_cast<int>(y);
//    w.setFixedSize(xw,yw);
    w.show();



    return a.exec();
}
