#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppModel model;
    MainWindow w(&model);


    w.show();

    return a.exec();
}
