//
// Created by ozil on 6/6/20.
//

#ifndef BANKSYSTEM_SAVINGSACCOUNT_H
#define BANKSYSTEM_SAVINGSACCOUNT_H

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

class SavingsAccount : public BankAccount {
private:
    bool status;

public:
    bool isStatus() const;

    void setStatus(bool status);

    int getNoOfWithdraw() const;

    void setNoOfWithdraw(int noOfWithdraw);

    int getNoOfDeposit() const;

    void setNoOfDeposit(int noOfDeposit);

private:
// Active = true   Inactive = false
    int No_Of_Withdraw=0 ,No_Of_Deposit=0;
public:

    double withdrawOperation(double Withdraw) override;

    double depositOperation(double Deposit) override;

    double monthlyPro() override;


};


#endif //BANKSYSTEM_SAVINGSACCOUNT_H