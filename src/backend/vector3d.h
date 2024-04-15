#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D
{
public:
  double x, y, z;

  Vector3D ();

  Vector3D (int xx, int yy, int zz);

  Vector3D operator+ (const Vector3D other) const;

  Vector3D operator- (const Vector3D other) const;

  Vector3D & operator= (const Vector3D & v);
};

std::ostream & operator<< (std::ostream & os, const Vector3D & v);

#endif
