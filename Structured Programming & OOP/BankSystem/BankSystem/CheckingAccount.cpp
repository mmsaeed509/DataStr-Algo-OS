//
// Created by ozil on 6/6/20.
//

#include "CheckingAccount.h"
#include <iostream>
#include <string>
using namespace std;


double CheckingAccount::withdrawOperation(double Withdraw) {
    double mBalance = getBalance() ;
    mBalance = mBalance - Withdraw ;
    No_of_Withdraw++;
    setBalance(mBalance);
    if (getBalance()<=0){
        setMonthlySerCharges(15.0);
    }
    return 0;

}

double CheckingAccount::monthlyPro() {
    double temp = getNumOfWithdraw() * 0.1;
    setMonthlySerCharges(5+temp);
    double balance = getBalance();
    balance  = balance - getMonthlySerCharges(); 
    return 0 ;
}

CheckingAccount::CheckingAccount() {}

int CheckingAccount::getNoOfWithdraw() const {
    return No_of_Withdraw;
}

void CheckingAccount::setNoOfWithdraw(int noOfWithdraw) {
    No_of_Withdraw = noOfWithdraw;
}
