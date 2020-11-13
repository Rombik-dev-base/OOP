//
// Created by 1285166 on 31.10.2020.
//

#include "transport.h"



LL Transport :: get_special(){
    return -1;
}

land_transport :: land_transport(LL const &speed, LL const &rest,std :: string const &name){
    rest_time = rest;
    my_speed = speed;
    my_name = name;
}

LL land_transport :: get_special (){
    return rest_time;
}

std :: string land_transport :: get_my_name(){
    return my_name;
};

LL land_transport :: get_speed() {
    return my_speed;
}

std :: string land_transport ::get_my_class() {
    return my_class;
}

flying_transport :: flying_transport(LL const &speed,LL const &slow, std :: string const &name){
    slower = slow;
    my_speed = speed;
    my_name = name;
}

std :: string flying_transport :: get_my_name(){
    return my_name;
};

LL flying_transport :: get_speed() {
    return my_speed;
}

LL flying_transport ::get_special() {
    return slower;
}

std :: string flying_transport ::get_my_class() {
    return my_class;
}

Magic_carpet :: Magic_carpet(LL const &speed,LL const &slow, std :: string const &name){
    slower = slow;
    my_speed = speed;
    my_name = name;
}

std :: string Magic_carpet :: get_my_name(){
    return my_name;
};

LL Magic_carpet :: get_speed() {
    return my_speed;
}

LL Magic_carpet ::get_special() {
    return slower;
}

std :: string Magic_carpet ::get_my_class() {
    return my_class;
}

Magic_carpet :: Magic_carpet() {
    my_speed = 25;
    slower = 8;
    my_name = "Magic carpet";
}

Bactrian ::Bactrian() {
    my_speed = 25;
    rest_time = 3;
    my_name = "Magic carpet";
}

Bactrian :: Bactrian(LL const &speed, LL const &rest,std :: string const &name){
    rest_time = rest;
    my_speed = speed;
    my_name = name;
}

LL Bactrian :: get_special (){
    return rest_time;
}

std :: string Bactrian :: get_my_name(){
    return my_name;
};

LL Bactrian :: get_speed() {
    return my_speed;
}

std :: string Bactrian ::get_my_class() {
    return my_class;
}


