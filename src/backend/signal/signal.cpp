#include "signal.h"

void Signal::reflectedObjects(std::vector<Object> &objects) {
  std::random_device rd;
  std::mt19937 g(rd());
  for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
    auto mean = iter->get_coordinates();
    double r = mean.lenght() * 0.0005;
    std::normal_distribution<double> d{0, r};
    mean.setX(mean.getX() + d(g));
    mean.setY(mean.getY() + d(g));
    mean.setY(mean.getY() + d(g));
    iter->set_coordinates(mean);
  }

  objects_probed = objects;
}
std::vector<Object> Signal::getReflectionInfo() { return objects_probed; }