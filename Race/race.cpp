//
// Created by 1285166 on 02.11.2020.
//

#include "race.h"
#include "exceptions.h"


Race :: Race(std :: vector<Transport*> my_racers){
    racers = my_racers;
    race_rules();
    start_race();
}

void Race ::race_rules() {
    std :: cout << "\nWrite count of circles\n";
    std :: cin >> circles;
    std :: cout << "\nWrite circle length\n";
    std :: cin >> circle_size;
}

void Race ::start_race() {
    std :: cout << "\n Number of racers : " << number_racers() << '\n';
    float cur_winner = 999999999;
    int number_winner;
    for(int i = 0 ; i < racers.size(); i++){
        float winner;
        if(racers[i]->get_my_class() == "land_transport")
            winner = (circle_size/racers[i]->get_speed())*circles + racers[i]->get_special();
        else{
            winner = (circle_size/(float(racers[i]->get_speed()) - float(racers[i]->get_speed()*float(int((circle_size*circles)/100)*float(racers[i]->get_special()/100))))) * circles;
        }
        if(cur_winner > winner){
            cur_winner = winner;
            number_winner = i;
        }
    }
    std :: cout << "Winner is : " << racers[number_winner]->get_my_name();

}

int Race ::number_racers() {
        return racers.size();
}



