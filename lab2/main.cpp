#include "shop.h"
#include "shop_list.h"

int main() {
    GUID guid;
    CoCreateGuid(&guid);
    shop_list shops;
    shops.create_shop("Magazine", "Bavarskaya");
    shops.add_product("Magazine","Pepsi",257,13);
    shops.create_shop("Bagazine", "Bavarskaya");
    shops.add_product("Bagazine","Pepsi",155,12);
    shops.add_product("Bagazine","Cheeps",50,14);
    shops.add_product("Magazine","Cheeps",47,13);
    shops.i_can_buy(1000, "Magazine");
    shops.set_price("Magazine","Cheeps",47);
    shops.search_lowest_cost_group_products({{"Pepsi",2},{"Cheeps",2}});
    shops.search_lowest_cost_single_product("Pepsi");
    shops.buy_products("Bagazine",{{"Pepsi",2}});
    shops.buy_products("Bagazine",{{"Pepsi",2},{"Cheeps",5}});
    return 0;
}
