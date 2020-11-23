//
// Created by 1285166 on 24.11.2020.
//

#ifndef RACE_REWORK_SPEED_CAMEL_H
#define RACE_REWORK_SPEED_CAMEL_H


#include "../ground_transport.h"

class speed_camel : public ground_transport{
public:
    double my_rest() override;
    unsigned int my_speed() override;
    unsigned int get_rest_interval() override;
    std :: string my_name() override;
private:
    unsigned int speed = 40;
    unsigned int restInterval = 10;
    unsigned int duration = 0;
    std :: string name = "speed camel";
};


#endif //RACE_REWORK_SPEED_CAMEL_H
