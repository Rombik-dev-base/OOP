//
// Created by 1285166 on 11.12.2020.
//

#include "debit.h"
#include <iostream>

Debit ::Debit(const float &start_money, double percent) {
    percent_ = percent;
    money_ = start_money;
    profit = 0;
}

void Debit ::end_day() {
    std :: cout << profit << '\n';
    profit += money_*percent_;
}

void Debit :: end_month() {
    std :: cout << profit << '\n';
    money_ += profit;
    profit = 0;
}
bool Debit :: withdraw(const float &Money) {
    if(money_-Money < 0)
        return false;
    else
        money_ -= Money;
    return true;
}

bool Debit::add_money(const float &Money) {
    money_+=Money;
    return true;
}

float Debit::return_money() {
    return money_;
}

std::string Debit :: type() {
    return type_;
}

void Debit::set_money(const double &money) {
    money_ = money;
}

void Debit::set_percent(const double &percent) {
    percent_ = percent;
}

void Debit::return_day() {
    money_=money_/(1+percent_);
}