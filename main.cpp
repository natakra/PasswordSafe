#include "login.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
