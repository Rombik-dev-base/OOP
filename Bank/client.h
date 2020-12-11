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
    explicit Client(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-",
            const std :: string &Account_type = "-",const float &start_money = 0);
    void change_info(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-");
    bool make_transaction(const std :: string &type, const float &money);
    Account* create_acc(const std :: string &Acc_type, const float &start_money = 0);
    float return_money();
    bool status();
    void skip_day(const float &Percent, const float &Percent_boost);
    std :: string acc_type();
    void cancel_transaction();
private:
    void add_transaction(const std :: string &type, const float &money);
    client_data *me = nullptr;
    bool is_reliable = false;
    std :: string type;
    Account *acc = nullptr;
    std :: vector <transaction> transactions;
};

#endif //BANK_CLIENT_H
