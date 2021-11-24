//
// Created by moham on 10/27/2020.
//

#include "MergeSorter.h"

void MergeSorter:: merge1Arr( int a [] , int l , int mid , int h){
    int i = l;
    int j= mid+1;
    int k=l;
    int * b = new int  [h+1];
    while(i<=mid &&j<=h){
        if (a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]= a[j++];

        }
    }

    for (; i <=mid ; i++) {
        b[k++]=a[i];
    }
    for (; j <=h ; j++) {
        b[k++]=a[j];
    }
    for (int q = l; q <=h ; ++q) {
        int x = b[q];
        a[q]=x;

    }
    delete []b;



}

void MergeSorter::sort(int *arr, int size) {
    int p,i,l,mid,h;
    for (p=2; p <=size ; p=p*2) {
        for (i=0; i+p-1<=size ; i=i+p) {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge1Arr(arr,l,mid,h);


        }
    }
    if (p/2<size)
        merge1Arr(arr,0,p/2-1,size-1);
}
