//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_DEPOSIT_H
#define BANK_DEPOSIT_H
#include "account.h"

class Deposit : public Account{
public:
    Deposit(const float &start_money = 0, const unsigned int &block = 31);
    virtual void end_day(const float &Percent, const float &Percent_boost = 0) override;
    virtual void end_month() override;
    virtual bool withdraw(const float &Money) override;
    virtual bool add_money(const float &Money) override;
    virtual float return_money() override;
private:
    float money;
    float profit;
    unsigned int block_days;
};

#endif //BANK_DEPOSIT_H
