//
// Created by ozil on 6/6/20.
//

#ifndef BANKSYSTEM_CHECKINGACCOUNT_H
#define BANKSYSTEM_CHECKINGACCOUNT_H

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class CheckingAccount : public BankAccount {
int No_of_Withdraw = 0 ;
public:
    int getNoOfWithdraw() const;

    void setNoOfWithdraw(int noOfWithdraw);

public:
    CheckingAccount();


    double withdrawOperation(double Withdraw) override;

    double monthlyPro() override;


};


#endif //BANKSYSTEM_CHECKINGACCOUNT_H