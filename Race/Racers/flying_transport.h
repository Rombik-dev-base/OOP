//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_FLYING_TRANSPORT_H
#define RACE_REWORK_FLYING_TRANSPORT_H
#include "transport_type.h"

class flying_transport : public transport{
public:
    flying_transport() = default;
    std :: string my_class() override;
private:

};

#endif //RACE_REWORK_FLYING_TRANSPORT_H
