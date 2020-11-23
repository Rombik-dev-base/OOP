//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_ALL_TERRAINT_BOOTS_H
#define RACE_REWORK_ALL_TERRAINT_BOOTS_H
#include "../ground_transport.h"

class all_terrain_boots : public ground_transport{
public:
    all_terrain_boots() = default;
    double my_rest() override;
    unsigned int my_speed() override;
    unsigned int get_rest_interval() override;
    std :: string my_name() override;
private:
    unsigned int speed = 15;
    unsigned int restInterval = 8;
    unsigned int duration = 0;
    std :: string name = "we are boots";
};

#endif //RACE_REWORK_ALL_TERRAINT_BOOTS_H
