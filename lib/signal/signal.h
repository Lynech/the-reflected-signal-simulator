#ifndef SIGNAL_H
#define SIGNAL_H
#include "../vector3d/vector3d.h"
class Signal {
private:
  double velocity;
  double d_between;
  double time_in_air;

public:
  Signal(double v, double d, double t) : velocity{v}, d_between{d}, time_in_air{t} {}
  double getD() { return d_between; }
  double getV() { return velocity; }
  double getT() { return time_in_air; }
};

#endif