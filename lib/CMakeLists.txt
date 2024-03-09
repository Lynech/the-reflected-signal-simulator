cmake_minimum_required (VERSION 3.5)

project(lib)

add_library(lib STATIC object/object.h object/object.cpp vector3d/vector3d.h vector3d/vector3d.cpp)
