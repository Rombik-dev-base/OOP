//
// Created by 1285166 on 23.11.2020.
//

#ifndef RACE_REWORK_TRANSPORT_TYPE_H
#define RACE_REWORK_TRANSPORT_TYPE_H
#include <string>

class transport{
public:
    transport() = default;
    virtual double my_rest();
    virtual int my_slower(unsigned int distance);
    virtual std :: string my_name();
    virtual unsigned int get_rest_interval();
    virtual std :: string my_class();
    virtual unsigned int my_speed();
private:
};


#endif //RACE_REWORK_TRANSPORT_TYPE_H
