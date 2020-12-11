#include <iostream>
#include "bank.h"

int main() {
    Bank bank;
    bank.add_client("Misha","jest","numthere","debit",15000);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    bank.transaction("add",10000,0);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    bank.cancel_transaction(0);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    bank.transaction("withdraw",20000,0);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    bank.transaction("withdraw",7000,0);
    std :: cout << '\n' << bank.show_client_status(0) << '\n';
    return 0;
}
