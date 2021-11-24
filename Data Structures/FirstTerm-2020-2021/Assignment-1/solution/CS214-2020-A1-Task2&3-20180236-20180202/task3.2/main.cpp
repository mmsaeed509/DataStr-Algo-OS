#include <iostream>
#include "Testbed.h"
#include "MergeSorter.h"
#include "BubbleSort.h"
#include <fstream>
using namespace std;
bool createCSVFile(const string& name,double * arr , int min ,int max) {
    string dir = "../CSV Sheets/" + name + ".CSV";
    fstream sheet(dir, ios::out | ios::app);
    int step = max / 20;
    for (int i = 0, j = min; j < max; ++i, j += step) {
        sheet <<j << ", "
              << arr[i] << endl;

    }
}

void print(int min , int max , double *arr){
    int step = max/20;
    cout<<" set size |   execution time (mileSCE) "<<endl;
    for (int i =min,j=0 ; i <max ; i+=step,j++) {
        cout<<i<<"               "<<arr[j]<<endl;
    }




}
int main() {
    Testbed testbed ;
    string choice ;
    while (true) {
        int min , max,MAX_SIZE,MIN_SIZE;
        cout << "1- run an experiment on bubble sort " << endl;
        cout << "2- run an experiment on merge sort " << endl;
        cout << "3- exit" <<endl;
        cin >> choice;
        if (choice == "1") {
            BubbleSort *sort = new BubbleSort;
            cout<<"enter the range of number that are going to be generated randomly "<<endl;
            cout<<"min: ";
            cin>>min;
            cout<<"max: ";
            cin>>max;
            cout<<"enter the minimum number of the dataset : ";
            cin>>MIN_SIZE;
            cout<<"enter the maximum number of the dateset :";
            cin>>MAX_SIZE;
            cout<<"running the experiment please wait for results ... "<<endl;
            double *arr= testbed.runExperiment(sort,min,max,MIN_SIZE,MAX_SIZE);
            print(MIN_SIZE,MAX_SIZE,arr);
            cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
            cin>>choice;
            if (choice=="y"||choice=="Y"){
                createCSVFile("bubbleSortExperiment",arr,MIN_SIZE,MAX_SIZE);
                cout<<"file has been create successfully";

            }
        }else if (choice=="2"){
            MergeSorter *sort = new MergeSorter;
            cout<<"enter the range of number that are going to be generated randomly "<<endl;
            cout<<"min: ";
            cin>>min;
            cout<<"max: ";
            cin>>max;
            cout<<"enter the minimum number of the dataset : ";
            cin>>MIN_SIZE;
            cout<<"enter the maximum number of the dateset :";
            cin>>MAX_SIZE;
            cout<<"running the experiment please wait for results ... "<<endl<<endl;
            double *arr= testbed.runExperiment(sort,min,max,MIN_SIZE,MAX_SIZE);
            print(MIN_SIZE,MAX_SIZE,arr);
            cout<<"do you want save this data into CSV file ?(y/n)"<<endl;
            cin>>choice;
            if (choice=="y"||choice=="Y"){
                createCSVFile("MergeSortExperiment",arr,MIN_SIZE,MAX_SIZE);
                cout<<"file has been create successfully";

            }






        }else if(choice=="3"){
            break;
        }
    }
    return 0;
}
