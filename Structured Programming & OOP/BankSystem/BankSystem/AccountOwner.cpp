//
// Created by ozil on 6/6/20.
//

#include "AccountOwner.h"
#include <iostream>
#include <string>
using namespace std;

AccountOwner::AccountOwner() {

    fullName = " ";
    National_ID = " ";
}

const string &AccountOwner::getPassWord() const {
    return PassWord;
}

void AccountOwner::setPassWord(const string &passWord) {
    PassWord = passWord;
}

const string &AccountOwner::getFullName() const {
    return fullName;
}

void AccountOwner::setFullName(const string &fullName) {
    AccountOwner::fullName = fullName;
}

const string &AccountOwner::getPhoneNumber() const {
    return phoneNumber;
}

void AccountOwner::setPhoneNumber(const string &phoneNumber) {
    AccountOwner::phoneNumber = phoneNumber;
}

const string &AccountOwner::getNationalId() const {
    return National_ID;
}

void AccountOwner::setNationalId(const string &nationalId) {
    National_ID = nationalId;
}
//
// Created by ozil on 6/12/20.
//

#include "AccountOwner.h"
