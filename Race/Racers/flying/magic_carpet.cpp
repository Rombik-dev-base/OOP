//
// Created by 1285166 on 23.11.2020.
//

#include "magic_carpet.h"
int magic_carpet :: my_slower(unsigned int distance) {
    if(distance < 1000){
        return 0;
    }
    else if(distance < 5000){
        return 3;
    }
    else if (distance < 10000){
        return 10;
    }
    else{
        return 5;
    }
}

unsigned int magic_carpet :: my_speed(){
    return speed;
}

std :: string magic_carpet :: my_name(){
    return name;
}