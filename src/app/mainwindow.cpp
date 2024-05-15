#include "mainwindow.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QTimer>
#include <fstream>

#include "./ui_mainwindow.h"

void save_results(Object obj, std::shared_ptr<Field> field_for_results){

    std::string path = "C:/the-reflected-signal-simulator/src/results/" + obj.get_name() + ".txt";
    std::ofstream outFile(path);

    // Check if the file was opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        }

    outFile << "Name: " << obj.get_name() << "\n";
    outFile << "Start coordinates: (" << obj.get_coordinates().x <<", " << obj.get_coordinates().y<<", " << obj.get_coordinates().z<< ")\n";
    outFile << "Velocity: ("<< obj.get_velocity().x <<", " << obj.get_velocity().y<<", " << obj.get_velocity().z<< ")\n";
    outFile<< "t - time past" << "\n"<< "r - real"<< "\n"<< "p - predicted"<< "\n"<< "s - sigma" << "\n"<< "\n";

    double curr_x = obj.get_coordinates().x;
    double curr_y = obj.get_coordinates().y;
    double curr_z = obj.get_coordinates().z;

    for (int i = 0; i<1000; ++i){
        // Update position based on velocity
        curr_x += i*obj.get_velocity().x;
        curr_y += i*obj.get_velocity().y;
        curr_z += i*obj.get_velocity().z;

        outFile<<"t: "<< i << "\t" << "r: " <<curr_x << " " << curr_y << " " << curr_z << "\t";

        // Predicted location
        field_for_results->clear();
        Vector3D c = Vector3D(curr_x, curr_y, curr_z);
        Vector3D v = Vector3D(obj.get_velocity().x, obj.get_velocity().y, obj.get_velocity().z);

        Object new_obj = Object("name", v, c);
        field_for_results->add_object(new_obj);
        std::vector<Object> probed = field_for_results->probe();
        Object probed_obj = (*probed.begin());

        double sigma_x = (curr_x - probed_obj.get_coordinates().x)/curr_x;
        double sigma_y = (curr_y - probed_obj.get_coordinates().y)/curr_y;
        double sigma_z = (curr_z - probed_obj.get_coordinates().z)/curr_z;

        double sigma = sqrt(sigma_x * sigma_x + sigma_y * sigma_y + sigma_z * sigma_z)/3;

        outFile<<"p: " <<probed_obj.get_coordinates().x << " " << probed_obj.get_coordinates().y << " " << probed_obj.get_coordinates().z << "\t" <<"s: " << sigma <<"\n";
    }
    outFile.flush();
    outFile.close();

}

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
  field_for_results->enable_rls();

  // Load the image into a QPixmap
  QPixmap pixmap("C:/the-reflected-signal-simulator/src/graphics/graph.png");

  // Create a QLabel to display the pixmap
  QLabel* label = new QLabel;
  label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatioByExpanding));

  // Add the QLabel to the layout
  ui->gridLayout_for_graph->addWidget(label);
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

  // Load results to file
  save_results(object, field_for_results);

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
  predictionsGraph->setName("Predictions");

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
