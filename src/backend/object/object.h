#ifndef OBJECT_H
#define OBJECT_H

#include <format>
#include <iostream>
#include <sstream>

#include "../vector3d/vector3d.h"
/// @brief Класс объект
class Object {
 private:
  std::string name;
  Vector3D velocity;
  Vector3D coordinates;
  double effective_reflection_surface = 1;

 public:
  /// @brief конструктор присваивания
  /// @param o другой объект
  Object(const Object &o) {
    name = o.name;
    velocity = o.velocity;
    coordinates = o.coordinates;
    effective_reflection_surface = 1;
  }
  /// @brief конструктор по умолчанию
  Object();
  /// @brief конструктор
  /// @param n имя объекта
  /// @param v вектор скорости
  /// @param c вектор координат
  Object(std::string n, Vector3D v, Vector3D c);
  /// @brief гетер имени
  /// @return имя
  std::string get_name() const { return name; }
  /// @brief гетер скорости
  /// @return скорость
  Vector3D get_velocity() const { return velocity; }
  /// @brief гетер координат
  /// @return координаты
  Vector3D get_coordinates() const { return coordinates; }
  /// @brief сетер скорости
  /// @param v скорость
  void set_velocity(Vector3D v) { velocity = v; }
  /// @brief сетер координат
  /// @param c координаты
  void set_coordinates(Vector3D c) { coordinates = c; }
  /// @brief сетер скорости покоординатный
  /// @param x скорость по x
  /// @param y скорость по y
  /// @param z скорость по z
  void set_velocity(double x, double y, double z) { velocity = {x, y, z}; }
  /// @brief сетер координат покоординатный
  /// @param x координата x
  /// @param y координата y
  /// @param z координата z
  void set_coordinates(double x, double y, double z) {
    coordinates = {x, y, z};
  }
  /// @brief обновляет положение объекта с учетом направления движения
  /// @param time время пройденное с последнего обновления
  void update(double time);
};
/// @brief перегруженный оператор << вывода в поток
/// @param os поток
/// @param obj объект
/// @return поток
std::ostream &operator<<(std::ostream &os, const Object &obj);

#endif