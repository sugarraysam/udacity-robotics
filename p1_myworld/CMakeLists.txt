cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(hello SHARED script/hello.cc)
target_link_libraries(hello ${GAZEBO_LIBRARIES})
