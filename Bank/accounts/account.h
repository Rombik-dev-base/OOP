//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>

class Account{
public:
    Account() = default;
    virtual void end_day() = 0;
    virtual std :: string type() = 0;
    virtual void end_month() = 0;
    virtual bool add_money(const float &Money) = 0;
    virtual bool withdraw(const float &Money) = 0;
    virtual float return_money() = 0;
    virtual void set_percent(const double &percent) = 0;
    virtual void set_money(const double &money) = 0;
};

#endif //BANK_ACCOUNT_H
