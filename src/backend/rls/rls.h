#ifndef RLS_H
#ifndef FIELD_H
#define RLS_H
#define FIELD_H
#include <algorithm>
#include <memory>
#include <optional>
#include <random>
#include <tuple>
#include <vector>

#include "../field/field.h"
#include "../object/object.h"
#include "../signal/signal.h"
#include "../vector3d/vector3d.h"
class Field;
/// @brief Класс Радиолокационной станции
class Rls {
 private:
  std::weak_ptr<Field> parent;

  Signal radiate_signal();

 public:
  /// @brief сетер менеджера моделирования
  /// @param parent менеджер моделирования
  void setParent(std::weak_ptr<Field> parent);
  /// @brief функция "сканирования", "зондирования"
  /// @return вычисленное положение и скорости объектов
  std::vector<Object> probe();
  /// @brief конструктор
  /// @param parent_ менеджер моделирования
  Rls(std::shared_ptr<Field> const &parent_);
  /// @brief конструктор по умолчанию
  ~Rls() = default;
};
/// @brief Класс менеджера моделирования
class Field : public std::enable_shared_from_this<Field> {
 private:
  Rls main_rls;
  std::vector<std::shared_ptr<Object>> objects;

 public:
  /// @brief конструктор по умолчанию
  Field();
  /// @brief подключает радиолокационную станцию к менеджеру
  void enable_rls();
  /// @brief добавляет новый объект в моделирование
  /// @param new_object новый объект
  void add_object(Object new_object);
  /// @brief отчищает модель и все объекты
  void clear();
  /// @brief функция сканирования
  /// @return вычисленные положения объектов
  std::vector<Object> probe() { return main_rls.probe(); }
  /// @brief гетер объктов
  /// @return объекты моделирования
  std::vector<Object> getObjects();
  /// @brief обновляет положения всех объектов моделирования
  /// @param delta_time время, пройденное с последнего моделирования
  void update(double delta_time);
};

std::ostream &operator<<(std::ostream &os, std::vector<Object> const &obj);

#endif
#endif
