//
// Created by moham on 10/27/2020.
//
#include <random>
#include "Search.h"
#include <string>
#include <ctime>
#include <ratio>
#include <iostream>
#include <chrono>
#include <time.h>
using namespace std::chrono;

template<class T>
bool Search<T>::loadData(std::ifstream &file ) {
    string line;
    data.reserve(14804000);
    while (file >> line){
        data.push_back(line);
    }
//    data.shrink_to_fit();
    return true;
}


template<class T>
std::vector<T> Search<T>::getData() {
    return data;
}

template<class T>
int Search<T>::binarySearch(T key) {
    int l=0;
    int r= data.size()-1;
    while (l<=r){
        int m = l +(r-l)/2;
        if (data.at(m)==key)
            return m;
        if (data.at(m)<key)
            l=m+1;
        else
            r=m-1;

    }
    return -1;


}


template<class T>
int Search<T>::linearSearch(T key) {

    if (data.empty())
        return -1;


    for (int i = 0; i <data.size() ; ++i) {
        if (key==data.at(i))
            return i;

    }
    return -1;



}

template<class T>
void Search<T>::sortData(std::ifstream &file) {
    string line;
    while (file>>line){
        list_data.push_back(line);
    }
    list_data.sort();
    std::ofstream newFile("../sortedromeo.txt");
    for (const auto &i :list_data){
        newFile<<i<<std::endl;
    }

}

template<class T>
std::pair<long double , long double > Search<T>::testPerformance(const int &wordsNumber, const string &algo, const string& performance , int X,  int Y) {
//    pair<long double,int>*pair = new std::pair<long double,int>;
    int n=100;

    std::vector<int> randomNums=generateRandInRange(X,Y,n);

     long double avgCompNum{};
     long double avgTime{};
    if (algo=="binary"){
        std::pair<float,float>P;

            for (int i = 0; i < n; i++) {

                auto startTime = high_resolution_clock::now();
                auto start= clock();
                if (performance=="average") {
                    avgCompNum += binarySearchNumberOfComp(data.at(randomNums.at(i)), wordsNumber);
                }else {
                    avgCompNum += binarySearchNumberOfComp("zzzzzzzzzzzzzzzzdata.at(randomNums.at(i))", wordsNumber);

                }
                auto end= clock();
                auto endTime = high_resolution_clock::now();
                auto elapsed = duration_cast<nanoseconds>(endTime - startTime);
//                avgTime+=(long double)  (end-start) / (long double)(CLOCKS_PER_SEC);

                  avgTime += elapsed.count();

            }
            avgTime = avgTime /(long double ) n;
           avgCompNum = avgCompNum / (long double )n;
            P.first = avgTime;
            P.second = avgCompNum;
        return P;

    }else if(algo=="linear"){
        std::pair<float ,float> P;


            for (int i = 0; i < n; i++) {
//                vector<int> randomNums=generateRandInRange(X,Y,100);

                auto startTime = high_resolution_clock::now();
                if (performance=="average") {
                    avgCompNum += linearSearchNumberOfComp(data.at(randomNums.at(i)), wordsNumber);
                }else {
                    avgCompNum += linearSearchNumberOfComp("zzzzdata.at(randomNums.at(i))", wordsNumber);

                }
                auto endTime = high_resolution_clock::now();
//            duration<long double, milli> elapsed = (endTime - startTime);
                auto elapsed = duration_cast<microseconds>(endTime - startTime);


                avgTime += elapsed.count();

            }
            avgTime = avgTime / (long double )n;
            avgCompNum = avgCompNum/ (long double )n;
            P.first = avgTime;
            P.second = avgCompNum;
        return P;

        }






    }






template<class T>
int  Search<T>::binarySearchNumberOfComp(T key,int elementsNum) {


    int l=0;
    int comparisonNum = 0;
    int r= elementsNum;
    while (l<=r){
        comparisonNum++;

        int m = l +(r-l)/2;
        if (data[m]==key) {


            return comparisonNum;
        }
        if (data.at(m)<key)
            l=m+1;
        else
            r=m-1;
    }

    return comparisonNum;

}

template<class T>
int Search<T>::linearSearchNumberOfComp(T key, int elementNum) {
    int comparisonNum{0};
    for (int i = 0; i <elementNum ; ++i) {
        comparisonNum++;
        if (key==data[i]) {

            return comparisonNum;
        }
    }

    return comparisonNum;
}

template<class T>
std::vector<int> Search<T>::generateRandInRange(int min, int max, int size) {

    std::vector<int> vec;
    if (min ==0&&max==0)
        return vec;
    unsigned seed  = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(min,max);

    for (int i = 0; i < size; ++i) {

        int dice_roll = distribution(generator);

        vec.push_back(dice_roll);
//        cout<<vec.at(i)<<"  ";
    }
//    cout<<"\n ---------------------------------------------------------"<<endl;


    return vec;
}
template<class T>

Search<T> &Search<T>::getInstance() {
    return search;
}
template<class T>
Search<T> Search<T> ::search ;
