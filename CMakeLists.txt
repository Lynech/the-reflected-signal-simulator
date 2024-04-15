cmake_minimum_required(VERSION 3.16)

project(simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory(src/backend)
add_subdirectory(src/app)

# set(CMAKE_BUILD_TYPE "MinSizeRel")
# set(QT_QMAKE_EXECUTABLE "C:/msys64/mingw64/bin/qmake6.exe")
# set(CMAKE_PREFIX_PATH "C:/msys64/mingw64")
# set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
