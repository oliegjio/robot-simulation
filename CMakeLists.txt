cmake_minimum_required(VERSION 3.8)
project(robot-simulation)

set(MY_SOURCES main.cpp point.cpp)

set(MY_HEADERS main.h point.h)

add_executable(robot-simulation ${MY_SOURCES} ${MY_HEADERS})

target_link_libraries(robot-simulation GL GLU glut)
