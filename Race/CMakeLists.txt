cmake_minimum_required(VERSION 3.15)
project(Race_Rework)

set(CMAKE_CXX_STANDARD 14)

add_executable(Race_Rework main.cpp Racers/transport_type.cpp Racers/transport_type.h Racers/ground/bactrian_camel.cpp Racers/ground/bactrian_camel.h Racers/flying_transport.cpp Racers/flying_transport.h Racers/ground_transport.cpp Racers/ground_transport.h Racers/ground/centaur.cpp Racers/ground/centaur.h Racers/ground/all_terraint_boots.cpp Racers/ground/all_terraint_boots.h Racers/flying/broom.cpp Racers/flying/broom.h Racers/flying/mortar.cpp Racers/flying/mortar.h Racers/racers_include.h race.cpp race.h Racers/ground/speed_camel.cpp Racers/ground/speed_camel.h Racers/flying/magic_carpet.cpp Racers/flying/magic_carpet.h)