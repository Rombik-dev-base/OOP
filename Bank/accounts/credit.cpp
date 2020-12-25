//
// Created by 1285166 on 11.12.2020.
//

#include "credit.h"

Credit ::Credit(const float &start_money, double credit_per) {
    percent_ = credit_per;
    money = start_money;
}

bool Credit::add_money(const float &Money) {
    money+=Money;
    return true;
}

float Credit::return_money() {
    return money;
}

void Credit :: end_day() {
    if(money < 0)
        money -= abs(money)*percent_;
}

std :: string Credit ::type() {
    return type_;
}

void Credit ::end_month() {
    return;
}

bool Credit :: withdraw(const float &Money) {
    money -= Money;
    return true;
}