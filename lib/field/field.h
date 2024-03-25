#ifndef FIELD_H
#ifndef RLS_H
#define FIELD_H
#define RLS_H
#include "../object/object.h"
// #include "../rls/rls.h"
#include "../signal/signal.h"
#include <memory>
#include <optional>
#include <vector>
class Rls;

class Field {
private:
  Rls main_rls;
  Object obgects;
  //   std::vector<std::shared_ptr<Signal>> signals;

public:
  //   void update();
  Field(double, double);
  std::optional<Signal> radiate_signal(double v, double d);
  void update(double delta_time);
};

class Rls {
private:
  // emitter {antenna, coordinates}
  // receiver {antenna, coordinates}
  // int amplitude{1};
  // double time1;
  // double time2;
  std::shared_ptr<Field> parent;

public:
  std::optional<Object> probe();

  Rls(std::shared_ptr<Field> parent_);
  ~Rls() = default;
};

#endif
#endif