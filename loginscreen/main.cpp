#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QString>
#include "userlogin.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    userlogin w;
    w.show();
    return a.exec();
}
