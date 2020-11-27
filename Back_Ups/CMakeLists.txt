cmake_minimum_required(VERSION 3.15)
project(Back_Ups)

set(CMAKE_CXX_STANDARD 14)

add_executable(Back_Ups main.cpp point_types/point.cpp point_types/point.h point_types/delta_point.cpp point_types/delta_point.h point_types/full_point.cpp point_types/full_point.h Back_Up.cpp Back_Up.h)