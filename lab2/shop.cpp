//
// Created by 1285166 on 30.10.2020.
//

#include "shop.h"

Shop :: Shop(std :: string my_name, std :: string my_pos){
    position = my_pos;
    name = my_name;
    CoCreateGuid(&my_guid);
}

Shop :: ~Shop(){
    position.clear();
    name.clear();
    storage.clear();
}

std::string Shop :: get_name() {
    return name;
}

void Shop :: set_product_price(std :: string product_name, ULL price){
    if(storage.find(product_name) != storage.end()){
        storage[product_name].first = price;
    }
    else
        throw my_exception("No product in price list");
}

void Shop :: add_product(std :: string product, ULL price, ULL count) {
    if(count == 1) {
        GUID new_guid;
        CoCreateGuid(&new_guid);
        storage[product].first = price;
        storage[product].second.push_back(new_guid);
    }
    else if(count > 1){
        for(int i = 0; i < count; i++){
            GUID new_guid;
            CoCreateGuid(&new_guid);
            storage[product].second.push_back(new_guid);
            storage[product].first = price;
        }
    }
    else if(count == 0){
        throw my_exception("You should add 1 or more products");
    }
}

void Shop :: add_product(std :: string product, ULL count) {
    if(storage.find(product) != storage.end()){
        if(count == 1) {
            GUID new_guid;
            CoCreateGuid(&new_guid);
            storage[product].second.push_back(new_guid);
        }
        else if(count > 1){
            for(int i = 0; i < count; i++){
                GUID new_guid;
                CoCreateGuid(&new_guid);
                storage[product].second.push_back(new_guid);
            }
        }
        else if(count == 0){
            throw my_exception("You should add 1 or more products");
        }
    }
    else{
        throw my_exception("Product of this type has not yet been registered");
    }
}

std :: pair<ULL, ULL> Shop :: find_product(std :: string prod_name){
    if(storage.find(prod_name) != storage.end()){
        return std :: make_pair(storage[prod_name].first, storage[prod_name].second.size());
    }
    else
        return {-1,-1};
}

void Shop :: set_product_count(std :: string product_name, ULL count){
    storage[product_name].second.erase(storage[product_name].second.begin(),storage[product_name].second.begin() + count);
}
