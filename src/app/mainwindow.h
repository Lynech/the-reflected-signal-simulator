#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include "grid_widget.h"


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

private:
    Ui::MainWindow *ui;
    Object obj;
    Grid* grid= new Grid;
}   ;
#endif // MAINWINDOW_H
