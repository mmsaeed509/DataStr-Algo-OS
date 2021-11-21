#include <iostream>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <vector>
using namespace std;
int main() {

    vector<SavingsAccount> savingAccounts ;
    vector<CheckingAccount> checkingAccounts ;
    string choice , fullName , phoneNumber , National_ID , pass ;
    BankAccount ob_1 ;
    SavingsAccount ob_2 ;
    CheckingAccount ob_3 ;
    float deposit , withdraw ;
    double balance , Annual_interest ;
    int counter_of_checking_account=0 ;
    int counter_of_saving_account=0 ;
    bool saving_status = false;
    bool checking_status = false;

    menu:
    cout<<"**************************\n";
    cout<<"* Welcome In Bank System *\n";
    cout<<"**************************\n\n";
    while (true){

        cout<<" [1] Create Saving Account \n [2] Create Checking Account \n [3] Sign In \n [4] Exit \n";
        cin>>choice;
        cin.ignore();
//-------------------------------- Create Saving Account ----------------------------------------
        if (choice=="1"){
            ob_2.setRole("saving");
            cout<<" Enter Your First & Second Name : \n";
            getline(cin,fullName);
            ob_2.getAccOwner().setFullName(fullName);

            cout<<" Enter Your Phone No. (11 digits) : \n";
            p:
            cin>>phoneNumber;
            cin.ignore();
            if (phoneNumber.size()==11){
                ob_2.getAccOwner().setPhoneNumber(phoneNumber);
            } else{
                cout<<" Enter Your Phone No. Again (11 digits) : \n";
                goto p ;
            }

            cout<<" Enter Your National ID (14 digits) : \n";
            n:
            cin>>National_ID;
            cin.ignore();
            if (National_ID.size()==14){
                ob_2.getAccOwner().setNationalId(National_ID);
            } else{
                cout<<" Enter Your National ID Again (14 digits) : \n";
                goto n;
            }

            cout<<" Enter Your Password \n";
            cin>>pass;
            cin.ignore();
            ob_2.getAccOwner().setPassWord(pass);
            cout<<" Enter Money \n";
            cin>>balance;
            cin.ignore();
            ob_2.setBalance(balance);
            cout<<"Annual interest rate \n";
            cin>>Annual_interest;
            cin.ignore();
            ob_2.setAnnualRate(Annual_interest);
            savingAccounts.push_back(ob_2);
        }
//------------------------------- Create Checking Account -----------------------------------------

        if (choice=="2"){
            ob_3.setRole("checking");
            cout<<" Enter Your First & Second Name : \n";
            getline(cin,fullName);
            ob_3.getAccOwner().setFullName(fullName);

            cout<<" Enter Your Phone No. (11 digits) : \n";
            p2:
            cin>>phoneNumber;
            cin.ignore();
            if (phoneNumber.size()==11){
                ob_3.getAccOwner().setPhoneNumber(phoneNumber);
            } else{
                cout<<" Enter Your Phone No. Again (11 digits) : \n";
                goto p2 ;
            }

            cout<<" Enter Your National ID (14 digits) : \n";
            n2:
            cin>>National_ID;
            cin.ignore();
            if (National_ID.size()==14){
                ob_3.getAccOwner().setNationalId(National_ID);
            } else{
                cout<<" Enter Your National ID Again (14 digits) : \n";
                goto n2;
            }

            cout<<" Enter Your Password \n";
            cin>>pass;
            cin.ignore();
            ob_3.getAccOwner().setPassWord(pass);
            cout<<" Enter Money \n";
            cin>>balance;
            cin.ignore();
            ob_3.setBalance(balance);
            cout<<"Annual interest rate \n";
            cin>>Annual_interest;
            cin.ignore();
            ob_3.setAnnualRate(Annual_interest);
            checkingAccounts.push_back(ob_3);

        }


//-------------------- Sign In ----------------------------------------------------

        else if (choice=="3") {

            //------ Loop -------------------------
            while (true) {

                if (checkingAccounts.empty() && savingAccounts.empty()) {
                    cout << " There Are No Accounts Exists \n\n";
                    goto menu;
                }


                    //----- else ---------------------------------------------
                else {

                    cout<<"*************************\n";
                    cout<<"* [1]  Saving Account   *"<<endl;
                    cout<<"* [2]  Checking Account *"<<endl;
                    cout<<"* [3]  Return Home Page *"<<endl;
                    cout<<"*************************\n";
                    string cho;
                    cin >> cho;
                    cin.ignore();

                    //---- Saving Account -------------------------------
                    if (cho == "1") {

                        cout << " Enter Your Phone No. \n";
                        cin >> phoneNumber;
                        cin.ignore();
                        cout << " Enter Your Password \n";
                        cin >> pass;
                        cin.ignore();


                        for (int i = 0; i < savingAccounts.size(); ++i) {

                            if (phoneNumber == savingAccounts.at(i).getAccOwner().getPhoneNumber() &&
                                pass == savingAccounts.at(i).getAccOwner().getPassWord() &&
                                savingAccounts.at(i).getRole() == "saving") {
                                counter_of_saving_account = i;
                                saving_status = true;
                                break;

                            }

                        }

                        //------ Home Page -------------------
                        if (saving_status) {

                            ozil2 :
                            cout << "***************************************\n";
                            cout << "* Welcome In Saving Account Home Page *\n";
                            cout << "***************************************\n\n";
                            cout
                                    << " [1] View Your Account Details \n [2] Deposit \n [3] Withdraw \n [4] Pay For service charges \n "
                                       "[5] Update interest \n [6] Update Person Details \n [Press Any Kay] Return To Main Page \n ";
                            cin >> choice;
                            cin.ignore();
                            //____________________ View Data _________________________________
                            if (choice == "1") {

                                cout << endl << endl;
                                cout << "*******************************************************\n";
                                cout << " Your Name : "
                                     << savingAccounts.at(counter_of_saving_account).getAccOwner().getFullName()
                                     << endl;
                                cout << " Your Phone No. : "
                                     << savingAccounts.at(counter_of_saving_account).getAccOwner().getPhoneNumber()
                                     << endl;
                                cout << " Your National Id : "
                                     << savingAccounts.at(counter_of_saving_account).getAccOwner().getNationalId()
                                     << endl;
                                cout << " Your Balance : " << savingAccounts.at(counter_of_saving_account).getBalance()
                                     << endl;
                                cout << " Your Password : "
                                     << savingAccounts.at(counter_of_saving_account).getAccOwner().getPassWord()
                                     << endl;
                                cout << " Your Annual interest rate : "
                                     << savingAccounts.at(counter_of_saving_account).getAnnualRate() << endl;
                                cout << " Your Role : " << savingAccounts.at(counter_of_saving_account).getRole()
                                     << endl;
                                cout << " No. Of Deposits : "
                                     << savingAccounts.at(counter_of_saving_account).getNoOfDeposit() << endl;
                                cout << " No. Of WithDraws : "
                                     << savingAccounts.at(counter_of_saving_account).getNoOfWithdraw() << endl;
                                cout << "*******************************************************\n\n";
                                goto ozil2;

                            }
                                //-------------- Deposit Saving Account ------------------------------------------------------
                            else if (choice == "2") {
                                cout << " Enter The Amount of Deposit \n";
                                cin >> deposit;
                                cin.ignore();
                                savingAccounts.at(counter_of_saving_account).depositOperation(deposit);
                                goto ozil2;
                            }

                                //--------------- Withdraw Saving Account ------------------------------------------------------

                            else if (choice == "3") {
                                if (savingAccounts.at(counter_of_saving_account).getBalance() <= 25) {
                                    savingAccounts.at(counter_of_saving_account).setStatus(false);
                                } else {
                                    savingAccounts.at(counter_of_saving_account).setStatus(true);
                                }

                                if (savingAccounts.at(counter_of_saving_account).isStatus() == true) {
                                    cout << " Enter withdraw \n";
                                    cin >> withdraw;
                                    cin.ignore();
                                    savingAccounts.at(counter_of_saving_account).withdrawOperation(withdraw);
                                } else {
                                    cout << " Can't Do This Operation Because Your Balance is : "
                                         << savingAccounts.at(counter_of_saving_account).getBalance() << " $\n";
                                }
                                goto ozil2;
                            }

                                //----------------- Update interest & Pay For service charges ----------------------------------------------
                            else if (choice == "4") {

                                int counter = savingAccounts.at(counter_of_saving_account).getNoOfWithdraw();
                                double m_balance, ser_charges = 1;
                                m_balance = savingAccounts.at(counter_of_saving_account).getBalance();
                                if (savingAccounts.at(counter_of_saving_account).getNoOfWithdraw() > 4) {
                                    counter -= 4;
                                    for (int j = 0; j < counter; ++j) {
                                        m_balance = m_balance - ser_charges;
                                        savingAccounts.at(counter_of_saving_account).setBalance(m_balance);
                                    }
                                    savingAccounts.at(counter_of_saving_account).setNoOfDeposit(0);
                                    savingAccounts.at(counter_of_saving_account).setNoOfWithdraw(0);

                                } else {
                                    cout << " No Update interest & Pay For service charges \n ";
                                }

                                goto ozil2;
                            }
                                //------------------- Update interest ---------------------------------------------
                            else if (choice == "5") {
                                savingAccounts.at(counter_of_saving_account).Calc_Monthly_Interest();
                                goto ozil2;
                            }
                            //---------- Update interest --------------------------------


                            //------ Update Person Details ------------------
                            else if (choice == "6"){
                                string update_name , update_phone , update_pass ;

                                cout<<" Enter Your Name : \n";
                                getline(cin,update_name);
                                savingAccounts.at(counter_of_saving_account).getAccOwner().setFullName(update_name);

                                cout<<" Enter Your Phone No. (11 digits) : \n";
                                p3:
                                cin>>update_phone;
                                cin.ignore();
                                if (update_phone.size()==11){
                                    savingAccounts.at(counter_of_saving_account).getAccOwner().setPhoneNumber(update_phone);
                                } else{
                                    cout<<" Enter Your Phone No. Again (11 digits) : \n";
                                    goto p3 ;
                                }

                                cout<<" Enter New Password : \n";
                                cin>>update_pass;cin.ignore();
                                savingAccounts.at(counter_of_saving_account).getAccOwner().setPassWord(update_pass);

                            }
                            //---------- Update Person Details ------------------

                                //------------- Return To Home Page -----------------------------------------------
                            else {
                                goto menu;
                            }
                            //---------------------------------

                        }
                        //------ Home Page ------------------
                        else{
                            cout<<" Wrong Password \n";
                        }

                    }
                        //------- Saving Account --------------------------



                        //----- Checking Account ----------------
                    else if (cho == "2") {

                        cout << " Enter Your Phone No. \n";
                        cin >> phoneNumber;
                        cin.ignore();
                        cout << " Enter Your Password \n";
                        cin >> pass;
                        cin.ignore();

                        for (int i = 0; i < checkingAccounts.size(); ++i) {

                            if (phoneNumber == checkingAccounts.at(i).getAccOwner().getPhoneNumber() &&
                                pass == checkingAccounts.at(i).getAccOwner().getPassWord()
                                && checkingAccounts.at(i).getRole() == "checking") {
                                counter_of_checking_account = i;
                                checking_status = true;
                                break;
                            }
                        }

                        //------ Home Page --------
                        if (checking_status) {

                            ozil:
                            cout << "******************************************\n";
                            cout << "*  Welcome In Checking Account Home Page *\n";
                            cout << "******************************************\n\n";
                            cout
                                    << " [1] View Your Account Details \n [2] Deposit \n [3] Withdraw \n [4] Pay For service charges \n "
                                       "[5] Update interest \n [6] Update Person Details \n [Press Any Kay] Return To Main Page \n";
                            cin >> choice;
                            cin.ignore();

                            //_______________View Data ________________________________________________________
                            if (choice == "1") {

                                cout << endl << endl;
                                cout << "*******************************************************\n";
                                cout << " Your Name : "
                                     << checkingAccounts.at(counter_of_checking_account).getAccOwner().getFullName()
                                     << endl;
                                cout << " Your Phone No. : "
                                     << checkingAccounts.at(counter_of_checking_account).getAccOwner().getPhoneNumber()
                                     << endl;
                                cout << " Your National Id : "
                                     << checkingAccounts.at(counter_of_checking_account).getAccOwner().getNationalId()
                                     << endl;
                                cout << " Your Balance : "
                                     << checkingAccounts.at(counter_of_checking_account).getBalance() << endl;
                                cout << " Your Password : "
                                     << checkingAccounts.at(counter_of_checking_account).getAccOwner().getPassWord()
                                     << endl;
                                cout << " Your Annual interest rate : "
                                     << checkingAccounts.at(counter_of_checking_account).getAnnualRate() << endl;
                                cout << " Your Role : " << checkingAccounts.at(counter_of_checking_account).getRole()
                                     << endl;
                                cout << " No. Of Deposits : "
                                     << checkingAccounts.at(counter_of_checking_account).getNumOfDepositMonth() << endl;
                                cout << " No. Of WithDraws : "
                                     << checkingAccounts.at(counter_of_checking_account).getNoOfWithdraw() << endl;
                                cout << "*******************************************************\n\n";
                                goto ozil;

                            }

                                //--------------- Deposit Checking Account -------------------------------------------------------------------
                            else if (choice == "2") {
                                cout << " Enter Your Deposit \n";
                                cin >> deposit;
                                checkingAccounts.at(counter_of_checking_account).depositOperation(deposit);
                                goto ozil;
                            }

                                //--------------- Withdraw Checking Account -------------------------------------------------------------------
                            else if (choice == "3") {
                                cout << " Enter Your Withdraw \n";
                                cin >> withdraw;
                                checkingAccounts.at(counter_of_checking_account).withdrawOperation(withdraw);
                                goto ozil;
                            }

                                //----------------- Pay For service charges ----------------------------------------------
                            else if (choice == "4") {
                                double temp = checkingAccounts.at(counter_of_checking_account).getNumOfWithdraw();
                                temp = temp * 0.1;
                                double m_balance = checkingAccounts.at(counter_of_checking_account).getBalance();
                                double mo_proc = 5 + temp;
                                if (checkingAccounts.at(counter_of_checking_account).getNumOfWithdraw() != 0) {

                                    m_balance = m_balance - mo_proc;
                                    checkingAccounts.at(counter_of_checking_account).setBalance(m_balance);
                                    checkingAccounts.at(counter_of_checking_account).setNoOfWithdraw(0);

                                }

                                goto ozil;
                            }
                                //------------------------------------------ Update interest ---------------------------------------------
                            else if (choice == "5") {
                                checkingAccounts.at(counter_of_checking_account).Calc_Monthly_Interest();
                                goto ozil;
                            }
                            //------------------------------------------ Update interest ---------------------------------------------


                                //------ Update Person Details ------------------
                            else if (choice == "6"){

                                string update_name , update_phone , update_pass ;

                                cout<<" Enter Your Name : \n";
                                getline(cin,update_name);
                                checkingAccounts.at(counter_of_checking_account).getAccOwner().setFullName(update_name);

                                cout<<" Enter Your Phone No. (11 digits) : \n";
                                p4:
                                cin>>update_phone;
                                cin.ignore();
                                if (update_phone.size()==11){
                                    checkingAccounts.at(counter_of_checking_account).getAccOwner().setPhoneNumber(update_phone);
                                } else{
                                    cout<<" Enter Your Phone No. Again (11 digits) : \n";
                                    goto p4 ;
                                }

                                cout<<" Enter New Password : \n";
                                cin>>update_pass;cin.ignore();
                                checkingAccounts.at(counter_of_checking_account).getAccOwner().setPassWord(update_pass);

                            }
                                //---------- Update Person Details ------------------




                                //---------- Return To Home Page ----------------------------------------------------------------
                            else {
                                goto menu;
                            }
                            //---------------------------------


                        }
                        //------ Home Page --------
                        else{
                            cout<<" Wrong Password \n";
                        }


                    }
                        //------ Checking Account ----------

                    else if (cho == "3") {
                        goto menu;
                    } else {

                        cout << " Invalid Choice  \n";
                    }


                }
                //-------- else ---------------


            }
            //----- Loop -----------------------------
        }


//---------------------------- Exit --------------------------------------------
        else if (choice=="4"){
            cout<<"\n Good Bye ^_^ "<<"\n\n\n";
            exit(0);

        }
    }

//------------------------------------------------------------------------

    return 0;
}
