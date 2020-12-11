//
// Created by 1285166 on 11.12.2020.
//

#include "credit.h"

Credit ::Credit(const float &start_money) {
    money = start_money;
}

void Credit :: end_day(const float &Percent, const float &Percent_boost) {
    if(money < 0)
        money -= abs(money)*Percent;
}

void Credit ::end_month() {
    return;
}

bool Credit :: withdraw(const float &Money) {
    money -= Money;
    return true;
}