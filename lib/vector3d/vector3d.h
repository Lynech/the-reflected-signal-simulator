#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>

class Vector3D
{
public:
  double x, y, z;

  Vector3D ();

  Vector3D (double xx, double yy, double zz);

  Vector3D operator+ (const Vector3D other) const;

  Vector3D operator- (const Vector3D other) const;

  Vector3D & operator= (const Vector3D & v);

  void normalize();
};

std::ostream & operator<< (std::ostream & os, const Vector3D & v);

#endif