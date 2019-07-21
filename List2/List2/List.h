#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>



typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);

void ListInsert(ListNode* pos, LTDataType x);

void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListDistinct(List* plist);
void  ListMerge(List * plist1,List * plist2);

void ListPrint(List* plist);



#endif