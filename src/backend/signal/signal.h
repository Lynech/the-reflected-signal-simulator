#ifndef SIGNAL_H
#define SIGNAL_H
#include <memory>
#include <vector>

#include "../object/object.h"
#include "../vector3d/vector3d.h"

class Signal {
 private:
  std::vector<Object> objects_probed;

 public:
  void SetObgects(std::vector<Object> &objects);
  std::vector<Object> ProbedObjects();
};

#endif