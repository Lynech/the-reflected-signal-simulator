#include "signal.h"

void Signal::SetObgects(std::vector<std::shared_ptr<Object>> &objects) {
  objects_probed = objects;
}
std::vector<std::shared_ptr<Object>> Signal::ProbedObjects() {
  return objects_probed;
}