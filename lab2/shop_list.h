//
// Created by 1285166 on 30.10.2020.
//

#ifndef SHOP__SHOP_LIST_H
#define SHOP__SHOP_LIST_H
#include "shop.h"
#include <list>

class shop_list{
public:
    void create_shop(std :: string shop_name, std :: string position);
    void add_product(std :: string shop_name, std :: string product_name, ULL price, ULL count);
    void add_product(std :: string shop_name, std :: string product_name, ULL count);
    void set_price(std :: string shop_name, std :: string product_name, ULL price);
    void search_lowest_cost_single_product(std :: string prod); // task 4
    void i_can_buy(ULL money, std :: string shop);
    void buy_products(std :: string shop_name, std :: vector <std :: pair <std :: string , ULL> > products_list); // task 6
    void search_lowest_cost_group_products(std :: vector <std :: pair <std :: string , ULL> > products_list); // task 7
private:
    std :: list <Shop> shops;
};

#endif //SHOP_HYINA__SHOP_LIST_H
