#include "field.h"

Field::Field() : main_rls{nullptr}, objects{} {}

void Field::update(double delta_time) {
  std::for_each(
      objects.begin(), objects.end(),
      [delta_time](std::shared_ptr<Object> item) { item->update(delta_time); });
}

void Field::add_object(Object new_object) {
  objects.push_back(std::make_shared<Object>(new_object));
}

void Field::clear() { objects = {}; }

std::vector<Object> Field::getObjects() {
  std::vector<Object> result;
  for (auto iter = objects.begin(); iter != objects.end(); ++iter)
    result.push_back(**iter);
  return result;
}

void Field::enable_rls() { main_rls.setParent(this->shared_from_this()); }

std::ostream &operator<<(std::ostream &os,
                         std::vector<std::shared_ptr<Object>> const &obj) {
  os << "vvvvvvvvvvv--std::vector<std::shared_ptr<Object>>--vvvvvvvvvvv"
     << std::endl;
  for (auto i = obj.begin(); i != obj.end(); i++) os << *i << std::endl;
  os << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
     << std::endl;
  return os;
}
