#include "field.h"

std::optional<Signal> Field::radiate_signal(double v, double d) {
  std::optional<Signal> result = std::nullopt;
  if (v > obgects.get_velocity()) {
    result =
        Signal{v, d - d / (v / obgects.get_velocity() - 1),
               2 * obgects.get_coordinates() / (v + obgects.get_velocity())};
  }
  return result;
}
Field::Field(double c = 100, double v = 0)
    : obgects{"name", v, c}, main_rls{std::shared_ptr<Field>(this)} {}

void Field::update(double delta_time) {
  std::cout << "predicted object: "
            << main_rls.probe().value_or(Object{"not found", 0, 0})
            << std::endl;
  std::cout << "real object: " << obgects << std::endl;
  obgects.update(delta_time);
}