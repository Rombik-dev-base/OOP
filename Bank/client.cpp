//
// Created by 1285166 on 11.12.2020.
//

#include "client.h"
#include <iostream>

Client :: Client(const std::string &Name, const std::string &Address, const std::string &Pass) {
    me = new client_data(Name, Address,Pass);
    if (me->address != "-" && me->name != "-" && me->pass != "-")
        is_reliable = true;
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

void Client::add_card(Account *acc) {
    cards.push_back(acc);
}

bool Client::make_transaction(const std::string &type, const float &money,const unsigned int &card_id) {
    if(type == "add") {
        bool done = cards[card_id]->add_money(money);
        if(done)
            add_transaction(type,money);
        return done;
    }
    if(type == "withdraw") {
        bool done = cards[card_id]->withdraw(money);
        if(done)
            add_transaction(type,money);
        return done;
    }
}

void Client::add_transaction(const std::string &type, const float &money) {
    transactions.push_back({type,money});
}

float Client::return_money(unsigned int &card_id) {
    return cards[card_id]->return_money();
}
bool Client::status() {
    return is_reliable;
}
void Client::skip_day(const unsigned int &card_id) {
    cards[card_id]->end_day();
}

int Client::count_cards() {
    return cards.size();
}

void Client::cancel_transaction(const unsigned int &card_id) {
    for(int i = 0; i < transactions.size();i++){
        std :: cout << '\n' << i <<' ' << transactions[i].money << ' ' << transactions[i].type << '\n';
    }
    std :: cout << '\n' << "Choose transaction to cancel\n";
    int num;
    std :: cin >> num;
    if(transactions[num].type == "add")
        cards[card_id]->withdraw(transactions[num].money);
    else if(transactions[num].type == "withdraw")
        cards[card_id]->add_money(transactions[num].money);
    transactions.erase(transactions.begin()+num);
}

void Client::end_month(unsigned int &card_id) {
    cards[card_id]->end_month();
}