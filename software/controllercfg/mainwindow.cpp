#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"

MainWindow::MainWindow(AppModel *model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = model;
    this->model->currentLayer = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  Funnel setter functions

void MainWindow::changeLayers()
{
    // Work out which layer has been selected, and update the model
    QRadioButton * references[8]
    {
        ui->rb_layer1, ui->rb_layer2, ui->rb_layer3, ui->rb_layer4,
        ui->rb_layer5, ui->rb_layer6, ui->rb_layer7, ui->rb_layer8
    };
    for (int i = 0; i < 8; i++)
    {
        if (references[i]->isChecked())
        {
            this->model->currentLayer = i;
            break;
        }
    }

    // Update the UI elements
    ui->c1_lineeditName ->setText   (this->model->controllers[0].userLabel[this->model->currentLayer]);
    ui->c2_lineeditName ->setText   (this->model->controllers[1].userLabel[this->model->currentLayer]);
    ui->c3_lineeditName ->setText   (this->model->controllers[2].userLabel[this->model->currentLayer]);
    ui->c4_lineeditName ->setText   (this->model->controllers[3].userLabel[this->model->currentLayer]);
    ui->c1_checkboxLatch->setChecked(this->model->controllers[0].latching[this->model->currentLayer]);
    ui->c2_checkboxLatch->setChecked(this->model->controllers[1].latching[this->model->currentLayer]);
    ui->c3_checkboxLatch->setChecked(this->model->controllers[2].latching[this->model->currentLayer]);
    ui->c4_checkboxLatch->setChecked(this->model->controllers[3].latching[this->model->currentLayer]);
    ui->c1_spinboxCC    ->setValue  (this->model->controllers[0].controllerID[this->model->currentLayer]);
    ui->c2_spinboxCC    ->setValue  (this->model->controllers[1].controllerID[this->model->currentLayer]);
    ui->c3_spinboxCC    ->setValue  (this->model->controllers[2].controllerID[this->model->currentLayer]);
    ui->c4_spinboxCC    ->setValue  (this->model->controllers[3].controllerID[this->model->currentLayer]);
    ui->c1_spinboxMin   ->setValue  (this->model->controllers[0].minVal[this->model->currentLayer]);
    ui->c2_spinboxMin   ->setValue  (this->model->controllers[1].minVal[this->model->currentLayer]);
    ui->c3_spinboxMin   ->setValue  (this->model->controllers[2].minVal[this->model->currentLayer]);
    ui->c4_spinboxMin   ->setValue  (this->model->controllers[3].minVal[this->model->currentLayer]);
    ui->c1_spinboxMax   ->setValue  (this->model->controllers[0].maxVal[this->model->currentLayer]);
    ui->c2_spinboxMax   ->setValue  (this->model->controllers[1].maxVal[this->model->currentLayer]);
    ui->c3_spinboxMax   ->setValue  (this->model->controllers[2].maxVal[this->model->currentLayer]);
    ui->c4_spinboxMax   ->setValue  (this->model->controllers[3].maxVal[this->model->currentLayer]);



}

void MainWindow::setControllerLatch(int id, QCheckBox * element)
{
    this->model->controllers[id].latching[this->model->currentLayer] = element->isChecked();
}

void MainWindow::setUserLabel(int id, QLineEdit * element)
{
    this->model->controllers[id].userLabel[this->model->currentLayer] = element->text();
}

void MainWindow::setControllerCC(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].controllerID[this->model->currentLayer] = element->value();
}

void MainWindow::setControllerMin(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].minVal[this->model->currentLayer] = element->value();
}

void MainWindow::setControllerMax(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].maxVal[this->model->currentLayer] = element->value();
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  Controller UI callbacks

void MainWindow::on_c1_lineeditName_returnPressed() {   this->setUserLabel(0, ui->c1_lineeditName);         }
void MainWindow::on_c2_lineeditName_returnPressed() {   this->setUserLabel(1, ui->c2_lineeditName);         }
void MainWindow::on_c3_lineeditName_returnPressed() {   this->setUserLabel(2, ui->c3_lineeditName);         }
void MainWindow::on_c4_lineeditName_returnPressed() {   this->setUserLabel(3, ui->c3_lineeditName);         }
void MainWindow::on_c1_checkboxLatch_stateChanged() {   this->setControllerLatch(0, ui->c1_checkboxLatch);  }
void MainWindow::on_c2_checkboxLatch_stateChanged() {   this->setControllerLatch(1, ui->c2_checkboxLatch);  }
void MainWindow::on_c3_checkboxLatch_stateChanged() {   this->setControllerLatch(2, ui->c3_checkboxLatch);  }
void MainWindow::on_c4_checkboxLatch_stateChanged() {   this->setControllerLatch(3, ui->c4_checkboxLatch);  }
void MainWindow::on_c1_spinboxCC_valueChanged()     {   this->setControllerCC(0, ui->c1_spinboxCC);         }
void MainWindow::on_c2_spinboxCC_valueChanged()     {   this->setControllerCC(1, ui->c2_spinboxCC);         }
void MainWindow::on_c3_spinboxCC_valueChanged()     {   this->setControllerCC(2, ui->c3_spinboxCC);         }
void MainWindow::on_c4_spinboxCC_valueChanged()     {   this->setControllerCC(3, ui->c4_spinboxCC);         }
void MainWindow::on_c1_spinboxMin_valueChanged()    {   this->setControllerMin(0, ui->c1_spinboxMin);       }
void MainWindow::on_c2_spinboxMin_valueChanged()    {   this->setControllerMin(1, ui->c2_spinboxMin);       }
void MainWindow::on_c3_spinboxMin_valueChanged()    {   this->setControllerMin(2, ui->c3_spinboxMin);       }
void MainWindow::on_c4_spinboxMin_valueChanged()    {   this->setControllerMin(3, ui->c4_spinboxMin);       }
void MainWindow::on_c1_spinboxMax_valueChanged()    {   this->setControllerMax(0, ui->c1_spinboxMax);       }
void MainWindow::on_c2_spinboxMax_valueChanged()    {   this->setControllerMax(1, ui->c2_spinboxMax);       }
void MainWindow::on_c3_spinboxMax_valueChanged()    {   this->setControllerMax(2, ui->c3_spinboxMax);       }
void MainWindow::on_c4_spinboxMax_valueChanged()    {   this->setControllerMax(3, ui->c4_spinboxMax);       }

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  Globals UI callbacks

void MainWindow::on_pushButton_2_clicked()
{
    printf("Breakpoint hit, go read your debugger, nerd.");
    int a = sizeof(ControllerConfig);
}

void MainWindow::on_rb_layer1_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer2_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer3_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer4_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer5_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer6_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer7_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer8_clicked() {   this->changeLayers();   }
