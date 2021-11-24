//
// Created by moham on 10/27/2020.
//

#ifndef TASK4_CODE_MERGESORTER_H
#define TASK4_CODE_MERGESORTER_H
#include "Sorter.h"

class MergeSorter : public Sorter  {
private:
    void  merge1Arr( int a [] , int l , int mid , int h);

public:

    void sort(int *arr, int size) override;
};


#endif //TASK4_CODE_MERGESORTER_H
