#ifndef OBJECT_H
#define OBJECT_H

#include "../vector3d/vector3d.h"
#include <iostream>
#include <format>
#include <sstream>

class Object {
private:
  std::string name;
  // double velocity;
  Vector3D velocity;
  Vector3D  coordinates;
  // double coordinates;
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

  // Object(std::string n, int x, int y, int z, int v_x, int v_y, int v_z);

  std::string get_name() const { return name; }

  Vector3D get_velocity() const { return velocity; }

  Vector3D get_coordinates() const { return coordinates; }

  void update(double time);
};

std::ostream &operator<<(std::ostream &os, const Object &obj);

#endif