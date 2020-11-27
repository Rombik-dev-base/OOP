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

int main() {
    Back_Up test({"test1.txt","test2.txt"});
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    test.create_point("full");
    Sleep(5000);
    std :: string time = currentDateTime();
    test.hybrid_delete(4,-1,time,true,true);
    std :: cout << test.print_amount_of_points();
    test.hybrid_delete(4,-1,time,true,false);
    return 0;
}