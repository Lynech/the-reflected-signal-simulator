#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>

/// @brief  Класс для 3-х мерного вектора
class Vector3D {
 public:
  double x, y, z;
  /// @brief  Конструктор по умолчанию
  Vector3D();
  /// @brief Конструктор
  /// @param xx x координата
  /// @param yy y координата
  /// @param zz z координата
  Vector3D(double xx, double yy, double zz);
  /// @brief Конструктор
  /// @param coords координаты в тупле
  Vector3D(std::tuple<double, double, double> const &coords);
  /// @brief перегруженный оператор +
  /// @param other другой вектор
  /// @return возвращает сумму
  Vector3D operator+(const Vector3D &other) const;
  /// @brief перегруженный оператор -
  /// @param other другой вектор
  /// @return возвращает разность
  Vector3D operator-(const Vector3D &other) const;
  /// @brief перегруженный оператор присваивания
  /// @param other другой вектор
  /// @return возвращает ссылку на текущий вектор
  Vector3D &operator=(const Vector3D &other);
  /// @brief перегруженный оператор +=
  /// @param other другой вектор
  /// @return возвращает ссылку на текущий вектор
  Vector3D &operator+=(const Vector3D &other);

  /// @brief перегруженный оператор *
  /// @param num число
  /// @return возвращает копию вектора
  Vector3D operator*(const double &num) const;
  /// @brief гетер x
  /// @return возвращает x
  double getX() { return x; }
  /// @brief герет y
  /// @return возвращает y
  double getY() { return y; }
  /// @brief гетер z
  /// @return возвращает z
  double getZ() { return z; }
  /// @brief сетер x
  /// @param x значение x
  void setX(double x) { this->x = x; }
  /// @brief сетер y
  /// @param y значение y
  void setY(double y) { this->y = y; }
  /// @brief сетер z
  /// @param z значение z
  void setZ(double z) { this->z = z; }
  /// @brief длина вектора
  /// @return длину вектора
  double lenght() { return pow(x * x + y * y + z * z, 0.5); }
  /// @brief преодразование вектора в строку
  /// @return строка вида "x={} y={} z={}"
  std::string string() const;
  /// @brief нормализирует вектор
  void normalize();
};
/// @brief перегруженный оператор для умножения на число в другом порядке
/// @param num число
/// @param v вектор
/// @return результат умножения
Vector3D operator*(const double &num, const Vector3D &v);
/// @brief перегруженный оператор для вывода
/// @param os поток
/// @param v вектор
/// @return поток
std::ostream &operator<<(std::ostream &os, const Vector3D &v);

#endif