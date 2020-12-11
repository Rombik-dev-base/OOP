//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_DEBIT_H
#define BANK_DEBIT_H
#include "account.h"

class Debit : public Account{
public:
    Debit(const float &start_money = 0);
    virtual void end_day(const float &Percent, const float &Percent_boost = 0) override;
    virtual void end_month() override;
    virtual bool withdraw(const float &Money) override;
private:
    float money;
    float profit;
};

#endif //BANK_DEBIT_H
