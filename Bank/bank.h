//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_BANK_H
#define BANK_BANK_H
#include "client.h"
#include <vector>
#include <iostream>

enum card_type{
    CREDIT,
    DEBIT,
    DEPOSIT
};

class card_builder{
public:
    card_builder() = default;
    virtual void set_percent(const double &percent) = 0;
    virtual void set_money(const double &money) = 0;
    virtual Account* return_card() = 0;
};

class credit_build : public card_builder{
public:
    credit_build();
    void set_percent(const double &percent) override;
    void set_money(const double &money ) override;
    Account* return_card() override;
private:
    Credit *card = nullptr;
};

class debit_build : public card_builder{
public:
    debit_build();
    void set_percent(const double &percent) override;
    void set_money(const double &money ) override;
    Account* return_card() override;
private:
    Debit *card = nullptr;
};

class deposit_build : public card_builder{
public:
    deposit_build();
    void set_percent(const double &percent) override;
    void set_money(const double &money ) override;
    Account* return_card() override;
private:
    Deposit *card = nullptr;
};

class card_director{
public:
    card_director(float percent, float percent_boost, float commission): percent_(percent),
    percent_boost_(percent_boost),
    commission_(commission){};
    void set_builder(card_builder *builder);
    void set_score(card_type type);
    void set_money(const double &money = 0);
    Account* get_pointer();
private:
    card_builder *builder_ = nullptr;
    float percent_;
    float percent_boost_;
    float commission_;
    double money_;
};

class Bank{
public:
    explicit Bank(const float &Percent = 0.04, const float &Percent_boost = 0.03, const float &Commission = 0.5);
    void add_client(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-", const std :: string &Account_type = "-",const float &start_money = 0);
    void time_lapse(const unsigned short &days = 0);
    void transaction(const std :: string &type, const float &money,const int &client_id_from,const int &client_to = -1);
    float show_client_status(const unsigned int &cliend_id);
    void cancel_transaction(const unsigned int &id, const unsigned int &card_id);
    Account* create_card(const card_type &type, const unsigned int &client_id,const double &money = 0);
private:
    void skip_day(Client &client);
    float maximal_transaction =  50000;
    float percent;
    float percent_boost;
    float commission;
    unsigned short day = 0;
    std :: vector <Client> storage;
    card_director *director = nullptr;
};

#endif //BANK_BANK_H
