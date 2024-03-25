#include "object.h"

Object::Object() {
  name = "name";
  velocity = 0;
  coordinates = 0;
}

Object::Object(std::string n, double v, double c) {
  name = n;
  velocity = v;
  coordinates = c;
}

// Object::Object (std::string n, int x, int y, int z, int v_x, int v_y, int
// v_z)
//   {
//   name = n;
//   velocity = Vector3D (v_x, v_y, v_z);
//   coordinates = Vector3D (x, y, z);
//   }

void Object::update(double time) { coordinates += time * velocity; }

// void Object::update (double time)
//   {
//   coordinates.x += time * velocity.x;
//   coordinates.y += time * velocity.y;
//   coordinates.z += time * velocity.z;
//   }

std::ostream &operator<<(std::ostream &os, const Object &obj) {
  // return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return os << "name: " << obj.get_name() << "\n"
            << "coordinates: " << obj.get_coordinates() << "\n"
            << "velocity: " << obj.get_velocity() << "\n";
}