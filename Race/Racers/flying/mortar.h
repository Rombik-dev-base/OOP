//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_MORTAR_H
#define RACE_REWORK_MORTAR_H
#include "../flying_transport.h"

class mortar : public flying_transport{
public:
    mortar() = default;
    int my_slower(unsigned int) override;
    unsigned int my_speed() override;
    std :: string my_name() override;
private:
    unsigned int speed = 8;
    std :: string name = "mortar";
};


#endif //RACE_REWORK_MORTAR_H
