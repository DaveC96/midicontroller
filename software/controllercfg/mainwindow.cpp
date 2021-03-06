#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "../../common/sysexmessaging.h"
#include <iostream>
#include "midi.h"
#include <QThread>

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
    ui->c1_lineeditName ->setText   (QString::fromStdString(this->model->controllers[0].getUserLabels()[this->model->currentLayer]));
    ui->c2_lineeditName ->setText   (QString::fromStdString(this->model->controllers[1].getUserLabels()[this->model->currentLayer]));
    ui->c3_lineeditName ->setText   (QString::fromStdString(this->model->controllers[2].getUserLabels()[this->model->currentLayer]));
    ui->c4_lineeditName ->setText   (QString::fromStdString(this->model->controllers[3].getUserLabels()[this->model->currentLayer]));
    ui->c1_checkboxLatch->setChecked(this->model->controllers[0].getLatchings()[this->model->currentLayer]);
    ui->c2_checkboxLatch->setChecked(this->model->controllers[1].getLatchings()[this->model->currentLayer]);
    ui->c3_checkboxLatch->setChecked(this->model->controllers[2].getLatchings()[this->model->currentLayer]);
    ui->c4_checkboxLatch->setChecked(this->model->controllers[3].getLatchings()[this->model->currentLayer]);
    ui->c1_spinboxCC    ->setValue  (this->model->controllers[0].getControllerIDs()[this->model->currentLayer]);
    ui->c2_spinboxCC    ->setValue  (this->model->controllers[1].getControllerIDs()[this->model->currentLayer]);
    ui->c3_spinboxCC    ->setValue  (this->model->controllers[2].getControllerIDs()[this->model->currentLayer]);
    ui->c4_spinboxCC    ->setValue  (this->model->controllers[3].getControllerIDs()[this->model->currentLayer]);
    ui->c1_spinboxMin   ->setValue  (this->model->controllers[0].getMinVals()[this->model->currentLayer]);
    ui->c2_spinboxMin   ->setValue  (this->model->controllers[1].getMinVals()[this->model->currentLayer]);
    ui->c3_spinboxMin   ->setValue  (this->model->controllers[2].getMinVals()[this->model->currentLayer]);
    ui->c4_spinboxMin   ->setValue  (this->model->controllers[3].getMinVals()[this->model->currentLayer]);
    ui->c1_spinboxMax   ->setValue  (this->model->controllers[0].getMaxVals()[this->model->currentLayer]);
    ui->c2_spinboxMax   ->setValue  (this->model->controllers[1].getMaxVals()[this->model->currentLayer]);
    ui->c3_spinboxMax   ->setValue  (this->model->controllers[2].getMaxVals()[this->model->currentLayer]);
    ui->c4_spinboxMax   ->setValue  (this->model->controllers[3].getMaxVals()[this->model->currentLayer]);



}

void MainWindow::setControllerLatch(int id, QCheckBox * element)
{
    this->model->controllers[id].setLatching(this->model->currentLayer, element->isChecked());
}

void MainWindow::setUserLabel(int id, QLineEdit * element)
{
    this->model->controllers[id].setUserLabel(this->model->currentLayer, element->text().toStdString());
}

void MainWindow::setControllerCC(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].setControllerID(this->model->currentLayer, element->value());
}

void MainWindow::setControllerMin(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].setMinVal(this->model->currentLayer, element->value());
}

void MainWindow::setControllerMax(int id, QSpinBox * element)
{
    if      (element->value() > 127) {  element->setValue(127); }
    else if (element->value() <   0) {  element->setValue(  0); }
    this->model->controllers[id].setMaxVal(this->model->currentLayer, element->value());
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

void MainWindow::on_glob_buttonWrite_clicked()
{
    std::vector<std::vector<uint8_t>> packets;

    for (uint8_t controller = 0; controller < 1; controller++)
    {
        std::vector<uint8_t> data = this->model->controllers[controller].serialise();
        std::cout << "Test";
        packets.push_back(generateXferData(this->model->controllers[controller].serialise()));
    }

    for (uint8_t controller = 0; controller < 1; controller++)
    {
        model->midiOut->sendMessage(&packets[controller]);
        ui->glob_textBrowser->append(QString("Sent config for controller ").append(QString::number(controller+1)));
    }
    packets.push_back(generatePrep(2));
    model->midiOut->sendMessage(&packets[0]);

//    model->controllers[1].deserialise(packets[0]);
}

void MainWindow::on_glob_buttonLoad_clicked()
{
    std::vector<uint8_t> pkt = generateConfigRequest(3);
    QString pstr;
    for (uint8_t data : pkt)
    {
        pstr.append(QString::number(data, 16).rightJustified(2, '0').toUpper() + " ");
    }
    ui->glob_textBrowser->append("Packet: [ " + pstr + "]");
}

void MainWindow::on_rb_layer1_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer2_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer3_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer4_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer5_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer6_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer7_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer8_clicked() {   this->changeLayers();   }

void MainWindow::on_glob_buttonOpenPort_clicked()
{
    const std::string target = "Teensy MIDI";   // Probably select this at some point
    if (openPort(model->midiOut, target) == 0)
    {
        ui->glob_labelPortActive->setText(QString::fromStdString("Active"));
        ui->glob_textBrowser->append(QString::fromStdString("Opened port: " + target));
    } else {
        ui->glob_labelPortActive->setText(QString::fromStdString("Not found"));
        ui->glob_textBrowser->append(QString::fromStdString("Not found: " + target));
    }

}
