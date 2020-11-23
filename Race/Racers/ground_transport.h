//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_GROUND_TRANSPORT_H
#define RACE_REWORK_GROUND_TRANSPORT_H
#include "transport_type.h"

class ground_transport : public transport{
public:
    ground_transport() = default;
    virtual std :: string my_class() override;
private:
};



#endif //RACE_REWORK_GROUND_TRANSPORT_H
