#include "../lib/object/object.h"
#include "../lib/vector3d/vector3d.h"


int main ()
{
  Vector3D vec1 (1, 2, 3);
  std::cout << vec1 << "\n";
  Vector3D vec2 (4, 5, 6);
  std::cout << vec2 << "\n";

  Vector3D vec3 = vec1 + vec2;
  std::cout << vec3 << "\n";

  Vector3D vec4 = vec1 - vec2;
  std::cout << vec4 << "\n";

  Object obj1;
  std::cout << obj1 << "\n";

  Object obj2 ("object", 1, 2, 3, 1, 2, 3);
  std::cout << obj2 << "\n";


  Object obj3 ("object", Vector3D (4, 5, 6), Vector3D (4, 5, 6));
  std::cout << obj3 << "\n";

  obj3.update(10);
  std::cout << obj3 << "\n";

}