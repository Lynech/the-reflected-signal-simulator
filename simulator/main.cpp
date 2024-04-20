#include "../lib/object/object.h"
#include "../lib/vector3d/vector3d.h"
#include "field.h"
#include <chrono>
#include <thread>
// #include<windows.h>



// std::string vobjtostr(std::vector<std::shared_ptr<Object>> objects) {
//   std::string result = "";
//   for (auto i = objects.begin(); i != objects.end(); i++)
//     result +=
// }

int main() {
  auto field = std::shared_ptr<Field>(new Field);
  field->enable_rls();
  field->add_object(Object{"obj1", {0, 0, 15}, {0, 0, 100}});
  // for (char t = 0; t >= 0; t++) {
  for (;;) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    field->update(1);
    auto probe = field->probe();
    std::cout << probe;
  }
  return 0;
}