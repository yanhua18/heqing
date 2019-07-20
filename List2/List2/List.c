#include"List.h"

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)//Î²²å
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_prev;
	cur->_data = x;
	tmp->_next = cur;
	cur->_prev = tmp;
	cur->_next = plist->_head;
	plist->_head->_prev = cur;
}

void ListPopBack(List* plist)//Î²É¾
{
	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)//Í·²å
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_next;
	cur->_data = x;
	cur->_next = tmp;
	tmp->_prev = cur;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}

void ListPopFront(List* plist)//Í·É¾
{
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void ListInsertAfter(ListNode* pos, LTDataType x)//ºó²å
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next->_prev = cur;
	pos->_next = cur;
	cur->_prev = pos;
}

void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode * tmp = pos->_prev;

	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
}

void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void ListRemove(List* plist, LTDataType x)
{
	ListNode *cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}

void ListPrint(List* plist)
{
	ListNode *tmp = plist->_head;
	printf("head");
	for (tmp = plist->_head->_next; tmp != plist->_head; tmp = tmp->_next)
	{
		printf("->%d ", tmp->_data);
	}
	printf("->head");
}