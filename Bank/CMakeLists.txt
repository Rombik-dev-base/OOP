cmake_minimum_required(VERSION 3.15)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp bank.cpp bank.h client.cpp client.h accounts/account.cpp accounts/account.h accounts/debit.cpp accounts/debit.h accounts/deposit.cpp accounts/deposit.h accounts/credit.cpp accounts/credit.h)