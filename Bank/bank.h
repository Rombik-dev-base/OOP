//
// Created by 1285166 on 11.12.2020.
//

#ifndef BANK_BANK_H
#define BANK_BANK_H
#include "client.h"
#include <vector>
#include <iostream>

class Bank{
public:
    explicit Bank(const float &Percent = 1.04, const float &Percent_boost = 0.03, const float &Commission = 0.5);
    void add_client(const std :: string &Name = "-",const std :: string &Address = "-",const std :: string &Pass = "-", const std :: string &Account_type = "-",const float &start_money = 0);
    void time_lapse(const unsigned short &years = 0,const unsigned short &months = 0,const unsigned short &days = 0);
    void transaction(const std :: string &type, const float &money,const int &client_id_from,const int &client_to = -1);
    float show_client_status(const unsigned int &cliend_id);
    void cancel_transaction(const unsigned int &id);
private:
    void skip_day(Client &client);
    float maximal_transaction =  50000;
    float percent;
    float percent_boost;
    float commission;
    unsigned short day = 0;
    std :: vector <Client> storage;
};

#endif //BANK_BANK_H
