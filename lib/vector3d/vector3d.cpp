#include "vector3d.h"

Vector3D::Vector3D ()
  {
  x = 0;
  y = 0;
  z = 0;
  }
Vector3D::Vector3D (double xx, double yy, double zz)
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
    if (this == &v)
        return *this;
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
  }

std::ostream & operator<< (std::ostream & os, const Vector3D & v)
{
  return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  
}

void Vector3D::normalize(){
  double scale = sqrt(x*x + y*y + z*z);
  x /= scale;
  y /= scale;
  z /= scale;
}