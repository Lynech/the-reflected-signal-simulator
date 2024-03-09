set(TARGET "simulator")

project(${TARGET} LANGUAGES CXX)

set(SOURCES
    main.cpp
)

add_executable(
    ${TARGET} ${SOURCES}
)

install(TARGETS ${TARGET})