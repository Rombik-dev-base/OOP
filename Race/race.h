//
// Created by 1285166 on 02.11.2020.
//

#ifndef RACE_RACE_H
#define RACE_RACE_H

#include "transport.h"
#include <vector>
#include <iostream>
#include <fstream>

struct Racer{
    Racer(std :: string const &name, LL const speed, LL const special){
        my_name = name;
        my_speed = speed;
        my_special = special;
    }
    std :: string my_name;
    LL my_speed;
    LL my_special;
};

class Race{
public:
    Race(std :: vector<Transport*> my_racers);
private:
    int number_racers();
    void race_rules();
    void start_race();
    std :: vector<Transport*> racers;
    int circles;
    int circle_size;
};

#endif //RACE_RACE_H
