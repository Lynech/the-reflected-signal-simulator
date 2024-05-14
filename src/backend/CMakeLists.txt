cmake_minimum_required (VERSION 3.25)

project(backend)
# include_directories("vector3d")
# include_directories("object")
# include_directories("field")
# include_directories("rls")
# include_regular_expression(lib_dirs [^*/$])
# file(GLOB lib_dirs "./*/")
# include_directories(${lib_dirs})
add_library(
    backend STATIC
    object/object.cpp
    vector3d/vector3d.cpp
    rls/rls.cpp
    field/field.cpp
    signal/signal.cpp

    object/object.h
    rls/rls.h
    vector3d/vector3d.h
    field/field.h
)
target_include_directories(backend
    PUBLIC
    object
    vector3d
    rls
    field
)
target_precompile_headers(backend
    PUBLIC
    object/object.h
    rls/rls.h
    vector3d/vector3d.h
    field/field.h
)
