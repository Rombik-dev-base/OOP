cmake_minimum_required(VERSION 3.15)
project(Race)

set(CMAKE_CXX_STANDARD 14)

add_executable(Race main.cpp transport.cpp transport.h race.cpp race.h exceptions.h construct_race.cpp construct_race.h)