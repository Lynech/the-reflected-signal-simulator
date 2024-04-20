cmake_minimum_required (VERSION 3.25)

set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
set(CXX_STANDART C++20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -g")
project(full_simulator)
# set_property(full_simulator tgt Y CXX_STANDARD 11)
add_subdirectory(lib)
add_subdirectory(simulator)

# set(DCMAKE_GENERATOR "STRING=C:/")
