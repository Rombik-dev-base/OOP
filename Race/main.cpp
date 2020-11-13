#include <iostream>
#include "race.h"
#include "construct_race.h"


int main() {
    construct_race race;
    Race my_race(race.choose_racers());
    return 0;
}
