#include "vector3d.h"

Vector3D::Vector3D ()
  {
  x = 0;
  y = 0;
  z = 0;
  }
Vector3D::Vector3D (int xx, int yy, int zz)
  {
  x = xx;
  y = yy;
  z = zz;
  }
Vector3D Vector3D::operator+ (const Vector3D other) const
  {
  Vector3D vec;
    vec.x = x + other.x;
    vec.y = y + other.y;
    vec.z = z + other.z;
    return vec;
  }
Vector3D Vector3D:: operator- (const Vector3D other) const
  {
  Vector3D vec;
    vec.x = x - other.x;
    vec.y = y - other.y;
    vec.z = z - other.z;
    return vec;
  }
Vector3D& Vector3D::operator= (const Vector3D & v)
  {
  x = v.x;
  y = v.y;
  z = v.z;
  //  return this;
  }

std::ostream & operator<< (std::ostream & os, const Vector3D & v)
{
  os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return os;
}