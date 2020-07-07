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
    void on_c2_checkboxLatch_stateChanged();
    void on_c3_checkboxLatch_stateChanged();
    void on_c4_checkboxLatch_stateChanged();
    void on_c1_lineeditName_returnPressed();
    void on_c2_lineeditName_returnPressed();
    void on_c3_lineeditName_returnPressed();
    void on_c4_lineeditName_returnPressed();
    void on_c1_spinboxCC_valueChanged();
    void on_c2_spinboxCC_valueChanged();
    void on_c3_spinboxCC_valueChanged();
    void on_c4_spinboxCC_valueChanged();
    void on_c1_spinboxMin_valueChanged();
    void on_c2_spinboxMin_valueChanged();
    void on_c3_spinboxMin_valueChanged();
    void on_c4_spinboxMin_valueChanged();
    void on_c1_spinboxMax_valueChanged();
    void on_c2_spinboxMax_valueChanged();
    void on_c3_spinboxMax_valueChanged();
    void on_c4_spinboxMax_valueChanged();
    void on_glob_buttonWrite_clicked();
    void on_glob_buttonLoad_clicked();
    void on_rb_layer1_clicked();
    void on_rb_layer2_clicked();
    void on_rb_layer3_clicked();
    void on_rb_layer4_clicked();
    void on_rb_layer5_clicked();
    void on_rb_layer6_clicked();
    void on_rb_layer7_clicked();
    void on_rb_layer8_clicked();





    void on_glob_buttonOpenPort_clicked();

private:
    Ui::MainWindow *ui;
    AppModel * model;

    void changeLayers       ();
    void setControllerLatch (int id, QCheckBox * element);
    void setUserLabel       (int id, QLineEdit * element);
    void setControllerCC    (int id, QSpinBox * element);
    void setControllerMin   (int id, QSpinBox * element);
    void setControllerMax   (int id, QSpinBox * element);
};

#endif // MAINWINDOW_H
