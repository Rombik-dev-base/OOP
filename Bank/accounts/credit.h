//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_CREDIT_H
#define BANK_CREDIT_H
#include "account.h"

class Credit : public Account{
public:
    Credit(const float &start_money = 0, double credit_per = 2.5);
    virtual void end_day() override;
    virtual void end_month() override;
    virtual bool withdraw(const float &Money) override;
    virtual bool add_money(const float &Money) override;
    virtual float return_money() override;
    virtual std :: string type() override;
    void set_percent(const double &percent) override;
    void set_money(const double &money ) override;
private:
    std :: string type_ = "credit";
    float money;
    double percent_;
};


#endif //BANK_CREDIT_H
