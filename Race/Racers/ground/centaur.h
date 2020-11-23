//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_CENTAUR_H
#define RACE_REWORK_CENTAUR_H
#include "../ground_transport.h"

class centaur : public ground_transport{
public:
    centaur() = default;
    double my_rest() override;
    unsigned int my_speed() override;
    unsigned int get_rest_interval() override;
    std :: string my_name() override;
private:
    unsigned int speed = 15;
    unsigned int restInterval = 8;
    std :: string name = "centaur";
};

#endif //RACE_REWORK_CENTAUR_H
