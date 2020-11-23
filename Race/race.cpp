//
// Created by 1285166 on 24.11.2020.
//

#include "race.h"
#include <iostream>
#include <string>

Race :: Race(unsigned int type){
    if(type == 1){
     add_ground();
    }
    else if(type == 2){
        add_flying();
    }
    else if(type == 3){
        add_ground();
        add_flying();
    }
    int inp = 1;
    while(inp >= 0 && inp < racers.size() && racers.size() > 0 ){
        for(int i = 0; i < racers.size(); i++){
            std :: cout << i << ' ' << racers[i]->my_name() <<  '\n';
        }
        std :: cout << "Choose racer by number or write -1" << '\n';
        std :: cin >> inp;
        if(inp >= 0 && inp < racers.size()){
            race.push_back(racers[inp]);
            racers.erase(racers.begin()+inp);
            inp = 0;
        }
    }
    racers.clear();
}

void Race ::to_race() {
    std :: cout << "Input race distance ";
    std :: cin >> distance;
    int winner = -1;
    unsigned long long race_time = ULLONG_MAX;
    for(unsigned int i = 0; i < race.size(); i++){
        unsigned long long cur_race_time = 0;
        if(race[i]->my_class() == "Ground transport") {
            int cur_distance = distance;
            unsigned int j = 0;
            while(cur_distance > 0){
                if(j == 0 || j % race[i]->get_rest_interval() != 0){
                    j++;
                    cur_distance -= race[i]->my_speed();
                    cur_race_time += 1;
                }
                else{
                    j = 0;
                    cur_race_time += race[i]->my_rest();
                }
            }
        }
        else{
            double cur_distance = 0;
            while(cur_distance < distance){
                cur_distance += race[i]->my_speed()*double(1 - double(race[i]->my_slower(cur_distance)/100));
                cur_race_time += 1;
            }
        }
        if(cur_race_time < race_time){
            race_time = cur_race_time;
            winner = i;
        }
    }
    std :: cout << "\nWinner is " << race[winner]->my_name() << " with time " << race_time;
}


void Race ::add_ground() {
    bactrian_camel *Bactrian = new bactrian_camel;
    transport *me = Bactrian;
    racers.push_back(me);
    centaur *Centaur = new centaur;
    me = Centaur;
    racers.push_back(me);
    all_terrain_boots *Boot = new all_terrain_boots;
    me = Boot;
    racers.push_back(me);

}

void Race ::add_flying() {
    broom *Broom = new broom;
    transport *me = Broom;
    racers.push_back(me);
    mortar *Mortar = new mortar;
    me = Mortar;
    racers.push_back(me);
    magic_carpet *carpet = new magic_carpet;
    me = carpet;
    racers.push_back(me);
}
