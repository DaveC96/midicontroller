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
    ui->c1_lineeditName->setText(this->model->controllers[0].userLabel[this->model->currentLayer]);
    ui->c1_checkboxLatch->setChecked(this->model->controllers[0].latching[this->model->currentLayer]);
}

void MainWindow::setControllerLatch(int id, QCheckBox * element)
{
    this->model->controllers[id].latching[this->model->currentLayer] = element->isChecked();
}

void MainWindow::setUserLabel(int id, QLineEdit * element)
{
    this->model->controllers[id].userLabel[this->model->currentLayer] = element->text();
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  User label lineEdits

void MainWindow::on_c1_lineeditName_returnPressed()
{
    this->setUserLabel(0, ui->c1_lineeditName);
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  Latching checkboxes

void MainWindow::on_c1_checkboxLatch_stateChanged()
{
    this->setControllerLatch(0, ui->c1_checkboxLatch);
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  CC number spinboxes

void MainWindow::on_c1_spinboxCC_valueChanged(int arg1)
{

}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
//  Globals

void MainWindow::on_pushButton_2_clicked()
{
    printf("Breakpoint hit, go read your debugger, nerd.");
}

void MainWindow::on_rb_layer1_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer2_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer3_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer4_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer5_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer6_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer7_clicked() {   this->changeLayers();   }
void MainWindow::on_rb_layer8_clicked() {   this->changeLayers();   }
