#include "rls.h"

std::vector<Object> Rls::probe() {
  std::vector<Object> obgects;
  auto signal = radiate_signal();
  obgects = signal.ProbedObjects();
  return obgects;
}

Rls::Rls(std::shared_ptr<Field> const &parent_) : parent{parent_} {};

Signal Rls::radiate_signal() {
  auto objects = parent.lock()->getObjects();
  {
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
  }
  Signal result;
  result.SetObgects(objects);
  return result;
}

void Rls::setParent(std::weak_ptr<Field> parent) { this->parent = parent; }
