//
// Created by ozil on 6/6/20.
//

#ifndef BANKSYSTEM_ACCOUNTOWNER_H
#define BANKSYSTEM_ACCOUNTOWNER_H
#include <iostream>
#include <string>
using namespace std;
class AccountOwner {
private:
    string fullName ;
    string phoneNumber ;
    string National_ID ;
    string PassWord ;


public:
    AccountOwner();

    const string &getFullName() const;

    void setFullName(const string &fullName);

    const string &getPhoneNumber() const;

    void setPhoneNumber(const string &phoneNumber);

    const string &getNationalId() const;

    void setNationalId(const string &nationalId);

    const string &getPassWord() const;

    void setPassWord(const string &passWord);


};


#endif //BANKSYSTEM_ACCOUNTOWNER_H