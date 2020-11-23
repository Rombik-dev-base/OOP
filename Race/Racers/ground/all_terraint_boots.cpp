//
// Created by 1285166 on 23.11.2020.
//

#include "all_terraint_boots.h"

double all_terrain_boots ::my_rest() {
    ++duration;
    return (duration == 1) ? 10 : 5;
}

unsigned int all_terrain_boots :: my_speed(){
    return speed;
}

std :: string all_terrain_boots :: my_name(){
    return name;
}

unsigned int all_terrain_boots :: get_rest_interval(){
    return restInterval;
}