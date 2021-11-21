cmake_minimum_required(VERSION 3.16)
project(BankSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSystem main.cpp AccountOwner.cpp AccountOwner.h BankAccount.cpp BankAccount.h SavingsAccount.cpp SavingsAccount.h CheckingAccount.cpp CheckingAccount.h)