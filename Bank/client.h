//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_CLIENT_H
#define BANK_CLIENT_H
#include <string>
#include <vector>
#include "accounts/credit.h"
#include "accounts/deposit.h"
#include "accounts/debit.h"

struct client_data{
    explicit client_data(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-"){
        name = Name;
        address = Address;
        pass = Pass;
    };
    std :: string name;
    std :: string address;
    std :: string pass;
};

struct transaction{
    transaction(const std :: string &Type, const float &Money){
        money = Money;
        type = Type;
    }
    float money;
    std :: string type;
};

class Client{
public:
    explicit Client(const std :: string &Name,const std :: string &Address = "-",const std :: string &Pass = "-");
    void change_info(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-");
    bool make_transaction(const std :: string &type, const float &money,const unsigned int &card_id);
    void add_card(Account *acc);
    float return_money(unsigned int &card_id);
    bool status();
    void skip_day(const unsigned int &card_id);
    void cancel_transaction(const unsigned int &card_id);
    void end_month(unsigned int &card_id);
    int count_cards();
private:
    void add_transaction(const std :: string &type, const float &money);
    client_data *me = nullptr;
    bool is_reliable = false;
    std :: vector <Account*> cards;
    std :: vector <transaction> transactions;
};

#endif //BANK_CLIENT_H
