//
// Created by ozil on 6/6/20.
//

#ifndef BANKSYSTEM_BANKACCOUNT_H
#define BANKSYSTEM_BANKACCOUNT_H
#include "AccountOwner.h"
#include <iostream>
#include <string>
using namespace std;

class BankAccount  {


private:
    int NumOfDepositMonth = 0,  NumOfWithdraw = 0 ;
    AccountOwner accOwner;
    string Role ;
    double balance , annualRate , monthlySerCharges;

public:

    const string &getRole() const;

    void setRole(const string &role);
    AccountOwner &getAccOwner() ;

    void setAccOwner(const AccountOwner &accOwner);

    BankAccount(const AccountOwner &accOwner, double balance, double annualRate);

    double getBalance() const;
    double getMonthlySerCharges() const;
    void setMonthlySerCharges(double monthlySerCharges);


    BankAccount();





    //----------------------Deposit Function ------------------------

    virtual double depositOperation(double Deposit);

    //----------------------Withdraw Function ------------------------

    virtual double withdrawOperation(double Withdraw);

    //----------------------Calculate Monthly_Interest Function ------------------------
    virtual  double Calc_Monthly_Interest();


    virtual double monthlyPro();


    void setBalance(double balance);

    void setAnnualRate(double annualRate);

    double getAnnualRate() const;

    int getNumOfDepositMonth() const;

    int getNumOfWithdraw() const;
};


#endif //BANKSYSTEM_BANKACCOUNT_H