//
// Created by 1285166 on 11.12.2020.
//

#include "debit.h"
#include <iostream>

Debit ::Debit(const float &start_money, double percent) {
    percent_ = percent;
    money = start_money;
    profit = 0;
}

void Debit ::end_day() {
    std :: cout << profit << '\n';
    profit += money*percent_;
}

void Debit :: end_month() {
    std :: cout << profit << '\n';
    money += profit;
    profit = 0;
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

std::string Debit :: type() {
    return type_;
}