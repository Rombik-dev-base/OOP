//
// Created by 1285166 on 13.11.2020.
//

#include "construct_race.h"


construct_race ::construct_race() {
    std :: cout << "Choose race type 1 - land, 2 - flying, 3 - mixed type\n";
    short type = -1;
    std :: cin >> type;
    std :: ifstream read_racers("racers.txt");
    if(type == 1){
        read_file(1,read_racers);
    }

    else if(type == 2){
        read_file(2, read_racers);
    }

    else if(type == 3){
        read_file(3, read_racers);
    }
    else{
        throw myexception("Wrong type of race");
    }
}

void construct_race :: read_file(short const &flag,  std :: ifstream &read) {
    std :: string contain;
    while(std :: getline(read, contain)){
        std :: string name = get_line(read);
        LL speed = std :: stoll(get_line(read));
        LL rest = std :: stoll(get_line(read));
        std :: string transport_type = get_line(read);
        Racer* transport = new Racer(name,speed,rest);
        if(flag == 1 && transport_type == " land_transport"){
            racers.push_back(add_transport(*transport));
        }

        else if(flag == 2 && transport_type == " flying_transport"){
            racers.push_back(add_transport(*transport));
        }

        else if(flag == 3){
                racers.push_back(add_transport(*transport));

        }
    }
}

std :: string construct_race  ::get_line(std::ifstream &read) {
    std :: string contain;
    int found_pos;
    std :: getline(read,contain);
    space_deleter(contain);
    found_pos = contain.find('=');
    contain = contain.substr(found_pos + 1,contain.size() - found_pos);
    return contain;
}

void construct_race :: space_deleter(std :: string cur_str) {
    while(cur_str[0] == ' ' || cur_str[cur_str.size() - 1] == ' '){
        if(cur_str[0] == ' '){
            cur_str.erase(0,1);
        }
        if(cur_str[cur_str.size() - 1] == ' ')
            cur_str.erase(cur_str.size() - 1 , 1);
    }
}

Transport* construct_race ::add_transport(const Racer &l_racer) {
    land_transport *racer = new land_transport(l_racer.my_speed, l_racer.my_special, l_racer.my_name);
    return racer;
}

std :: vector <Transport*> construct_race :: choose_racers(){
    std :: vector <Transport*> my_racers;
    while(racers.size() != 0) {
        for (int i = 0; i < racers.size(); i++) {
            std::cout << i << ' ' << racers[i]->get_my_name() << '\n';
        }
        std::cout << "Choose number of racer or if u wont write -1\n";
        int num;
        std::cin >> num;
        if(num == -1)
            return my_racers;
        my_racers.push_back(racers[num]);
        racers.erase(racers.begin() + num);
    }
}

