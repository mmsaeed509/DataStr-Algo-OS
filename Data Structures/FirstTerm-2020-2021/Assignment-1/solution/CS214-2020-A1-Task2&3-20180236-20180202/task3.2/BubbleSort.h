//
// Created by moham on 10/27/2020.
//

#ifndef TASK4_CODE_SELECTIONSORT_H
#define TASK4_CODE_SELECTIONSORT_H
#include "Sorter.h"

class BubbleSort : public Sorter{
private:
    void swap(int &A , int &B);
public:
    BubbleSort()= default;
    void sort(int *arr, int size) override;


};


#endif //TASK4_CODE_SELECTIONSORT_H
