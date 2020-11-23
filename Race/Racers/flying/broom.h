//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_BROOM_H
#define RACE_REWORK_BROOM_H
#include "../flying_transport.h"

class broom : public flying_transport{
public:
    broom() = default;
    int my_slower(unsigned int) override;
    unsigned int my_speed() override;
    std :: string my_name() override;
private:
    unsigned int speed = 20;
    std :: string name = "broom";
};

#endif //RACE_REWORK_BROOM_H
