//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_DEBIT_H
#define BANK_DEBIT_H
#include "account.h"

class Debit : public Account{
public:
    Debit(const float &start_money = 0, double percent = 0.1);
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
    double percent_;
    std :: string type_ = "debit";
};

#endif //BANK_DEBIT_H
