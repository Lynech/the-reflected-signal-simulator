cmake_minimum_required(VERSION 3.10)

project(simulator)

# cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

include_directories(
    ${LIB_DIR}
)
add_subdirectory("simulator")
