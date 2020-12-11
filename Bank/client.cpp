//
// Created by 1285166 on 11.12.2020.
//

#include "client.h"
#include <iostream>

Client :: Client(const std::string &Name, const std::string &Address, const std::string &Pass,
                const std::string &Account_type, const float &start_money) {
    me = new client_data(Name, Address, Account_type);
    if (me->address != "-" && me->name != "-" && me->pass != "-")
        is_reliable = true;
    acc = create_acc(Account_type, start_money);
    type = Account_type;
}

Account* Client::create_acc(const std::string &Acc_type, const float &start_money) {
    if(Acc_type == "credit") {
        return new Credit(start_money);
    }
    else if(Acc_type == "debit")
        return new Debit(start_money);
    else if(Acc_type == "deposit")
        return new Deposit(start_money);
    else
        return nullptr;
}

std::string Client::acc_type() {
    return type;
}

void Client::change_info(const std::string &Name, const std::string &Address, const std::string &Pass) {
    if(Name != "-")
        me->name = Name;
    if(Address != "-")
        me->address = Address;
    if(Pass != "-")
        me->pass = Pass;
    if(me->address != "-" && me->name != "-" && me->pass != "-")
        is_reliable = true;
}

bool Client::make_transaction(const std::string &type, const float &money) {
    if(type == "add") {
        bool done = acc->add_money(money);
        if(done)
            add_transaction(type,money);
        return done;
    }
    if(type == "withdraw") {
        bool done = acc->withdraw(money);
        if(done)
            add_transaction(type,money);
        return done;
    }
}

void Client::add_transaction(const std::string &type, const float &money) {
    transactions.push_back({type,money});
}

float Client::return_money() {
    return acc->return_money();
}
bool Client::status() {
    return is_reliable;
}
void Client::skip_day(const float &Percent, const float &Percent_boost) {
    acc->end_day(Percent,Percent_boost);
}

void Client::cancel_transaction() {
    for(int i = 0; i < transactions.size();i++){
        std :: cout << '\n' << i <<' ' << transactions[i].money << ' ' << transactions[i].type << '\n';
    }
    std :: cout << '\n' << "Choose transaction to cancel\n";
    int num;
    std :: cin >> num;
    if(transactions[num].type == "add")
        acc->withdraw(transactions[num].money);
    else if(transactions[num].type == "withdraw")
        acc->add_money(transactions[num].money);
    transactions.erase(transactions.begin()+num);
}
