#ifndef SIGNAL_H
#define SIGNAL_H
#include <memory>
#include <vector>

#include "../object/object.h"
#include "../vector3d/vector3d.h"
/// @brief Класс сигнал
class Signal {
 private:
  std::vector<Object> objects_probed;

 public:
  /// @brief преобразовать сигнал с учетом отражений
  /// @param objects объекты, которые могут быть отражены
  void reflectedObjects(std::vector<Object> &objects);
  /// @brief получить инфомацию об отражениях
  /// @return вектор преображения
  std::vector<Object> getReflectionInfo();
};

#endif