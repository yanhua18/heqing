#ifndef _HEAP_H_
#define _HEAP_H_
#define MAXSIZE 100
#include<stdio.h>
#include<Windows.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType *_a;
	int _size;
	int _capacity;
}Heap;

int HeapSize_(Heap *hp);
void HeapInit(Heap *hp, HPDataType *a, int n);
void HeapDestory(Heap *hp);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
int HeapTop(Heap *hp);
HPDataType HeapEmpty(Heap *hp);

// ∂—≈≈–Ú
void HeapSort(Heap *hp);

void HeapPrint(Heap *hp);



#endif