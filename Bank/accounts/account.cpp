//
// Created by 1285166 on 11.12.2020.
//

#include "account.h"

bool Account :: add_money(const float &Money) {
    money += Money;
    return true;
}
float Account::return_money() {
    return money;
}
