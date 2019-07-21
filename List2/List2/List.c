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

void ListPushBack(List* plist, LTDataType x)//尾插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_prev;
	cur->_data = x;
	tmp->_next = cur;
	cur->_prev = tmp;
	cur->_next = plist->_head;
	plist->_head->_prev = cur;
}

void ListPopBack(List* plist)//尾删
{
	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)//头插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_next;
	cur->_data = x;
	cur->_next = tmp;
	tmp->_prev = cur;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}

void ListPopFront(List* plist)//头删
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

void ListInsertAfter(ListNode* pos, LTDataType x)//后插
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

//删除链表中重复的数
void ListDistinct(List* plist)
{
	ListNode *cur = plist->_head->_next;//由于头的data为随机值，因此不需要遍历头，从头的下一位开始遍历一直遍历到头的前一位
	while (cur != plist->_head)
	{
		if (cur->_data == cur->_next->_data)//当cur与cur->next的值相同时，就删掉后面的那个节点直到前后不相等是再进行cur前移
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}

//将两个有序链表合并为一个有序链表
void  ListMerge(List * plist1, List * plist2)
{
	ListNode *cur1 = plist1->_head->_next;
	ListNode *cur2 = plist2->_head->_next;
	ListNode * tmp1, *tmp2;
	while(cur1 != plist1->_head && cur2 != plist2->_head)//跳出循环的出口当其中有一条链走到了头
	{
		if (cur1->_data > cur2->_data)//当cur1比cur2大时，将cur2所指的节点前插到cur1中
		{
			tmp1 = cur1->_prev; //由于CUR1会被修改，这里做一个备份******必须要做一个备份，不然在移动cur位置时会出问题
			tmp2 = cur2->_next; //由于CUR2未来会被修改，这里做一个备份******必须要做一个备份，不然在移动cur位置时会出问题

			cur1->_prev = cur2; // cur1左手拉起cur2
			cur2->_next = cur1; // cur2右手拉起cur1，两手相连
			tmp1->_next = cur2; // tmp1（cur1的prev）的右手拉起cur2
			cur2->_prev = tmp1; // cur2的左手拉起tmp1，两手相连

			cur2 = tmp2; // cur2找到它的下一个节点
		}
		else
		{
			cur1 = cur1->_next;
		}
	}//如果list2走到了头就表示其所有的节点都已经插入到list1中了，这时只需要释放头就行
	if (cur1 == plist1->_head)//当list1走到头儿list2还未结束时，需要把list2剩余的节点接到list1后面。
	{
		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;
		plist2->_head->_prev->_next = cur1;
		cur1->_prev = plist2->_head->_prev;
	}
	free(plist2->_head);//释放掉list2的头
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