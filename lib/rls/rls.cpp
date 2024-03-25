#include "rls.h"

std::optional<Object> Rls::probe() {
  std::optional<Object> obgects = std::nullopt;
  double d = 0.1;
  double v = 50;
  auto signal = parent->radiate_signal(v, d);
  if (signal) {
    double obj_v =
        signal.value().getV() / (1 + d / (d - signal.value().getD()));
    double obj_coord = signal.value().getT() * (v + obj_v) / 2;
    obgects = Object("lol", obj_v, obj_coord);
  }
  return obgects;
}

Rls::Rls(std::shared_ptr<Field> parent_) : parent{parent_} {};