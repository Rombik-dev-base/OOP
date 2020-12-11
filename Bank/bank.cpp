//
// Created by 1285166 on 11.12.2020.
//

#include "bank.h"

Bank::Bank(const float &Percent, const float &Percent_boost, const float &Commission) {
    percent = Percent;
    percent_boost = Percent_boost;
    commission = Commission;
}

void Bank::add_client(const std::string &Name, const std::string &Address, const std::string &Pass, const std::string &Account_type,const long long &start_money = 0) {
    Client *client = new Client(Name,Address,Pass,Account_type,start_money);
    storage.push_back(*client);
}

void Bank::transaction(const std::string &type, const float &money, const int &client_id_from, const int &client_to) {
    if(maximal_transaction < money && (type == "transfer" || type ==  "withdraw" ) && !storage[client_id_from].status())
    {
        std :: cout << "\n Cant make transaction";
        return;
    }
    if(type == "transfer"){
        if(storage[client_id_from].make_transaction("withdraw",money)) {
            storage[client_to].make_transaction("add",money);
        }
        storage[client_id_from].make_transaction(type,money);
        return;
    }
}

float Bank::show_client_status(const unsigned int &cliend_id) {
    return storage[cliend_id].return_money();
}

void Bank::time_lapse(const unsigned short &years, const unsigned short &months, const unsigned short &days) {
    unsigned long long day = years*365+months*31+days;
    for(int i = 0; i < storage.size();i++)
        for(int i = 0 ; i < day;i++)
            skip_day(storage[i]);
}

void Bank::skip_day(Client &client) {
    if(client.acc_type() == "credit")
        client.skip_day(commission,0);
    else
        client.skip_day(percent,percent_boost);
}

void Bank::cancel_transaction(const unsigned int &id) {
    storage[id].cancel_transaction();   
}