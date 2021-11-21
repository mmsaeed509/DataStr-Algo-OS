//
// Created by ozil on 6/6/20.
//

#include "SavingsAccount.h"
#include <iostream>
#include <string>
using namespace std;

double SavingsAccount::withdrawOperation(double Withdraw) {
    if (getBalance()<=25){
        setStatus(false);

    } else{
        setStatus(true);
        if (getBalance() < Withdraw + 25){
            cout << "can't withdraw because your balance is $" << getBalance() << endl;
        } else{
            double mBalance = getBalance();
            mBalance = mBalance - Withdraw ;
            setBalance(mBalance);
            No_Of_Withdraw++;
        }
    }
    return getBalance();
}


double SavingsAccount::depositOperation(double Deposit) {

    double mBalance = getBalance();
    mBalance = mBalance + Deposit ;
    setBalance(mBalance);
    No_Of_Deposit++;

    if (getBalance()>25){
        setStatus(true);

    } else{
        setStatus(false);
    }
    return getBalance();
}


double SavingsAccount::monthlyPro() {

    if (getNoOfWithdraw()>4){
        setMonthlySerCharges(1);
        double balance = getBalance() - getMonthlySerCharges();
        setBalance(balance);
        setNoOfWithdraw(0);
    } else{
        return 0;
    }

    return 0;
}


bool SavingsAccount::isStatus() const {
    return status;
}

void SavingsAccount::setStatus(bool status) {
    SavingsAccount::status = status;
}

int SavingsAccount::getNoOfWithdraw() const {
    return No_Of_Withdraw;
}

void SavingsAccount::setNoOfWithdraw(int noOfWithdraw) {
    No_Of_Withdraw = noOfWithdraw;
}

int SavingsAccount::getNoOfDeposit() const {
    return No_Of_Deposit;
}

void SavingsAccount::setNoOfDeposit(int noOfDeposit) {
    No_Of_Deposit = noOfDeposit;
}



