#ifndef SIGNAL_H
#define SIGNAL_H
#include "object.h"
#include "vector3d.h"
#include <memory>
#include <vector>

class Signal {
private:
  // double power;
  std::vector<std::shared_ptr<Object>> objects_probed;

public:
  void SetObgects(std::vector<std::shared_ptr<Object>> &objects);
  std::vector<std::shared_ptr<Object>> ProbedObjects();
  // Signal(do) : velocity{v}, d_between{d}, time_in_air{t} {}
};

#endif
