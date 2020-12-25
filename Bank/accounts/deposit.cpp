//
// Created by 1285166 on 11.12.2020.
//

#include "deposit.h"

Deposit :: Deposit(const float &start_money, const unsigned int &block, double percent, double boost) {
    boost_ = boost;
    percent_ = percent;
    money = start_money;
    block_days = block;
}

void Deposit ::end_day() {
    if (money < 50000)
        profit += money * (percent_+boost_ * 0);
    else if (money < 100000)
        profit += money * (percent_+boost_ * 1);
    else if (money < 500000)
        profit = money * (percent_+boost_ * 2);
    else
        profit += money * (percent_+boost_ * 3);
    block_days -= 1;
}

void Deposit :: end_month() {
    money += profit;
}

bool Deposit ::withdraw(const float &Money) {
    if(block_days < 1){
        if(money-Money < 0)
            return false;
        else
            money -= Money;
        return true;
    }
    return false;
}

bool Deposit::add_money(const float &Money) {
    money+=Money;
    return true;
}

float Deposit::return_money() {
    return money;
}

std::string Deposit::type() {
    return type_;
}