//
// Created by 1285166 on 30.10.2020.
//

#ifndef SHOP__SHOP_H
#define SHOP__SHOP_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <vector>
#include "exceptions.h"

#define ULL unsigned long long

class Product;

class Shop{
public:
    Shop(std :: string my_name, std :: string my_pos);
    ~Shop();
    void set_product_count(std :: string product_name, ULL count);
    void set_product_price(std :: string product_name, ULL price);
    void add_product(std :: string product, ULL price, ULL count);
    void add_product(std :: string product, ULL count);
    std :: pair<ULL, ULL> find_product(std :: string prod_name);
    std :: string get_name();
    std :: unordered_map <std :: string, std :: pair< ULL , std :: vector <GUID> >> storage;
private:
    std :: string name;
    GUID my_guid;
    std :: string position;
};

class Product{
public:
    Product(std :: string my_name, ULL my_price){
        name = my_name;
        price = my_price;
        CoCreateGuid(&my_guid);
    }
    std :: string get_name();
    ULL get_price();
    GUID get_guid();
    void set_price(ULL new_price);

private:
    ULL price;
    std :: string name;
    GUID my_guid;
    ULL counter;
};

#endif //SHOP__SHOP_H
