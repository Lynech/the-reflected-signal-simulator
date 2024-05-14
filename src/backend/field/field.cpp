#include "field.h"
#include <algorithm>

// std::optional<Signal> Field::radiate_signal(double v, double d) {
//   std::optional<Signal> result = std::nullopt;
//   if (v > obgects.get_velocity()) {
//     result =
//         Signal{v, d - d / (v / obgects.get_velocity() - 1),
//                2 * obgects.get_coordinates() / (v + obgects.get_velocity())};
//   }
//   return result;
// }

Field::Field() : main_rls{nullptr}, objects{} {}

void Field::update(double delta_time) {
  // std::cout << "predicted object: "
  //           << main_rls.probe().value_or(Object{"not found", 0, 0})
  //           << std::endl;
  // std::cout << "real object: " << obgects << std::endl;
  std::for_each(
      objects.begin(), objects.end(),
      [delta_time](std::shared_ptr<Object> item) { item->update(delta_time); });
}

void Field::add_object(Object *new_object) {
  add_object(std::shared_ptr<Object>(new_object));
}
void Field::add_object(Object const &new_object) {
  add_object(std::make_shared<Object>(new_object));
}
void Field::add_object(std::shared_ptr<Object> const &new_object) {
  objects.push_back(new_object);
}

// void Field::add_object(Object const * new_object);
// void Field::add_object(Object const & new_object);
std::vector<std::shared_ptr<Object>> Field::getObjects() { return objects; }

void Field::enable_rls() { main_rls.setParent(this->shared_from_this()); }


std::ostream &operator<<(std::ostream &os,
                         std::vector<std::shared_ptr<Object>> const &obj) {
  os << "vvvvvvvvvvv--std::vector<std::shared_ptr<Object>>--vvvvvvvvvvv"
     << std::endl;
  for (auto i = obj.begin(); i != obj.end(); i++)
    os << *(*i) << std::endl;
  os << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
     << std::endl;
  return os;
}