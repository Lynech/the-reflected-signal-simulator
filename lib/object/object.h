#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "../vector3d/vector3d.h"

class Object
{
private:
  std::string name;
  Vector3D velocity;
  Vector3D coordinates;

public:
  Object ();

  Object (std::string n, Vector3D c, Vector3D v);

  Object (std::string n, int x, int y, int z, int v_x, int v_y, int v_z);

  std::string get_name ()const {return name;}

  Vector3D get_velocity () const {return velocity;}
  
  Vector3D get_coordinates () const {return coordinates;}

  void update (double time);

};

std::ostream & operator<< (std::ostream & os, const Object obj);

#endif