cmake_minimum_required (VERSION 3.12)

project(lib)
# include_directories("vector3d")
# include_directories("object")
# include_directories("field")
# include_directories("rls")
# include_regular_expression(lib_dirs [^*/$])
# file(GLOB lib_dirs "./*/")
# include_directories(${lib_dirs})
add_library(
    lib STATIC
)
target_sources(lib
    PRIVATE
    object/object.cpp
    vector3d/vector3d.cpp
    rls/rls.cpp
    field/field.cpp
    signal/signal.cpp
)
target_include_directories(lib
    PUBLIC
    object
    vector3d
    rls
    field
)
target_precompile_headers(lib
    PUBLIC
    object/object.h
    rls/rls.h
    vector3d/vector3d.h
    field/field.h
)