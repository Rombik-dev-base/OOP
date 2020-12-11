//
// Created by 1285166 on 11.12.2020.
//

#include "debit.h"

Debit ::Debit(const float &start_money) {
    money = start_money;
}

void Debit ::end_day(const float &Percent, const float &Percent_boost) {
    profit = money*Percent;
}

void Debit :: end_month() {
    money += profit;
}
bool Debit :: withdraw(const float &Money) {
    if(money-Money < 0)
        return false;
    else
        money -= Money;
    return true;
}

bool Debit::add_money(const float &Money) {
    money+=Money;
    return true;
}

float Debit::return_money() {
    return money;
}