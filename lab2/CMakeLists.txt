cmake_minimum_required(VERSION 3.15)
project(Shop)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shop main.cpp shop.cpp shop.h shop_list.cpp shop_list.h exceptions.h)
