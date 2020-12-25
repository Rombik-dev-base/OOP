//
// Created by 1285166 on 11.12.2020.
//

#include "credit.h"

Credit ::Credit(const float &start_money, double credit_per) {
    percent_ = credit_per;
    money_ = start_money;
}

bool Credit::add_money(const float &Money) {
    money_+=Money;
    return true;
}

float Credit::return_money() {
    return money_;
}

void Credit :: end_day() {
    if(money_ < 0)
        money_ -= abs(money_)*percent_;
}

std :: string Credit ::type() {
    return type_;
}

void Credit::set_percent(const double &percent) {
    percent_=percent;
}

void Credit::set_money(const double &money) {
    money_ = money;
}

void Credit::return_day() {
    money_ =money_/(1+percent_);
}

void Credit ::end_month() {
    return;
}

bool Credit :: withdraw(const float &Money) {
    money_ -= Money;
    return true;
}