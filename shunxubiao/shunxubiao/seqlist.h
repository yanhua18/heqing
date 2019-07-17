#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<windows.h>
#pragma warning (disable:4996)

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *array; // ָ��̬���ٵ�����
	int size; // ��Ч���ݸ���
	int capacity; // �����ռ�Ĵ�С
}SeqList;


void SeqListInit(SeqList* psl, int capacity);
void SeqListDestory(SeqList* psl);
void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);

#endif