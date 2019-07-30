#ifndef _SORT_H_
#define _SORT_H_
#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))




#include<stdio.h>
#include<Windows.h>

void mergeSort(int *arr, int n);
void printArray(int*arr, int n);
void quickSort(int *arr, int n);


#endif