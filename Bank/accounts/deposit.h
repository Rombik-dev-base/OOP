//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_DEPOSIT_H
#define BANK_DEPOSIT_H
#include "account.h"

class Deposit : public Account{
public:
    Deposit(const float &start_money = 0, const unsigned int &block = 31, double percent = 0.1, double boost = 0);
    virtual void end_day() override;
    virtual void end_month() override;
    virtual bool withdraw(const float &Money) override;
    virtual bool add_money(const float &Money) override;
    virtual float return_money() override;
    virtual std :: string type() override;
    void set_percent(const double &percent) override;
    void set_money(const double &money ) override;

private:
    float money;
    float profit = 0;
    double boost_;
    double percent_;
    unsigned int block_days;
    std :: string type_ = "deposit";
};

#endif //BANK_DEPOSIT_H
