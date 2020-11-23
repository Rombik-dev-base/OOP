//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_MAGIC_CARPET_H
#define RACE_REWORK_MAGIC_CARPET_H
#include "../flying_transport.h"

class magic_carpet : public flying_transport{
public:
    magic_carpet() = default;
    int my_slower(unsigned int) override;
    unsigned int my_speed() override;
    std :: string my_name() override;
private:
    unsigned int speed = 10;
    std :: string name = "magic carpet";
};


#endif //RACE_REWORK_MAGIC_CARPET_H
