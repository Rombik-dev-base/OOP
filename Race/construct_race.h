//
// Created by 1285166 on 13.11.2020.
//

#ifndef RACE_CONSTRUCT_RACE_H
#define RACE_CONSTRUCT_RACE_H

#include "race.h"
#include "exceptions.h"

class construct_race{
public:
    construct_race();
    std :: vector <Transport*> choose_racers();
private:
    void read_file(short const &flag, std :: ifstream &read);
    std :: string get_line(std :: ifstream &read);
    void space_deleter(std :: string cur_str);
    static Transport* add_transport(const Racer &l_racer);
    std :: vector<Transport*> racers;
};

#endif //RACE_CONSTRUCT_RACE_H
