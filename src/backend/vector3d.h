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

    // Vector3D(double xx, double yy, double zz);

    Vector3D(std::tuple<double, double, double> const &coords);

    Vector3D operator+(const Vector3D &other) const;

    Vector3D operator-(const Vector3D &other) const;

    Vector3D &operator=(const Vector3D &v);

    Vector3D &operator+=(const Vector3D &v);

    Vector3D operator*(const double &num) const;

    std::string string() const;

    void normalize();
};

Vector3D operator*(const double &num, const Vector3D &v);

std::ostream &operator<<(std::ostream &os, const Vector3D &v);

#endif
