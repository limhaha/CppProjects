cmake_minimum_required(VERSION 3.15)
project(opencv)

set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED)

add_executable(opencv main.cpp)

target_link_libraries( opencv ${OpenCV_LIBS} )