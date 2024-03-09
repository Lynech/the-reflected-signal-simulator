cmake_minimum_required(VERSION 3.16)

set(TARGET "simulator")

set(HEADERS
    ../lib/object/object.h
    ../lib/vector3d/vector3d.h
)

set(SOURCES
    ../lib/object/object.cpp
    ../lib/vector3d/vector3d.cpp
)

# add_executable(
#     ${TARGET}
#     main.cpp
# )
project(${TARGET} CXX)

add_executable(${TARGET} ${SOURCES})

install(TARGETS ${TARGET})
