cmake_minimum_required(VERSION 3.16)

project(simulator VERSION 1.0.0 LANGUAGES CXX)

include_directories(../backend/)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(simulator
    mainwindow.ui
    mainwindow.cpp
    mainwindow.h
    main.cpp
    grid_widget.cpp
    grid_widget.h
    qcustomplot.cpp
    qcustomplot.h

)

target_link_libraries(simulator PRIVATE Qt6::Widgets)

target_link_libraries(simulator PRIVATE backend)

set_target_properties(simulator PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
