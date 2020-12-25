//
// Created by 1285166 on 11.12.2020.
//

#include "bank.h"

Bank::Bank(const float &Percent, const float &Percent_boost, const float &Commission) {
    percent = Percent;
    percent_boost = Percent_boost;
    commission = Commission;
    director = new card_director(percent,percent_boost,commission);
}

void Bank::add_client(const std::string &Name, const std::string &Address, const std::string &Pass, const std::string &Account_type,const float &start_money) {
    Client *client = new Client(Name,Address,Pass);
    storage.push_back(*client);
}

void Bank::transaction(const std::string &type, const float &money, const int &client_id_from, const int &client_to) {
    if(maximal_transaction < money && (type == "transfer" || type ==  "withdraw" ) && !storage[client_id_from].status())
    {
        std :: cout << "\n Cant make transaction";
        return;
    }
    if(type == "transfer"){
        if(storage[client_id_from].make_transaction("withdraw",money,0)) {
            storage[client_to].make_transaction("add",money,0);
        }
        storage[client_id_from].make_transaction(type,money);
        return;
    }
    storage[client_id_from].make_transaction(type,money);
}

float Bank::show_client_status(const unsigned int &cliend_id) {
    return storage[cliend_id].return_money();
}

void Bank::time_lapse(const unsigned short &days) {
    unsigned long long Days = days;
    for(int i = 0; i < storage.size();i++)
        for(int j = 0 ; j < Days;j++) {
            skip_day(storage[i]);
            day += 1;
            if(day == 31) {
                storage[i].end_month();
                day = 0;
            }
        }
}

Account * card_director::get_pointer() {
    return builder_->return_card();
}

void card_director::set_builder(card_builder *builder) {
    builder_ = builder;
}

void card_director::set_score(card_type type) {
    builder_->set_money(money_);
    if(type == CREDIT)
        builder_->set_percent(commission_);
    else
        builder_->set_percent(percent_);
}


void card_director::set_money(const double &money) {
    money_ = money;
}


credit_build::credit_build(){
    card = new Credit;
}

void credit_build::set_money(const double &money) {
    card->set_money(money);
}

void credit_build::set_percent(const double &percent) {
    card->set_percent(percent);
}

Account * credit_build::return_card() {
    return card;
}

deposit_build::deposit_build(){
    card = new Deposit;
}

void deposit_build::set_money(const double &money) {
    card->set_money(money);
}

void deposit_build::set_percent(const double &percent) {
    card->set_percent(percent);
}

Account * deposit_build::return_card() {
    return card;
}

debit_build::debit_build(){
    card = new Debit;
}

void debit_build::set_money(const double &money) {
    card->set_money(money);
}

void debit_build::set_percent(const double &percent) {
    card->set_percent(percent);
}

Account * debit_build::return_card() {
    return card;
}

Account* Bank :: create_card(const card_type &type,const unsigned int &client_id,const double &money){
    if(type == CREDIT){
        director->set_builder(new credit_build);
    }
    else if(type == DEBIT){
        director->set_builder(new debit_build);
    }
    else if(type == DEPOSIT){
        director->set_builder(new deposit_build);
    }
    director->set_score(type);
    storage[client_id].add_card(director->get_pointer());
}

void Bank::skip_day(Client &client) {
    for(int i = 0; i < client.count_cards(); i++){
        client.skip_day(i);
    }
}

void Bank::cancel_transaction(const unsigned int &id, const unsigned int &card_id) {
    storage[id].cancel_transaction(card_id);
}
