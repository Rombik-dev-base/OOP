//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_BACTRIAN_CAMEL_H
#define RACE_REWORK_BACTRIAN_CAMEL_H
#include "../ground_transport.h"

class bactrian_camel : public ground_transport{
public:
    double my_rest() override;
    unsigned int my_speed() override;
    unsigned int get_rest_interval() override;
    std :: string my_name() override;
private:
    unsigned int speed = 10;
    unsigned int restInterval = 30;
    unsigned int duration = 0;
    std :: string name = "bactrian camel";
};

#endif //RACE_REWORK_BACTRIAN_CAMEL_H
