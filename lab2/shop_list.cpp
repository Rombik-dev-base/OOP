//
// Created by 1285166 on 30.10.2020.
//

#include "shop_list.h"
#include "exceptions.h"
void shop_list :: create_shop(std :: string shop_name, std :: string position){
    shops.push_back(Shop(shop_name,position));
}

void shop_list :: add_product(std :: string shop_name, std :: string product_name, ULL price, ULL count){
    for(auto i = shops.begin(); i != shops.end(); i++){
        if(i->get_name() == shop_name){
            i->add_product(product_name,price,count);
            return;
        }
    }
    throw my_exception("Store does not exist");
}

void shop_list :: add_product(std :: string shop_name, std :: string product_name, ULL count){
    for(auto i = shops.begin(); i != shops.end(); i++){
        if(i->get_name() == shop_name){
            i->add_product(product_name,count);
            return;
        }
    }
    throw my_exception("Store does not exist");
}

void shop_list :: set_price(std :: string shop_name, std :: string product_name, ULL price){
    for(auto i = shops.begin(); i != shops.end(); i++){
        if(i->get_name() == shop_name){
            i->set_product_price(product_name,price);
            return;
        }
    }
}

void shop_list :: search_lowest_cost_single_product(std :: string prod){
    std :: pair<ULL,std :: string> cur_min = {ULLONG_MAX, ""};
    for(auto i = shops.begin(); i != shops.end(); i++){
        std :: pair <ULL,ULL> search_min = i->find_product(prod);
        if(search_min.first != -1){
            if(search_min.second > 0)
                if(search_min.first <= cur_min.first) {
                    cur_min = {search_min.first, i->get_name()};
                }
        }
    }
    if(cur_min.second != "")
        std :: cout << cur_min.second << '\n';
    else
        std :: cout << "there are no such goods in stores" << '\n';
}

void shop_list :: buy_products(std :: string shop_name, std :: vector <std :: pair <std :: string , ULL> > products_list){
    auto pointer = shops.begin();
    bool can_buy = false;
    for(auto i = shops.begin(); i != shops.end(); i++){
        if(i->get_name() == shop_name){
            can_buy = true;
            for(int j = 0; j < products_list.size(); j++){
                if(i->find_product(products_list[j].first).second < products_list[j].second){
                    can_buy = false;
                    break;
                }
            }
            if(can_buy) {
                pointer = i;
                break;
            }
        }
    }
    if(can_buy){
        ULL final_price = 0;
        for(int j = 0; j < products_list.size(); j++){
            std :: pair<ULL,ULL> new_pair = pointer->find_product(products_list[j].first);
            final_price += (new_pair.first * products_list[j].second);
            pointer->set_product_count(products_list[j].first,products_list[j].second);
        }
        std :: cout << final_price << '\n';
    }
    else{
        std :: cout << "not enough goods";
    }
}

void shop_list :: search_lowest_cost_group_products(std :: vector <std :: pair <std :: string , ULL> > products_list){
    std :: string shop;
    long long lowest_price = LONG_LONG_MAX;
    for(auto i = shops.begin(); i != shops.end(); i++){
        long long cur_lowest_price = 0;
        for(int j = 0; j < products_list.size(); j++){
            if(i->find_product(products_list[j].first).second >= products_list[j].second){
                cur_lowest_price += (i->find_product(products_list[j].first).first * products_list[j].second);
            }
            else
                cur_lowest_price = -1;
        }
        if(cur_lowest_price < lowest_price && cur_lowest_price != -1){
            lowest_price = cur_lowest_price;
            shop = i->get_name();
        }
    }
    if(lowest_price != LONG_LONG_MAX)
        std :: cout << "\nComplete lowest cost is : " << lowest_price << " in shop with name : " << shop << '\n';
    else
        std :: cout << "\nNot enough goods in shops\n";
}

void shop_list :: i_can_buy(ULL money, std :: string shop){
    bool buyed = false;
    for(auto i = shops.begin(); i != shops.end(); i++){
        if(i->get_name() == shop){
            for(auto j = i->storage.begin() ; j != i->storage.end(); j++){
                if(j->second.first <= money){
                    buyed = true;
                    std :: cout << "\nI can buy : " << money/j->second.first << " " << j->first << '\n';
                }
            }
            if(buyed)
                break;
        }
    }
    if(!buyed){
        std :: cout << "\nI have not money to buy anything\n";
    }
}
