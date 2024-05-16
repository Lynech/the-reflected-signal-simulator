#include "rls.h"

std::vector<Object> Rls::probe() {
  std::vector<Object> obgects;
  auto signal = radiate_signal();
  obgects = signal.getReflectionInfo();
  return obgects;
}

Rls::Rls(std::shared_ptr<Field> const &parent_) : parent{parent_} {};

Signal Rls::radiate_signal() {
  auto objects = parent.lock()->getObjects();
  Signal result;
  result.reflectedObjects(objects);
  return result;
}

void Rls::setParent(std::weak_ptr<Field> parent) { this->parent = parent; }
