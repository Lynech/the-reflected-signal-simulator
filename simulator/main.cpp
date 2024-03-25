#include "../lib/object/object.h"
#include "../lib/vector3d/vector3d.h"
#include "field.h"
#include <chrono>
#include <thread>
// #include<windows.h>
int main() {
  Field field{100, 3};
  for (char t = 0; t >= 0; t++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    field.update(1);
  }
  return 0;
}