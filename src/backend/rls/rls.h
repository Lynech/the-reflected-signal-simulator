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

class Rls {
 private:
  std::weak_ptr<Field> parent;

  Signal radiate_signal();

 public:
  void setParent(std::weak_ptr<Field> parent);
  std::vector<Object> probe();

  Rls(std::shared_ptr<Field> const &parent_);
  ~Rls() = default;
};

class Field : public std::enable_shared_from_this<Field> {
 private:
  Rls main_rls;
  std::vector<std::shared_ptr<Object>> objects;

 public:
  Field();
  void enable_rls();
  void add_object(Object new_object);
  void clear();

  std::vector<Object> probe() { return main_rls.probe(); }

  std::vector<Object> getObjects();
  void update(double delta_time);
};

std::ostream &operator<<(std::ostream &os, std::vector<Object> const &obj);

#endif
#endif
