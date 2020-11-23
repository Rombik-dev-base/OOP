//
// Created by 1285166 on 23.11.2020.
//

#include "bactrian_camel.h"

double bactrian_camel ::my_rest() {
    ++duration;
    return (duration == 1) ? 5 : 8;
}

unsigned int bactrian_camel :: my_speed(){
    return speed;
}

std :: string bactrian_camel :: my_name(){
    return name;
}

unsigned int bactrian_camel :: get_rest_interval(){
    return restInterval;
}
