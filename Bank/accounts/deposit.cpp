//
// Created by 1285166 on 11.12.2020.
//

#include "deposit.h"

Deposit :: Deposit(const float &start_money, const unsigned int &block, double percent, double boost) {
    boost_ = boost;
    percent_ = percent;
    money_ = start_money;
    block_days = block;
}

void Deposit ::end_day() {
    if (money_ < 50000)
        profit += money_ * (percent_+boost_ * 0);
    else if (money_ < 100000)
        profit += money_ * (percent_+boost_ * 1);
    else if (money_ < 500000)
        profit = money_ * (percent_+boost_ * 2);
    else
        profit += money_ * (percent_+boost_ * 3);
    block_days -= 1;
}

void Deposit :: end_month() {
    money_ += profit;
}

bool Deposit ::withdraw(const float &Money) {
    if(block_days < 1){
        if(money_-Money < 0)
            return false;
        else
            money_ -= Money;
        return true;
    }
    return false;
}

bool Deposit::add_money(const float &Money) {
    money_+=Money;
    return true;
}

float Deposit::return_money() {
    return money_;
}

std::string Deposit::type() {
    return type_;
}

void Deposit::return_day() {
    money_ = money_/(1+percent_);
}

void Deposit::set_money(const double &money) {
    money_ = money;
}

void Deposit::set_percent(const double &percent) {
    percent_ = percent;
}