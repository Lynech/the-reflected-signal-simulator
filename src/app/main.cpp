#include "mainwindow.h"
#include "object.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Object obj;
    std::cout << obj << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
