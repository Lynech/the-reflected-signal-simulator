#include "mainwindow.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QTimer>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  const int maxCoordX = 99;
  const int maxCoordY = 99;
  const int maxCoordZ = 99;

  ui->setupUi(this);

  QLocale lo(QLocale::C);  // Use the C locale as a base
  lo.setNumberOptions(
      QLocale::RejectGroupSeparator);  // Reject commas as group separators
  QDoubleValidator *validator =
      new QDoubleValidator(-100.0, 100.0, 2);  // Set the range and decimals
  validator->setLocale(lo);  // Apply the modified locale to the validator

  ui->lineEdit_object_coord_x->setValidator(validator);
  ui->lineEdit_object_coord_y->setValidator(validator);
  ui->lineEdit_object_coord_z->setValidator(validator);

  ui->lineEdit_object_vel_x->setValidator(validator);
  ui->lineEdit_object_vel_y->setValidator(validator);
  ui->lineEdit_object_vel_z->setValidator(validator);

  ui->lineEdit_signal_direct_x->setValidator(validator);
  ui->lineEdit_signal_direct_y->setValidator(validator);
  ui->lineEdit_signal_direct_z->setValidator(validator);

  customPlot = new QCustomPlot(this);
  customPlot->xAxis->setRange(0, 100);
  customPlot->yAxis->setRange(0, 100);

  // Customize the legend's appearance
  customPlot->legend->setFont(QFont("Arial", 5));
  customPlot->legend->setIconSize(QSize(20, 20));
  // Move the legend to the right corner of the plot area
  customPlot->legend->setOuterRect(customPlot->axisRect()->outerRect());
  customPlot->axisRect()->insetLayout()->setInsetPlacement(
      0, QCPLayoutInset::ipFree);
  customPlot->legend->setVisible(true);

  // Plot can be resizable and scrollable
  customPlot->setInteraction(QCP::iRangeDrag, true);
  customPlot->setInteraction(QCP::iRangeZoom, true);

  // Add names of axis
  customPlot->xAxis->setLabel("X");
  customPlot->yAxis->setLabel("Y");

  ui->verticalLayout_scene->addWidget(customPlot);

  // unchangable station:
  stationGraph = customPlot->addGraph();
  stationGraph->setName("Station");

  stationGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDiamond,
                                                QColor(255, 0, 0),
                                                QColor(255, 0, 0, 50), 20));
  stationGraph->addData(0, 0);

  field->enable_rls();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_apply_object_clicked() {
  // If prediction already loaded
  updateTimer.stop();
  timer_active = false;

  ui->pushButton_predict->setEnabled(true);
  ui->pushButton_pause_predict->setEnabled(false);
  ui->pushButton_stop_predict->setEnabled(false);

  // Set coords to object
  double c_x;
  c_x = (ui->lineEdit_object_coord_x->text().toDouble());
  ui->lineEdit_object_coord_x->setText(QString::number(c_x));

  double c_y;
  c_y = (ui->lineEdit_object_coord_y->text().toDouble());
  ui->lineEdit_object_coord_y->setText(QString::number(c_y));

  double c_z;
  c_z = (ui->lineEdit_object_coord_z->text().toDouble());
  ui->lineEdit_object_coord_z->setText(QString::number(c_z));

  object.set_coordinates(c_x, c_y, c_z);
  std::cout << object << std::endl;

  // Set velocity to object
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
  std::cout << object << std::endl;

  // If we had object on scene added before
  {
    customPlot->removeGraph(objectGraph);
    customPlot->removeGraph(objectMovesGraph);
    customPlot->removeGraph(predictionsGraph);
  }

  // Add object on the plot
  objectGraph = customPlot->addGraph();
  objectGraph->setName("Object");

  objectGraph->setScatterStyle(QCPScatterStyle(
      QCPScatterStyle::ssDisc, QColor(255, 0, 0), QColor(255, 0, 0, 50), 10));
  objectGraph->addData(c_x, c_y);

  customPlot->replot();

  real_x = object.get_coordinates().x;
  real_y = object.get_coordinates().y;

  ui->pushButton_predict->setEnabled(true);
  ui->pushButton_pause_predict->setEnabled(false);
  ui->pushButton_stop_predict->setEnabled(false);

  // Add object to backend
  field->clear();
  field->add_object(object);
}

void MainWindow::on_pushButton_predict_clicked() {
  // Object moves added
  objectMovesGraph = customPlot->addGraph();
  objectMovesGraph->setName("Object moves");

  objectMovesGraph->setScatterStyle(QCPScatterStyle(
      QCPScatterStyle::ssDisc, QColor(255, 0, 0), QColor(0, 255, 0, 50), 5));
  objectMovesGraph->addData(object.get_coordinates().x,
                            object.get_coordinates().y);

  // Predicted moves added
  predictionsGraph = customPlot->addGraph();
  predictionsGraph->setName("Predi  ctions");

  predictionsGraph->setScatterStyle(QCPScatterStyle(
      QCPScatterStyle::ssDisc, QColor(0, 255, 0), QColor(0, 255, 0, 50), 5));
  std::vector<Object> probed = field->probe();
  Object probed_obj = (*probed.begin());
  predictionsGraph->addData(probed_obj.get_coordinates().x,
                            probed_obj.get_coordinates().y);

  customPlot->replot();

  if (!timer_connected) {
    connect(&updateTimer, &QTimer::timeout, this,
            &MainWindow::updateDotPosition);
    timer_connected = true;
  }
  if (!updateTimer.isActive()) {
    updateTimer.start(1000);  // Update every 1000 ms
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

  // Predicted location
  field->update(1);
  std::vector<Object> probed = field->probe();
  Object probed_obj = (*probed.begin());
  predictionsGraph->addData(probed_obj.get_coordinates().x,
                            probed_obj.get_coordinates().y);

  // Update the dot's position
  objectMovesGraph->addData(real_x, real_y);

  // Redraw the plot
  customPlot->replot();
}

void MainWindow::on_pushButton_pause_predict_clicked() {
  if (timer_active) {
    updateTimer.stop();  // Stop the timer if it's currently running
    timer_active = false;
    timer_paused = true;
  } else {
    updateTimer.start(1000);  // Start the timer with an interval of 1000 ms if
                              // it's not running
    timer_active = true;
  }

  ui->pushButton_predict->setEnabled(false);
  ui->pushButton_pause_predict->setEnabled(true);
  ui->pushButton_stop_predict->setEnabled(true);
}

void MainWindow::on_pushButton_stop_predict_clicked() {
  if (timer_active or timer_paused) {
    updateTimer.stop();
    if (objectMovesGraph) {
      objectMovesGraph->data()->clear();
      customPlot->removeGraph(objectMovesGraph);
      customPlot->removeGraph(predictionsGraph);
    }
    // Reset static variables to their initial values
    real_x = object.get_coordinates().x;
    real_y = object.get_coordinates().y;

    timer_active = false;

    customPlot->replot();
  }

  // Old object to field
  field->clear();
  field->add_object(object);

  ui->pushButton_predict->setEnabled(true);
  ui->pushButton_pause_predict->setEnabled(false);
  ui->pushButton_stop_predict->setEnabled(false);
}

void MainWindow::on_pushButton_apply_noise_clicked() {
  double n;
  n = (ui->lineEdit_noise->text().toDouble());
  ui->lineEdit_noise->setText(QString::number(n));
  noise = n;
}
