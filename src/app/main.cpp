#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  Object obj;
  std::cout << obj << std::endl;
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
