#include <iostream>
#include "bank.h"

int main() {
    Bank bank;
    bank.add_client("Misha","jest","numthere","debit",15000);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    bank.transaction("add",10000,0);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
