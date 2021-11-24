//
// Created by moham on 10/27/2020.
//

#ifndef TASK4_CODE_TESTBED_H
#define TASK4_CODE_TESTBED_H
#include "Sorter.h"
#include <string>
using namespace std;
class Sorter;
class Testbed {
private:
    int* generateRandomList( const int &min , const int &max , const int &size);
    double runOnce(Sorter * sorter, int* data , const int & size);
public:

    double runAndAverage(Sorter * sorter,const int &min , const int &max ,const int &size );
    double* runExperiment(Sorter *sorter,int min , int max , int MIN_SIZE, int MAX_SIZE);

};


#endif //TASK4_CODE_TESTBED_H
