//
// Created by moham on 10/27/2020.
//

#include "BubbleSort.h"

void BubbleSort::sort(int *arr, int size) {
    bool flag= false;
    for (int i = 0; i < size-1; ++i) {
        flag = false;
        for (int j = 0; j <size-i-1 ; ++j) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j + 1]);
                flag = true;
            }
        }
        if (!flag){
            break;
        }
    }
}

void BubbleSort::swap(int &A, int &B) {
    {
        int temp;
        temp=A;
        A=B;
        B=temp;

    }

}
