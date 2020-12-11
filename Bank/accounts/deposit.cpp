//
// Created by 1285166 on 11.12.2020.
//

#include "deposit.h"

Deposit :: Deposit(const float &start_money, const unsigned int &block) {
    money = start_money;
    block_days = block;
}

void Deposit ::end_day(const float &Percent, const float &Percent_boost) {
    if (money < 50000)
        profit = money * (Percent + Percent_boost * 0);
    else if (money < 100000)
        profit = money * (Percent + Percent_boost * 1);
    else if (money < 500000)
        profit = money * (Percent + Percent_boost * 2);
    else
        profit = money * (Percent + Percent_boost * 3);
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
    return false
}

