#include <iostream>
#include "Back_Up.h"
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y:%m:%d:%X", &tstruct);
    return buf;
}

void case1(){
    Back_Up test({"test1.txt","test2.txt"});
    test.create_point("full");
    test.print_point_info(0);
    int n = 5;
    Sleep(10000);
    test.create_point("delta");
    test.print_point_info(1);
    test.create_point("full");
    std :: cout << test.print_amount_of_points() << '\n';
    test.delete_by_amount(2);
    std :: cout << test.print_amount_of_points() << '\n';
    test.delete_by_amount(1);
    std :: cout << test.print_amount_of_points() << '\n';
    test.print_point_info(0);
    test.create_point("full");
    test.print_point_info(0);
    Sleep(10000);
    test.create_point("delta");
    test.print_point_info(1);
    test.create_point("full");
    test.delete_by_size(2100);
    test.print_amount_of_points();
    test.print_point_info(0);

}

void case2(){
    Back_Up test({"test1.txt","test2.txt"});
    test.create_point("full");
    Sleep(25000);
    std :: string time = currentDateTime();
    Sleep(1000);
    test.create_point("full");
    std :: cout << test.print_amount_of_points() << '\n';
    test.print_point_info(0);
    test.delete_by_date(time);
    std :: cout << test.print_amount_of_points() << '\n';
    test.print_point_info(0);
}

void case4(){
    Back_Up test({"test1.txt","test2.txt"});
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    test.hybrid_delete(6,2500,"none",true,true);
}

int main() {

    return 0;
}