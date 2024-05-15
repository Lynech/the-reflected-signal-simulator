#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>

class Vector3D {
 public:
  double x, y, z;

  Vector3D();

  Vector3D(double xx, double yy, double zz);

  Vector3D(std::tuple<double, double, double> const &coords);

  Vector3D operator+(const Vector3D &other) const;

  Vector3D operator-(const Vector3D &other) const;

  Vector3D &operator=(const Vector3D &v);

  Vector3D &operator+=(const Vector3D &v);

  Vector3D operator*(const double &num) const;

  double getX() { return x; }

  double getY() { return y; }

  double getZ() { return z; }

  void setX(double x) { this->x = x; }

  void setY(double y) { this->y = y; }

  void setZ(double z) { this->z = z; }

  double lenght() { return pow(x * x + y * y + z * z, 0.5); }

  std::string string() const;

  void normalize();
};

Vector3D operator*(const double &num, const Vector3D &v);

std::ostream &operator<<(std::ostream &os, const Vector3D &v);

#endif