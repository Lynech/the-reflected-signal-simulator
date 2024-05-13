#include "rls.h"

std::vector<std::shared_ptr<Object>> Rls::probe() {
  std::vector<std::shared_ptr<Object>> obgects;
  // double d = 0.1;
  // double v = 50;
  auto signal = radiate_signal();
  obgects = signal.ProbedObjects();
  return obgects;
}

Rls::Rls(std::shared_ptr<Field> const &parent_) : parent{parent_} {};

Signal Rls::radiate_signal() {
  auto objects = parent.lock()->getObjects();
  {
    // в этом блоке должно быть ъ
    // математическое моделирование погрешностей
  }
  Signal result;
  result.SetObgects(objects);
  return result;
}

void Rls::setParent(std::weak_ptr<Field> parent) { this->parent = parent; }