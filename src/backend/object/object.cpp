#include "object.h"

#include <format>
#include <string>

Object::Object() {
  static int count = 1;
  name = "name" + std::to_string(count);
  velocity = {0, 0, 0};
  coordinates = {0, 0, 0};
  count++;
}

Object::Object(std::string n, Vector3D v, Vector3D c) {
  name = n;
  velocity = v;
  coordinates = c;
}

void Object::update(double time) { coordinates += time * velocity; }

std::ostream &operator<<(std::ostream &os, const Object &obj) {
  return os << "name: " << obj.get_name()
            << "\ncoordinates: " << obj.get_coordinates()
            << "\nvelocity:" << obj.get_velocity();
}