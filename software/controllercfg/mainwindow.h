#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "ui_mainwindow.h"
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AppModel *model, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_c1_checkboxLatch_stateChanged();
    void on_c1_lineeditName_returnPressed();
    void on_c1_spinboxCC_valueChanged(int arg1);
    void on_pushButton_2_clicked();
    void on_rb_layer1_clicked();
    void on_rb_layer2_clicked();
    void on_rb_layer3_clicked();
    void on_rb_layer4_clicked();
    void on_rb_layer5_clicked();
    void on_rb_layer6_clicked();
    void on_rb_layer7_clicked();
    void on_rb_layer8_clicked();

private:
    Ui::MainWindow *ui;
    AppModel * model;

    void changeLayers();
    void setControllerLatch(int id, QCheckBox * element);
    void setUserLabel(int id, QLineEdit * element);
};

#endif // MAINWINDOW_H
