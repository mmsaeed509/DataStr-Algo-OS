#include <iostream>
#include <fstream>
#include "Search.h"
#include "Search.cpp"
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <windows.h>
#include <c++/4.8.3/iomanip>

using namespace std;
bool createCSVFile(const string& name,const pair<vector<long double>,vector<long double>> &p){
    string dir  = "../CSV Sheets/"+name+".CSV";
    std::fstream sheet(dir,std::ios::out);
    for (int i = 0,j=50000; i < 20; ++i,j+=50000) {
        sheet<<j<<", "
             <<p.first.at(i)<<", "
             <<p.second.at(i)<<endl;

    }

    return true;

}
pair<vector<long double>,vector<long double>> linearWorstPerformance( Search<string> &search){

    pair<vector<long double>,vector<long double> >P;
    pair<long double,long double>P2;
    for (int i = 50000,j=0; j < 20; i+=50000,j++) {
      P2= search.testPerformance(i,"linear","worst");
      P.first.push_back(P2.first);
      P.second.push_back(P2.second);

    }
    return P;



}
pair<vector<long double>,vector<long double>> linearAveragePerformance( Search<string> &search){
    pair<vector<long double>,vector<long double> >P;
    pair<long double,long double>P2;
    for (int i = 50000,j=0; j < 20; i+=50000,j++) {
        P2= search.testPerformance(i,"linear","average",1,i);
        P.first.push_back(P2.first);
        P.second.push_back(P2.second);

    }
    return P;
}
pair<vector<long double>,vector<long double>> binaryWorstPerformance( Search<string> &search){
    pair<vector<long double>,vector<long double> >P;
    pair<float,float>P2;
    for (int i = 50000,j=0; j < 20; i+=50000,j++) {
        P2= search.testPerformance(i,"binary","worst");
        P.first.push_back(P2.first);
        P.second.push_back(P2.second);

    }
    return P;


}
pair<vector<long double>,vector<long double>> binaryAveragePerformance( Search<string> &search){
    pair<vector<long double>,vector<long double> >P;
    pair<float,float>P2;
    for (int i = 50000,j=0; j < 20; i+=50000,j++) {
        P2= search.testPerformance(i,"binary","average",1,i);
        P.first.push_back(P2.first);
        P.second.push_back(P2.second);

    }
    return P;
}
void print(const vector<float>& vec){
    for(const auto&i : vec){
        cout<<i<<endl;
    }

}
void print(const pair<vector<long double>,vector<long double>>&P){
    cout<<" words number |   average execution time(mircoSec)    |  average comparison number  | "<<endl;
    for (int i = 0,j=50000; i <20 ; ++i,j+=50000) {
        cout<<j<<"             "<<setprecision(13)<<P.first.at(i)<<setprecision(13)<<"                          "<<P.second.at(i)<<endl;
    }
}
int main() {

    ifstream file;
//    fstream sheet("../excelsheet.csv",ios::out| ios::app);

    file.open("../sortedWords.txt");
   if (!file){
       cerr<<" an error has happened during trying to load the data from the file\n"
             "check that the text file 'sortedWords' is in the project directory"<<endl;
       return 0;
   }

    pair<vector<long double>,vector<long double>> P;

    string choice ;
   Search<string>& search= Search<string>::getInstance();
//   search->sortData(file);
    cout << "loading data from the file.." << endl;
    search.loadData(file);
    cout << "data loaded successfully from the text file ...\n";

   while (true) {

       cout << "0-load the data form another file" << endl;
       cout << "1-search for a word using linear search " << endl;
       cout << "2-search for a word using binary search " << endl;
       cout << "3-test the performance of linear search " << endl;
       cout << "4-test the performance of binary search" << endl;
       cout << "5-exit"<<endl;
       cin >> choice;
       if (choice == "0") {
           string dir;
           cout << "enter the path of the new file :  ";
           cin >> dir;
           file.open(dir);
           if (file) {
               search.loadData(file);
               cout << "data loaded successfully from the text file ...\n";
           } else {
               cerr << "something went wrong" << endl;
           }

       } else if (choice == "1") {
           cout<<"enter the word you are searching for:";
           cin>>choice;
           int index= search.linearSearch(choice);
            if (index==-1){
                cout<<"word is not found"<<endl;
            }else{
                cout<<"the index of the word is "<< index<<endl;
            }

       } else if (choice == "2") {
           cout<<"enter the word you are searching for:";
           cin>>choice;
           int index= search.binarySearch(choice);
           if (index==-1){
               cout<<"word is not found"<<endl;
           }else{
               cout<<"the index of the word is "<< index<<endl;
           }

       } else if (choice == "3") {
           cout<<"1-test the worst performance "<<endl;
           cout<<"2-test the average performance"<<endl;
           cin>>choice;
           if (choice=="1"){
               cout<<"testing ..."<<endl;
               P= linearWorstPerformance(search);
               print(P);
               cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
               cin>>choice;
               if (choice=="y"||choice=="Y"){
                   createCSVFile("LinearWorstPerformance",P);
                   cout<<"file has been create successfully";


               }
           }else if (choice=="2"){
               cout<<"testing ..."<<endl;
               P= linearAveragePerformance(search);
               print(P);
               cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
               cin>>choice;
               if (choice=="y"||choice =="Y"){
                   createCSVFile("LinearAveragePerformance",P);
                   cout<<"file has been create successfully";

               }


           }


       } else if (choice == "4") {
           cout<<"1-test the worst performance "<<endl;
           cout<<"2-test the average performance"<<endl;
           cin>>choice;
           if (choice=="1"){
               cout<<"testing ..."<<endl;
               P = binaryWorstPerformance(search);
               print(P);
               cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
               cin>>choice;
               if (choice=="y"||"Y"){
                   createCSVFile("binaryWorsePerformance",P);
                   cout<<"file has been create successfully";

               }



           }else if(choice=="2"){
               cout<<"testing ..."<<endl;
               P = binaryAveragePerformance(search);
               print(P);
               cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
               cin>>choice;
               if (choice=="y"||"Y"){
                   createCSVFile("binaryAveragePerformance",P);
                   cout<<"file has been create successfully";

               }



           }

       } else if (choice == "5") {
           file.close();
            break;
       }

   }

    return 0;
}