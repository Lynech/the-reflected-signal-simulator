#ifndef RLS_H
#ifndef FIELD_H
#define RLS_H
#define FIELD_H
// #include "../field/field.h"
#include "../object/object.h"
#include "../signal/signal.h"
#include "../vector3d/vector3d.h"
#include <memory>
#include <optional>
#include <tuple>
#include <vector>
class Field;

class Rls {
private:
  // emitter {antenna, coordinates}
  // receiver {antenna, coordinates}
  // int amplitude{1};
  // double time1;
  // double time2;
  std::weak_ptr<Field> parent;

  // Signal radiate_signal(double power ...);
  Signal radiate_signal();

public:
  void setParent(std::weak_ptr<Field> parent);
  std::vector<std::shared_ptr<Object>> probe();

  Rls(std::shared_ptr<Field> const &parent_);
  ~Rls() = default;
};

class Field : public std::enable_shared_from_this<Field> {
private:
  Rls main_rls;
  // Object obgects;
  std::vector<std::shared_ptr<Object>> objects;
  //   std::vector<std::shared_ptr<Signal>> signals;


public:
  //   void update();
  Field();
  void enable_rls();
  void add_object(Object *new_object);
  void add_object(Object const &new_object);
  void add_object(std::shared_ptr<Object> const &new_object);
  void clear();

  std::vector<std::shared_ptr<Object>> probe() { return main_rls.probe(); }

  std::vector<std::shared_ptr<Object>> getObjects();
  // Signal& radiate_signal();
  void update(double delta_time);
};

std::ostream &operator<<(std::ostream &os,
                         std::vector<std::shared_ptr<Object>> const &obj);

#endif
#endif
