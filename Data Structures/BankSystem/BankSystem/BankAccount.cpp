//
// Created by ozil on 6/6/20.
//

#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;


BankAccount::BankAccount() {

    this->annualRate = 0.0;
}

int BankAccount::getNumOfDepositMonth() const {
    return NumOfDepositMonth;
}

int BankAccount::getNumOfWithdraw() const {
    return NumOfWithdraw;
}



//----------------------Deposit Function ------------------------

double BankAccount::depositOperation(double Deposit) {
    balance = balance + Deposit;
    NumOfDepositMonth++;
    return balance;
}

//----------------------Withdraw Function ------------------------

double BankAccount::withdrawOperation(double Withdraw) {
    balance=balance-Withdraw;
    NumOfWithdraw++;
    return balance;
}



double BankAccount::Calc_Monthly_Interest() {

    double monthly_Interest_Rate = 0.0, monthly_Interest = 0.0;
    monthly_Interest_Rate = annualRate / 12;
    monthly_Interest = balance * monthly_Interest_Rate;
    balance += monthly_Interest;
    return 0;

}
double BankAccount::monthlyPro() {
    balance-=monthlySerCharges;
    return 0;

}

double BankAccount::getMonthlySerCharges() const {
    return monthlySerCharges;
}

void BankAccount::setMonthlySerCharges(double monthlySerCharges) {
    BankAccount::monthlySerCharges = monthlySerCharges;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    BankAccount::balance = balance;
}



double BankAccount::getAnnualRate() const {
    return annualRate;
}



void BankAccount::setAnnualRate(double annualRate) {
    BankAccount::annualRate = annualRate;
}

AccountOwner &BankAccount::getAccOwner()  {
    return accOwner;
}

void BankAccount::setAccOwner(const AccountOwner &accOwner) {
    BankAccount::accOwner = accOwner;
}

BankAccount::BankAccount(const AccountOwner &accOwner, double balance, double annualRate) : accOwner(accOwner),
                                                                                            balance(balance),
                                                                                            annualRate(annualRate) {}

const string &BankAccount::getRole() const {
    return Role;
}

void BankAccount::setRole(const string &role) {
    Role = role;
}





