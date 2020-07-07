#include "mainwindow.h"
#include "model.h"
#include "midi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppModel model;
    MainWindow w(&model);

    model.midiOut = new RtMidiOut;


    w.show();

    return a.exec();
}
