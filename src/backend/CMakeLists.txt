project(backend)

add_library(backend STATIC
    vector3d.h
    object.h
    signal.h
    field.h
    rls.h
    vector3d.cpp
    object.cpp
    signal.cpp
    field.cpp
    rls.cpp
)

target_include_directories(backend INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
