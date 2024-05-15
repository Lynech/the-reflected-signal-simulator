#include "vector3d.h"

Vector3D::Vector3D() {
  x = 0;
  y = 0;
  z = 0;
}
Vector3D::Vector3D(double xx, double yy, double zz) {
  x = xx;
  y = yy;
  z = zz;
}
Vector3D Vector3D::operator+(const Vector3D &other) const {
  Vector3D vec;
  vec.x = x + other.x;
  vec.y = y + other.y;
  vec.z = z + other.z;
  return vec;
}
Vector3D Vector3D::operator-(const Vector3D &other) const {
  Vector3D vec;
  vec.x = x - other.x;
  vec.y = y - other.y;
  vec.z = z - other.z;
  return vec;
}
Vector3D &Vector3D::operator=(const Vector3D &v) {
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
}

Vector3D &Vector3D::operator+=(const Vector3D &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector3D &v) {
  return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

void Vector3D::normalize() {
  double scale = sqrt(x * x + y * y + z * z);
  x /= scale;
  y /= scale;
  z /= scale;
}

Vector3D Vector3D::operator*(const double &num) const {
  Vector3D vec;
  vec.x = x * num;
  vec.y = y * num;
  vec.z = z * num;
  return vec;
}

Vector3D operator*(const double &num, const Vector3D &v) { return v * num; }

std::string Vector3D::string() const {
  return std::format("x={} y={} z={}", x, y, z);
}
Vector3D::Vector3D(std::tuple<double, double, double> const &coords) {
  x = std::get<0>(coords);
  y = std::get<1>(coords);
  z = std::get<2>(coords);
}
