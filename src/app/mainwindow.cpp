#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include "grid_widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const int maxCoordX = 99;
    const int maxCoordY = 99;
    const int maxCoordZ = 99;

    ui->setupUi(this);

    // if cords are not only int:
    // ui->lineEdit_object_coord_x->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));

    ui->lineEdit_object_coord_x->setValidator(new QIntValidator(0, maxCoordX, this));
    ui->lineEdit_object_coord_y->setValidator(new QIntValidator(0, maxCoordY, this));
    ui->lineEdit_object_coord_z->setValidator(new QIntValidator(0, maxCoordZ, this));

    ui->lineEdit_object_vel_x->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));
    ui->lineEdit_object_vel_y->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));
    ui->lineEdit_object_vel_z->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));

    ui->lineEdit_station_coord_x->setValidator(new QIntValidator(0, maxCoordX, this));
    ui->lineEdit_station_coord_y->setValidator(new QIntValidator(0, maxCoordY, this));
    ui->lineEdit_station_coord_z->setValidator(new QIntValidator(0, maxCoordZ, this));

    ui->lineEdit_signal_coord_x->setValidator(new QIntValidator(0, maxCoordX, this));
    ui->lineEdit_signal_coord_y->setValidator(new QIntValidator(0, maxCoordY, this));
    ui->lineEdit_signal_coord_z->setValidator(new QIntValidator(0, maxCoordZ, this));

    ui->lineEdit_signal_direct_x->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));
    ui->lineEdit_signal_direct_y->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));
    ui->lineEdit_signal_direct_z->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]*"), this));


    customPlot = new QCustomPlot(this);
    customPlot->xAxis->setRange(0, 100);
    customPlot->yAxis->setRange(0, 100);

    // Customize the legend's appearance
    customPlot->legend->setFont(QFont("Arial", 5));
    customPlot->legend->setIconSize(QSize(20, 20));
    // Move the legend to the top right corner of the plot area
    customPlot->legend->setOuterRect(customPlot->axisRect()->outerRect());
    customPlot->axisRect()->insetLayout()->setInsetPlacement(100, QCPLayoutInset::ipFree);
    customPlot->legend->setVisible(true);

// Plot can be resizable and scrollable
    customPlot->setInteraction(QCP::iRangeDrag, true);
    customPlot->setInteraction(QCP::iRangeZoom, true);

    ui->verticalLayout_scene->addWidget(customPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_apply_object_clicked()
{
    // set coords to object
    int c_x;
    c_x = (ui->lineEdit_object_coord_x->text().toInt());
    ui->lineEdit_object_coord_x->setText(QString::number(c_x));

    int c_y;
    c_y = (ui->lineEdit_object_coord_y->text().toInt());
    ui->lineEdit_object_coord_y->setText(QString::number(c_y));

    int c_z;
    c_z = (ui->lineEdit_object_coord_z->text().toInt());
    ui->lineEdit_object_coord_z->setText(QString::number(c_z));

    obj.set_coordinates(c_x, c_y, c_z);
    std::cout<<obj << std::endl;


    // // set velocity to object
    double v_x;
    v_x = (ui->lineEdit_object_vel_x->text().toDouble());
    ui->lineEdit_object_vel_x->setText(QString::number(v_x));

    double v_y;
    v_y = (ui->lineEdit_object_vel_y->text().toDouble());
    ui->lineEdit_object_vel_y->setText(QString::number(v_y));

    double v_z;
    v_z = (ui->lineEdit_object_vel_z->text().toDouble());
    ui->lineEdit_object_vel_z->setText(QString::number(v_z));

    obj.set_velocity(v_x, v_y, v_z);
    std::cout<<obj << std::endl;

    //if we had object on scene before
    if (objectGraph){
        customPlot->removeGraph(objectGraph);
    }
    objectGraph = customPlot->addGraph();
    objectGraph->setName("Object");


    objectGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QColor(255, 0, 0), QColor(255, 0, 0, 50), 10));
    objectGraph->addData(c_x, c_y);

    customPlot->replot();
}
