#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include "grid_widget.h"
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_apply_object_clicked();

    void on_pushButton_predict_clicked();

    void updateDotPosition();

    void on_pushButton_pause_predict_clicked();

    void on_pushButton_stop_predict_clicked();

private:
    Ui::MainWindow *ui;
    Object object;
    double real_x;
    double real_y;

    // Grid* grid= new Grid;
    QCustomPlot *customPlot;

    QCPGraph *objectGraph;

    QCPGraph *stationGraph;

    QCPGraph *predictionsGraph;

    QTimer updateTimer;

    bool timer_active = false;
    bool timer_paused = false;



}   ;
#endif // MAINWINDOW_H
