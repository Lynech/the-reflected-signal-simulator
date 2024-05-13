#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QTimer>
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
    customPlot->axisRect()->insetLayout()->setInsetPlacement(0, QCPLayoutInset::ipFree);
    customPlot->legend->setVisible(true);

    // Plot can be resizable and scrollable
    customPlot->setInteraction(QCP::iRangeDrag, true);
    customPlot->setInteraction(QCP::iRangeZoom, true);

    ui->verticalLayout_scene->addWidget(customPlot);

    //unchangable station:
    stationGraph = customPlot->addGraph();
    stationGraph->setName("Station");

    stationGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond, QColor(255, 0, 0), QColor(255, 0, 0, 50), 20));
    stationGraph->addData(0, 0);
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

    object.set_coordinates(c_x, c_y, c_z);
    std::cout<<object << std::endl;


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

    object.set_velocity(v_x, v_y, v_z);
    std::cout<<object << std::endl;

    //if we had object on scene before
    {
        customPlot->removeGraph(objectGraph);
        customPlot->removeGraph(predictionsGraph);
    }
    objectGraph = customPlot->addGraph();
    objectGraph->setName("Object");


    objectGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QColor(255, 0, 0), QColor(255, 0, 0, 50), 10));
    objectGraph->addData(c_x, c_y);

    customPlot->replot();

    real_x = object.get_coordinates().x;
    real_y = object.get_coordinates().y;

    ui->pushButton_predict->setEnabled(true);
    ui->pushButton_pause_predict->setEnabled(false);
    ui->pushButton_stop_predict->setEnabled(false);

}

void MainWindow::on_pushButton_predict_clicked()
{
    predictionsGraph = customPlot->addGraph();
    predictionsGraph->setName("Predictions");


    predictionsGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, QColor(0, 255, 0), QColor(0, 255, 0, 50), 5));
    predictionsGraph->addData(object.get_coordinates().x, object.get_coordinates().y);

    customPlot->replot();

    connect(&updateTimer, &QTimer::timeout, this, &MainWindow::updateDotPosition);
    if (!updateTimer.isActive()){
        updateTimer.start(1000); // Update every 1000 ms
        timer_active = true;
    }

    ui->pushButton_predict->setEnabled(false);
    ui->pushButton_pause_predict->setEnabled(true);
    ui->pushButton_stop_predict->setEnabled(true);
}

void MainWindow::updateDotPosition() {

    // Update position based on velocity
    real_x += object.get_velocity().x;
    real_y += object.get_velocity().y;

    // Update the dot's position
    predictionsGraph->addData(real_x, real_y);

    // Redraw the plot
    customPlot->replot();
}



void MainWindow::on_pushButton_pause_predict_clicked()
{
    if (timer_active) {
        updateTimer.stop(); // Stop the timer if it's currently running
        timer_active = false;
        timer_paused = true;
    } else {
        updateTimer.start(1000); // Start the timer with an interval of 1000 ms if it's not running
        timer_active = true;
    }

    ui->pushButton_predict->setEnabled(false);
    ui->pushButton_pause_predict->setEnabled(true);
    ui->pushButton_stop_predict->setEnabled(true);
}


void MainWindow::on_pushButton_stop_predict_clicked()
{
    if (timer_active or timer_paused){
        updateTimer.stop();
        if (predictionsGraph){
            predictionsGraph->data()->clear();
        }
        // Reset static variables to their initial values
        real_x = object.get_coordinates().x;
        real_y = object.get_coordinates().y;

        timer_active = false;

        customPlot->replot();
    }

    ui->pushButton_predict->setEnabled(true);
    ui->pushButton_pause_predict->setEnabled(false);
    ui->pushButton_stop_predict->setEnabled(false);

}

