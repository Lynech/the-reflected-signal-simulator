#ifndef OBJECT_H
#define OBJECT_H

#include "../vector3d/vector3d.h"
#include <iostream>

class Object {
private:
  std::string name;
  double velocity;
  double coordinates;
  double size = 1;

public:
  Object(const Object &o) {
    name = o.name;
    velocity = o.velocity;
    coordinates = o.coordinates;
    size = 1;
  }

  Object();

  Object(std::string n, double v, double c);

  // Object(std::string n, int x, int y, int z, int v_x, int v_y, int v_z);

  std::string get_name() const { return name; }

  double get_velocity() const { return velocity; }

  double get_coordinates() const { return coordinates; }

  void update(double time);
};

std::ostream &operator<<(std::ostream &os, const Object &obj);

#endif