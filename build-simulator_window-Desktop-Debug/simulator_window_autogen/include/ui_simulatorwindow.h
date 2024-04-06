/********************************************************************************
** Form generated from reading UI file 'simulatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORWINDOW_H
#define UI_SIMULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulatorWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *signal_tab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_16;
    QLineEdit *lineEdit_11;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_18;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_17;
    QLineEdit *lineEdit_10;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_19;
    QLineEdit *lineEdit_8;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *lineEdit_12;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEdit_13;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_14;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_15;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_16;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_2;
    QWidget *station_tab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_23;
    QLineEdit *lineEdit_17;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_25;
    QLineEdit *lineEdit_18;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_24;
    QLineEdit *lineEdit_19;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *pushButton_3;
    QWidget *object_tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimulatorWindow)
    {
        if (SimulatorWindow->objectName().isEmpty())
            SimulatorWindow->setObjectName("SimulatorWindow");
        SimulatorWindow->resize(473, 414);
        QPalette palette;
        QBrush brush(QColor(79, 170, 227, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush1(QColor(232, 232, 232, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        SimulatorWindow->setPalette(palette);
        centralwidget = new QWidget(SimulatorWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        signal_tab = new QWidget();
        signal_tab->setObjectName("signal_tab");
        gridLayout_4 = new QGridLayout(signal_tab);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        scrollArea = new QScrollArea(signal_tab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 415, 472));
        gridLayout_6 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_6->setObjectName("gridLayout_6");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_10 = new QLabel(scrollAreaWidgetContents_4);
        label_10->setObjectName("label_10");

        verticalLayout_9->addWidget(label_10);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_11->setObjectName("lineEdit_11");

        horizontalLayout_16->addWidget(lineEdit_11);

        label_15 = new QLabel(scrollAreaWidgetContents_4);
        label_15->setObjectName("label_15");

        horizontalLayout_16->addWidget(label_15);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_9->setObjectName("lineEdit_9");

        horizontalLayout_18->addWidget(lineEdit_9);

        label_12 = new QLabel(scrollAreaWidgetContents_4);
        label_12->setObjectName("label_12");

        horizontalLayout_18->addWidget(label_12);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_9);


        verticalLayout_9->addLayout(horizontalLayout_18);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_10->setObjectName("lineEdit_10");

        horizontalLayout_17->addWidget(lineEdit_10);

        label_13 = new QLabel(scrollAreaWidgetContents_4);
        label_13->setObjectName("label_13");

        horizontalLayout_17->addWidget(label_13);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_10);


        verticalLayout_9->addLayout(horizontalLayout_17);

        label_14 = new QLabel(scrollAreaWidgetContents_4);
        label_14->setObjectName("label_14");

        verticalLayout_9->addWidget(label_14);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_8->setObjectName("lineEdit_8");

        horizontalLayout_19->addWidget(lineEdit_8);

        label_11 = new QLabel(scrollAreaWidgetContents_4);
        label_11->setObjectName("label_11");

        horizontalLayout_19->addWidget(label_11);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_8);


        verticalLayout_9->addLayout(horizontalLayout_19);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_12->setObjectName("lineEdit_12");

        horizontalLayout_15->addWidget(lineEdit_12);

        label_16 = new QLabel(scrollAreaWidgetContents_4);
        label_16->setObjectName("label_16");

        horizontalLayout_15->addWidget(label_16);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_13->setObjectName("lineEdit_13");

        horizontalLayout_14->addWidget(lineEdit_13);

        label_17 = new QLabel(scrollAreaWidgetContents_4);
        label_17->setObjectName("label_17");

        horizontalLayout_14->addWidget(label_17);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_13);


        verticalLayout_9->addLayout(horizontalLayout_14);

        label_21 = new QLabel(scrollAreaWidgetContents_4);
        label_21->setObjectName("label_21");

        verticalLayout_9->addWidget(label_21);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_14->setObjectName("lineEdit_14");

        horizontalLayout_13->addWidget(lineEdit_14);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_14);


        verticalLayout_9->addLayout(horizontalLayout_13);

        label_22 = new QLabel(scrollAreaWidgetContents_4);
        label_22->setObjectName("label_22");

        verticalLayout_9->addWidget(label_22);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_7->setObjectName("lineEdit_7");

        horizontalLayout_8->addWidget(lineEdit_7);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_15);


        verticalLayout_9->addLayout(horizontalLayout_8);

        label_23 = new QLabel(scrollAreaWidgetContents_4);
        label_23->setObjectName("label_23");

        verticalLayout_9->addWidget(label_23);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_15->setObjectName("lineEdit_15");

        horizontalLayout_10->addWidget(lineEdit_15);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);


        verticalLayout_9->addLayout(horizontalLayout_10);

        label_24 = new QLabel(scrollAreaWidgetContents_4);
        label_24->setObjectName("label_24");

        verticalLayout_9->addWidget(label_24);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lineEdit_16 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_16->setObjectName("lineEdit_16");

        horizontalLayout_11->addWidget(lineEdit_16);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_17);


        verticalLayout_9->addLayout(horizontalLayout_11);


        gridLayout_6->addLayout(verticalLayout_9, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_3->addWidget(scrollArea);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        pushButton_2 = new QPushButton(signal_tab);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_20->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_20);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(signal_tab, QString());
        station_tab = new QWidget();
        station_tab->setObjectName("station_tab");
        gridLayout_3 = new QGridLayout(station_tab);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        scrollArea_2 = new QScrollArea(station_tab);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 269));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_7->setObjectName("gridLayout_7");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName("label_25");

        verticalLayout_2->addWidget(label_25);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        lineEdit_17 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_17->setObjectName("lineEdit_17");

        horizontalLayout_23->addWidget(lineEdit_17);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName("label_26");

        horizontalLayout_23->addWidget(label_26);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_19);


        verticalLayout_2->addLayout(horizontalLayout_23);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        lineEdit_18 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_18->setObjectName("lineEdit_18");

        horizontalLayout_25->addWidget(lineEdit_18);

        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName("label_27");

        horizontalLayout_25->addWidget(label_27);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_20);


        verticalLayout_2->addLayout(horizontalLayout_25);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        lineEdit_19 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_19->setObjectName("lineEdit_19");

        horizontalLayout_24->addWidget(lineEdit_19);

        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName("label_28");

        horizontalLayout_24->addWidget(label_28);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_21);


        verticalLayout_2->addLayout(horizontalLayout_24);


        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 1, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea_2);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        pushButton_3 = new QPushButton(station_tab);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_21->addWidget(pushButton_3);


        verticalLayout_5->addLayout(horizontalLayout_21);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(station_tab, QString());
        object_tab = new QWidget();
        object_tab->setObjectName("object_tab");
        gridLayout_2 = new QGridLayout(object_tab);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        scrollArea_3 = new QScrollArea(object_tab);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 429, 269));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setObjectName("gridLayout_8");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_8 = new QLabel(scrollAreaWidgetContents_3);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(scrollAreaWidgetContents_3);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);

        label_2 = new QLabel(scrollAreaWidgetContents_3);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_3->addWidget(lineEdit_3);

        label_3 = new QLabel(scrollAreaWidgetContents_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        label_9 = new QLabel(scrollAreaWidgetContents_3);
        label_9->setObjectName("label_9");

        verticalLayout_4->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_4->addWidget(lineEdit_4);

        label_4 = new QLabel(scrollAreaWidgetContents_3);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_5->setObjectName("lineEdit_5");

        horizontalLayout_5->addWidget(lineEdit_5);

        label_5 = new QLabel(scrollAreaWidgetContents_3);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_6->setObjectName("lineEdit_6");

        horizontalLayout_6->addWidget(lineEdit_6);

        label_6 = new QLabel(scrollAreaWidgetContents_3);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        gridLayout_8->addLayout(verticalLayout_4, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pushButton = new QPushButton(object_tab);
        pushButton->setObjectName("pushButton");

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(object_tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setObjectName("gridLayout_5");
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        SimulatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimulatorWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 473, 21));
        SimulatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SimulatorWindow);
        statusbar->setObjectName("statusbar");
        SimulatorWindow->setStatusBar(statusbar);

        retranslateUi(SimulatorWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SimulatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SimulatorWindow)
    {
        SimulatorWindow->setWindowTitle(QCoreApplication::translate("SimulatorWindow", "SimulatorWindow", nullptr));
        label_10->setText(QCoreApplication::translate("SimulatorWindow", "Coordinates, m", nullptr));
        label_15->setText(QCoreApplication::translate("SimulatorWindow", "x", nullptr));
        label_12->setText(QCoreApplication::translate("SimulatorWindow", "y", nullptr));
        label_13->setText(QCoreApplication::translate("SimulatorWindow", "z", nullptr));
        label_14->setText(QCoreApplication::translate("SimulatorWindow", "Direction, m", nullptr));
        label_11->setText(QCoreApplication::translate("SimulatorWindow", "x", nullptr));
        label_16->setText(QCoreApplication::translate("SimulatorWindow", "y", nullptr));
        label_17->setText(QCoreApplication::translate("SimulatorWindow", "z", nullptr));
        label_21->setText(QCoreApplication::translate("SimulatorWindow", "Frequency, KGz", nullptr));
        label_22->setText(QCoreApplication::translate("SimulatorWindow", "Pulse Repetition Frequency, Gz", nullptr));
        label_23->setText(QCoreApplication::translate("SimulatorWindow", "Pulse Duration, sec", nullptr));
        label_24->setText(QCoreApplication::translate("SimulatorWindow", "Sample Frequency, Gz", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SimulatorWindow", "Apply", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(signal_tab), QCoreApplication::translate("SimulatorWindow", "Signal", nullptr));
        label_25->setText(QCoreApplication::translate("SimulatorWindow", "Coordinates, m", nullptr));
        label_26->setText(QCoreApplication::translate("SimulatorWindow", "x", nullptr));
        label_27->setText(QCoreApplication::translate("SimulatorWindow", "y", nullptr));
        label_28->setText(QCoreApplication::translate("SimulatorWindow", "z", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SimulatorWindow", "Apply", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(station_tab), QCoreApplication::translate("SimulatorWindow", "Station", nullptr));
        label_8->setText(QCoreApplication::translate("SimulatorWindow", "Coordinates, m", nullptr));
        label->setText(QCoreApplication::translate("SimulatorWindow", "x", nullptr));
        label_2->setText(QCoreApplication::translate("SimulatorWindow", "y", nullptr));
        label_3->setText(QCoreApplication::translate("SimulatorWindow", "z", nullptr));
        label_9->setText(QCoreApplication::translate("SimulatorWindow", "Velocity, m", nullptr));
        label_4->setText(QCoreApplication::translate("SimulatorWindow", "x", nullptr));
        label_5->setText(QCoreApplication::translate("SimulatorWindow", "y", nullptr));
        label_6->setText(QCoreApplication::translate("SimulatorWindow", "z", nullptr));
        pushButton->setText(QCoreApplication::translate("SimulatorWindow", "Apply", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(object_tab), QCoreApplication::translate("SimulatorWindow", "Object", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("SimulatorWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulatorWindow: public Ui_SimulatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORWINDOW_H
