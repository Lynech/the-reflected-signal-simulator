#ifndef OBJECT_H
#define OBJECT_H

#include <format>
#include <iostream>
#include <sstream>

#include "../vector3d/vector3d.h"

class Object {
 private:
  std::string name;
  Vector3D velocity;
  Vector3D coordinates;
  double effective_reflection_surface = 1;

 public:
  Object(const Object &o) {
    name = o.name;
    velocity = o.velocity;
    coordinates = o.coordinates;
    effective_reflection_surface = 1;
  }

  Object();

  Object(std::string n, Vector3D v, Vector3D c);

  std::string get_name() const { return name; }

  Vector3D get_velocity() const { return velocity; }

  Vector3D get_coordinates() const { return coordinates; }

  void set_velocity(Vector3D v) { velocity = v; }

  void set_coordinates(Vector3D c) { coordinates = c; }

  void set_velocity(double x, double y, double z) { velocity = {x, y, z}; }

  void set_coordinates(double x, double y, double z) {
    coordinates = {x, y, z};
  }

  void update(double time);
};

std::ostream &operator<<(std::ostream &os, const Object &obj);

#endif