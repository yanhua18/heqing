#ifndef _SLIST_H_
#define _SLIST_H_

#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<math.h>
#pragma warning(disable:4996)


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;


void SListInit(SListNode** pphead);

void SListDestory(SListNode** pphead);

SListNode* BuySListNode(SLTDataType x);

void SListPushFront(SListNode** pphead, SLTDataType x);

void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);

void SListInsertAfter(SListNode* pos, SLTDataType x);

void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** pphead, SLTDataType x);

void SListPrint(SListNode* phead);

void SListReverse(SListNode** pphead);
void _SListReverse(SListNode** pphead);

#endif