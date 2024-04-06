#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SimulatorWindow;
}
QT_END_NAMESPACE

class SimulatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    SimulatorWindow(QWidget *parent = nullptr);
    ~SimulatorWindow();

private:
    Ui::SimulatorWindow *ui;
};
#endif // SIMULATORWINDOW_H
