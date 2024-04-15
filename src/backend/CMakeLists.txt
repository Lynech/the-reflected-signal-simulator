project(backend)

add_library(backend STATIC
    vector3d.h
    object.h
    vector3d.cpp
    object.cpp
)

target_include_directories(backend INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
