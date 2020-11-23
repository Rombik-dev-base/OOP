//
// Created by 1285166 on 24.11.2020.
//

#ifndef RACE_REWORK_RACE_H
#define RACE_REWORK_RACE_H
#include <vector>
#include "Racers/racers_include.h"

class Race{
public:
    Race(unsigned int);
    void to_race();
private:
    std :: vector<transport*> racers;
    std :: vector<transport*> race;
    void add_ground();
    void add_flying();
    unsigned int distance;
};


#endif //RACE_REWORK_RACE_H
