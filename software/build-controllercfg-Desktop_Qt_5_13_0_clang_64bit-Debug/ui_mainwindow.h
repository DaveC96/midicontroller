/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Layout;
    QAction *actionLoad_Layout;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLineEdit *c3_lineeditName;
    QCheckBox *c3_checkboxLatch;
    QLabel *label_20;
    QLabel *label_6;
    QSpinBox *c3_spinboxMax;
    QSpinBox *c3_spinboxMin;
    QSpinBox *c3_spinboxCC;
    QGroupBox *groupBox_9;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox_17;
    QLabel *label_17;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QSpinBox *c4_spinboxMin;
    QLabel *label_8;
    QSpinBox *c4_spinboxMax;
    QLineEdit *c4_lineeditName;
    QCheckBox *c4_checkboxLatch;
    QLabel *label_21;
    QSpinBox *c4_spinboxCC;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *c1_labelMax;
    QSpinBox *c1_spinboxMin;
    QLabel *c1_labelMin;
    QSpinBox *c1_spinboxMax;
    QCheckBox *c1_checkboxLatch;
    QLineEdit *c1_lineeditName;
    QSpinBox *c1_spinboxCC;
    QLabel *c1_labelCC;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QSpinBox *c2_spinboxMin;
    QSpinBox *c2_spinboxMax;
    QCheckBox *c2_checkboxLatch;
    QLineEdit *c2_lineeditName;
    QLabel *label_4;
    QSpinBox *c2_spinboxCC;
    QLabel *label_23;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rb_layer1;
    QRadioButton *rb_layer2;
    QRadioButton *rb_layer3;
    QRadioButton *rb_layer4;
    QRadioButton *rb_layer5;
    QRadioButton *rb_layer6;
    QRadioButton *rb_layer7;
    QRadioButton *rb_layer8;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(871, 412);
        actionSave_Layout = new QAction(MainWindow);
        actionSave_Layout->setObjectName(QString::fromUtf8("actionSave_Layout"));
        actionLoad_Layout = new QAction(MainWindow);
        actionLoad_Layout->setObjectName(QString::fromUtf8("actionLoad_Layout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 871, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(gridLayoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setEnabled(true);
        gridLayoutWidget_5 = new QWidget(groupBox_3);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(0, 20, 211, 151));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(16777215, 30));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_5, 3, 0, 1, 1);

        c3_lineeditName = new QLineEdit(gridLayoutWidget_5);
        c3_lineeditName->setObjectName(QString::fromUtf8("c3_lineeditName"));

        gridLayout_5->addWidget(c3_lineeditName, 0, 0, 1, 2);

        c3_checkboxLatch = new QCheckBox(gridLayoutWidget_5);
        c3_checkboxLatch->setObjectName(QString::fromUtf8("c3_checkboxLatch"));

        gridLayout_5->addWidget(c3_checkboxLatch, 1, 0, 1, 2);

        label_20 = new QLabel(gridLayoutWidget_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_20, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_5->addWidget(label_6, 3, 1, 1, 1);

        c3_spinboxMax = new QSpinBox(gridLayoutWidget_5);
        c3_spinboxMax->setObjectName(QString::fromUtf8("c3_spinboxMax"));
        c3_spinboxMax->setMaximum(127);
        c3_spinboxMax->setValue(127);

        gridLayout_5->addWidget(c3_spinboxMax, 4, 1, 1, 1);

        c3_spinboxMin = new QSpinBox(gridLayoutWidget_5);
        c3_spinboxMin->setObjectName(QString::fromUtf8("c3_spinboxMin"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(c3_spinboxMin->sizePolicy().hasHeightForWidth());
        c3_spinboxMin->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(c3_spinboxMin, 4, 0, 1, 1);

        c3_spinboxCC = new QSpinBox(gridLayoutWidget_5);
        c3_spinboxCC->setObjectName(QString::fromUtf8("c3_spinboxCC"));

        gridLayout_5->addWidget(c3_spinboxCC, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_9 = new QGroupBox(gridLayoutWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayoutWidget_3 = new QWidget(groupBox_9);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 20, 871, 151));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        spinBox_17 = new QSpinBox(gridLayoutWidget_3);
        spinBox_17->setObjectName(QString::fromUtf8("spinBox_17"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_17->sizePolicy().hasHeightForWidth());
        spinBox_17->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(spinBox_17, 1, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_17, 0, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 4, 0, 1, 3);


        gridLayout->addWidget(groupBox_9, 1, 0, 1, 4);

        groupBox_4 = new QGroupBox(gridLayoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setEnabled(true);
        gridLayoutWidget_6 = new QWidget(groupBox_4);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(0, 20, 211, 151));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_6->addWidget(label_7, 3, 0, 1, 1);

        c4_spinboxMin = new QSpinBox(gridLayoutWidget_6);
        c4_spinboxMin->setObjectName(QString::fromUtf8("c4_spinboxMin"));
        sizePolicy1.setHeightForWidth(c4_spinboxMin->sizePolicy().hasHeightForWidth());
        c4_spinboxMin->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(c4_spinboxMin, 4, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_6->addWidget(label_8, 3, 1, 1, 1);

        c4_spinboxMax = new QSpinBox(gridLayoutWidget_6);
        c4_spinboxMax->setObjectName(QString::fromUtf8("c4_spinboxMax"));
        c4_spinboxMax->setMaximum(127);
        c4_spinboxMax->setValue(127);

        gridLayout_6->addWidget(c4_spinboxMax, 4, 1, 1, 1);

        c4_lineeditName = new QLineEdit(gridLayoutWidget_6);
        c4_lineeditName->setObjectName(QString::fromUtf8("c4_lineeditName"));

        gridLayout_6->addWidget(c4_lineeditName, 0, 0, 1, 2);

        c4_checkboxLatch = new QCheckBox(gridLayoutWidget_6);
        c4_checkboxLatch->setObjectName(QString::fromUtf8("c4_checkboxLatch"));

        gridLayout_6->addWidget(c4_checkboxLatch, 1, 0, 1, 2);

        label_21 = new QLabel(gridLayoutWidget_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_21, 2, 0, 1, 1);

        c4_spinboxCC = new QSpinBox(gridLayoutWidget_6);
        c4_spinboxCC->setObjectName(QString::fromUtf8("c4_spinboxCC"));

        gridLayout_6->addWidget(c4_spinboxCC, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_4, 0, 3, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 20, 211, 151));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        c1_labelMax = new QLabel(gridLayoutWidget_2);
        c1_labelMax->setObjectName(QString::fromUtf8("c1_labelMax"));
        sizePolicy.setHeightForWidth(c1_labelMax->sizePolicy().hasHeightForWidth());
        c1_labelMax->setSizePolicy(sizePolicy);
        c1_labelMax->setMaximumSize(QSize(16777215, 30));
        c1_labelMax->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(c1_labelMax, 3, 1, 1, 1);

        c1_spinboxMin = new QSpinBox(gridLayoutWidget_2);
        c1_spinboxMin->setObjectName(QString::fromUtf8("c1_spinboxMin"));
        sizePolicy1.setHeightForWidth(c1_spinboxMin->sizePolicy().hasHeightForWidth());
        c1_spinboxMin->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(c1_spinboxMin, 4, 0, 1, 1);

        c1_labelMin = new QLabel(gridLayoutWidget_2);
        c1_labelMin->setObjectName(QString::fromUtf8("c1_labelMin"));
        sizePolicy.setHeightForWidth(c1_labelMin->sizePolicy().hasHeightForWidth());
        c1_labelMin->setSizePolicy(sizePolicy);
        c1_labelMin->setMaximumSize(QSize(16777215, 30));
        c1_labelMin->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(c1_labelMin, 3, 0, 1, 1);

        c1_spinboxMax = new QSpinBox(gridLayoutWidget_2);
        c1_spinboxMax->setObjectName(QString::fromUtf8("c1_spinboxMax"));
        c1_spinboxMax->setMaximum(127);
        c1_spinboxMax->setValue(127);

        gridLayout_2->addWidget(c1_spinboxMax, 4, 1, 1, 1);

        c1_checkboxLatch = new QCheckBox(gridLayoutWidget_2);
        c1_checkboxLatch->setObjectName(QString::fromUtf8("c1_checkboxLatch"));
        c1_checkboxLatch->setChecked(false);

        gridLayout_2->addWidget(c1_checkboxLatch, 1, 0, 1, 2);

        c1_lineeditName = new QLineEdit(gridLayoutWidget_2);
        c1_lineeditName->setObjectName(QString::fromUtf8("c1_lineeditName"));

        gridLayout_2->addWidget(c1_lineeditName, 0, 0, 1, 2);

        c1_spinboxCC = new QSpinBox(gridLayoutWidget_2);
        c1_spinboxCC->setObjectName(QString::fromUtf8("c1_spinboxCC"));

        gridLayout_2->addWidget(c1_spinboxCC, 2, 1, 1, 1);

        c1_labelCC = new QLabel(gridLayoutWidget_2);
        c1_labelCC->setObjectName(QString::fromUtf8("c1_labelCC"));
        c1_labelCC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(c1_labelCC, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(gridLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setFlat(false);
        gridLayoutWidget_4 = new QWidget(groupBox_2);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 20, 211, 151));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        c2_spinboxMin = new QSpinBox(gridLayoutWidget_4);
        c2_spinboxMin->setObjectName(QString::fromUtf8("c2_spinboxMin"));
        sizePolicy1.setHeightForWidth(c2_spinboxMin->sizePolicy().hasHeightForWidth());
        c2_spinboxMin->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(c2_spinboxMin, 4, 0, 1, 1);

        c2_spinboxMax = new QSpinBox(gridLayoutWidget_4);
        c2_spinboxMax->setObjectName(QString::fromUtf8("c2_spinboxMax"));
        c2_spinboxMax->setMaximum(127);
        c2_spinboxMax->setValue(127);

        gridLayout_4->addWidget(c2_spinboxMax, 4, 1, 1, 1);

        c2_checkboxLatch = new QCheckBox(gridLayoutWidget_4);
        c2_checkboxLatch->setObjectName(QString::fromUtf8("c2_checkboxLatch"));

        gridLayout_4->addWidget(c2_checkboxLatch, 1, 0, 1, 2);

        c2_lineeditName = new QLineEdit(gridLayoutWidget_4);
        c2_lineeditName->setObjectName(QString::fromUtf8("c2_lineeditName"));

        gridLayout_4->addWidget(c2_lineeditName, 0, 0, 1, 2);

        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(label_4, 3, 1, 1, 1);

        c2_spinboxCC = new QSpinBox(gridLayoutWidget_4);
        c2_spinboxCC->setObjectName(QString::fromUtf8("c2_spinboxCC"));

        gridLayout_4->addWidget(c2_spinboxCC, 2, 1, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setEnabled(true);
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_23, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 871, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rb_layer1 = new QRadioButton(horizontalLayoutWidget);
        rb_layer1->setObjectName(QString::fromUtf8("rb_layer1"));
        rb_layer1->setChecked(true);

        horizontalLayout->addWidget(rb_layer1);

        rb_layer2 = new QRadioButton(horizontalLayoutWidget);
        rb_layer2->setObjectName(QString::fromUtf8("rb_layer2"));

        horizontalLayout->addWidget(rb_layer2);

        rb_layer3 = new QRadioButton(horizontalLayoutWidget);
        rb_layer3->setObjectName(QString::fromUtf8("rb_layer3"));

        horizontalLayout->addWidget(rb_layer3);

        rb_layer4 = new QRadioButton(horizontalLayoutWidget);
        rb_layer4->setObjectName(QString::fromUtf8("rb_layer4"));

        horizontalLayout->addWidget(rb_layer4);

        rb_layer5 = new QRadioButton(horizontalLayoutWidget);
        rb_layer5->setObjectName(QString::fromUtf8("rb_layer5"));

        horizontalLayout->addWidget(rb_layer5);

        rb_layer6 = new QRadioButton(horizontalLayoutWidget);
        rb_layer6->setObjectName(QString::fromUtf8("rb_layer6"));

        horizontalLayout->addWidget(rb_layer6);

        rb_layer7 = new QRadioButton(horizontalLayoutWidget);
        rb_layer7->setObjectName(QString::fromUtf8("rb_layer7"));

        horizontalLayout->addWidget(rb_layer7);

        rb_layer8 = new QRadioButton(horizontalLayoutWidget);
        rb_layer8->setObjectName(QString::fromUtf8("rb_layer8"));

        horizontalLayout->addWidget(rb_layer8);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 871, 22));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave_Layout);
        menuFile->addAction(actionLoad_Layout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Controller Config", nullptr));
        actionSave_Layout->setText(QCoreApplication::translate("MainWindow", "Save Layout", nullptr));
        actionLoad_Layout->setText(QCoreApplication::translate("MainWindow", "Load Layout", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Controller 3", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        c3_lineeditName->setText(QCoreApplication::translate("MainWindow", "Label", nullptr));
        c3_checkboxLatch->setText(QCoreApplication::translate("MainWindow", "Latched push", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "CC #:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "Globals", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "MIDI Channel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Load from Device", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Write to Device", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Controller 4", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        c4_lineeditName->setText(QCoreApplication::translate("MainWindow", "Label", nullptr));
        c4_checkboxLatch->setText(QCoreApplication::translate("MainWindow", "Latched push", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "CC #:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Controller 1", nullptr));
        c1_labelMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        c1_labelMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        c1_checkboxLatch->setText(QCoreApplication::translate("MainWindow", "Latched push", nullptr));
        c1_lineeditName->setText(QCoreApplication::translate("MainWindow", "Label", nullptr));
        c1_labelCC->setText(QCoreApplication::translate("MainWindow", "CC #:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Controller 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        c2_checkboxLatch->setText(QCoreApplication::translate("MainWindow", "Latched push", nullptr));
        c2_lineeditName->setText(QCoreApplication::translate("MainWindow", "Label", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "CC #:", nullptr));
        rb_layer1->setText(QCoreApplication::translate("MainWindow", "Layer 1", nullptr));
        rb_layer2->setText(QCoreApplication::translate("MainWindow", "Layer 2", nullptr));
        rb_layer3->setText(QCoreApplication::translate("MainWindow", "Layer 3", nullptr));
        rb_layer4->setText(QCoreApplication::translate("MainWindow", "Layer 4", nullptr));
        rb_layer5->setText(QCoreApplication::translate("MainWindow", "Layer 5", nullptr));
        rb_layer6->setText(QCoreApplication::translate("MainWindow", "Layer 6", nullptr));
        rb_layer7->setText(QCoreApplication::translate("MainWindow", "Layer 7", nullptr));
        rb_layer8->setText(QCoreApplication::translate("MainWindow", "Layer 8", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
