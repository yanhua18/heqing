#include"SList.h"

void SListInit(SListNode** pphead)//将头指针进行初始化，所以需要二级指针来接收头指针的地址，对二级指针解引用（头指针）将其的data和next都置为NULL
{
	*pphead = NULL;
	/**pphead = (SListNode*)malloc(sizeof(SListNode));
	(*pphead)->data = 0;
	(*pphead)->next = NULL;*/
}

SListNode* BuySListNode(SLTDataType x)//重新申请一个新的节点，通过tmp来指向这个节点，将其数据部分赋值为x，next置为空
{
	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

SListNode* SListFind(SListNode* phead, SLTDataType x)//找到与x相同的数字的地址并返回，需要一个tmp变量来进行遍历知道找到和x相同的数据的地址返回
{
	SListNode *tmp = phead;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
}

void SListPopFront(SListNode** pphead)//头删,由于需要进行头删操作所以我们就需要定义一个二级指针来指向头phead，定义一个tmp来保存头所指向的目标，再把tmp的地址传给二级指针pphead
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

void SListPushFront(SListNode** pphead, SLTDataType x)//头插，首先要申请一个新的节点，然后让这个新节点的next指向phead，然后再将pphead指向tmp
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)//后插
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void SListEraseAfter(SListNode* pos)//后删
{
	SListNode *tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}

void SListRemove(SListNode** pphead, SLTDataType x)
{
	SListNode *tmp = NULL;
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListRemoveAll(SListNode** pphead, SLTDataType x)
{
	SListNode *tmp = NULL;
	if (*pphead&&(*pphead)->data == x)
	{
		SListPopFront(pphead);
	}
	for (tmp = *pphead; tmp&&tmp->next;)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->next;
		}
	}
}

void SListPrint(SListNode* phead)
{
	SListNode *tmp = phead;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("->%d ", tmp->data);
	}
	tmp = NULL;
}

void SListDestory(SListNode** pphead)//从头结点开始，删除其后的每一个节点，直到只剩下头结点，最后free头结点
{
	if (*pphead == NULL)
	{
		return;
	}
	while ((*pphead)->next)
	{
		SListEraseAfter(*pphead);
	}
	free(*pphead);
	*pphead = NULL;
}

//反转一个单链表
void SListReverse(SListNode** pphead)
{
	SListNode *oldh = *pphead;//定义一个oldh指针指向头，始终指向原有的头结点
	SListNode *head = *pphead;//定义一个head指针指向头，指向不断更新的头结点
	SListNode *tmp = head->next;//tmp始终指向oldh的下一个    
	while (tmp)
	{
		oldh->next = tmp->next;//断开tmp，旧头指向tmp的下一个
		tmp->next = head;//tmp每次指向新的头
		head = tmp;//将head挪到新的头
		tmp = oldh->next;//将tmp挪到旧头oldh的下一个
	}
	*pphead = head;//逆转结束后，将新的头赋给phead
}
void _SListReverse(SListNode** pphead)
{
	SListNode *pre = *pphead;
	SListNode *cur = pre->next;
	SListNode *next = cur;
	pre->next = NULL;//让头变成尾
	while (next)
	{
		next = next->next;//next右移一位
		cur->next = pre;//将原本指向下一位的反转指向上一位
		pre = cur;//将cur给pre
		cur = next;//将next给cur（cur指向next）
	}
	*pphead = pre;
}

//两个链表找他们的第一个公共节点（右对齐）
SListNode *getIntersectionNode(SListNode *headA, SListNode *headB)
{
	SListNode *longerlist=headA;
	SListNode *shorterlist=headB;
	SListNode *cur;
	int lenA=0;
	int lenB=0;
	int gap = 0;
	int i = 0;
	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}
	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);//找到两个链表的长度之差
	if (lenA < lenB)
	{
		longerlist = headB;
		shorterlist = headA;
	}
	for (i = 0; i < gap; i++)//让长的链表走到和短的链表一样的起点
	{
		longerlist = longerlist->next;
	}
	for (; longerlist&&shorterlist; longerlist = longerlist->next, shorterlist = shorterlist->next)//让两链表一起走直到找到两链表相同的地址结束循环
	{
		if (longerlist == shorterlist)
		{
			return longerlist;//返回找到的地址（即这两个链表的第一个公共节点）
		}
	}
	return NULL;
}

//找一个链表入环的第一个节点，如果无环返回NULL
SListNode *detectCycle(SListNode *head)//设置两个指针fast和slow，fast的速度是slow的两倍，当fast与slow相等的时候就是他们的相遇点
{
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}
	}
	for (; fast&&fast->next; fast = fast->next, head = head->next)//从相遇点和从头节点到入环的第一个相遇点的距离是一样的，当找到他们距离相等的点就是入环的第一个节点
	{
		if (fast == head)
		{
			return fast;
		}
	}
}
