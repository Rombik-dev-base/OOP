//
// Created by 1285166 on 23.11.2020.
//

#include "speed_camel.h"

double speed_camel ::my_rest() {
    ++duration;
    if(duration == 1)
        return 5;
    else if(duration == 2){
        return 6.5;
    }
    else{
        return 8;
    }
}

unsigned int speed_camel :: my_speed(){
    return speed;
}

std :: string speed_camel :: my_name(){
    return name;
}

unsigned int speed_camel :: get_rest_interval(){
    return restInterval;
}
//
// Created by 1285166 on 24.11.2020.
//

#include "speed_camel.h"
