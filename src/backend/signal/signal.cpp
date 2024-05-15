#include "signal.h"

void Signal::SetObgects(std::vector<Object> &objects) {
  objects_probed = objects;
}
std::vector<Object> Signal::ProbedObjects() { return objects_probed; }