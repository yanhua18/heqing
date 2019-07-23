#include"SList.h"

void SListInit(SListNode** pphead)//��ͷָ����г�ʼ����������Ҫ����ָ��������ͷָ��ĵ�ַ���Զ���ָ������ã�ͷָ�룩�����data��next����ΪNULL
{
	*pphead = NULL;
	/**pphead = (SListNode*)malloc(sizeof(SListNode));
	(*pphead)->data = 0;
	(*pphead)->next = NULL;*/
}

SListNode* BuySListNode(SLTDataType x)//��������һ���µĽڵ㣬ͨ��tmp��ָ������ڵ㣬�������ݲ��ָ�ֵΪx��next��Ϊ��
{
	SListNode *tmp = (SListNode*)malloc(sizeof(SListNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

SListNode* SListFind(SListNode* phead, SLTDataType x)//�ҵ���x��ͬ�����ֵĵ�ַ�����أ���Ҫһ��tmp���������б���֪���ҵ���x��ͬ�����ݵĵ�ַ����
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

void SListPopFront(SListNode** pphead)//ͷɾ,������Ҫ����ͷɾ�����������Ǿ���Ҫ����һ������ָ����ָ��ͷphead������һ��tmp������ͷ��ָ���Ŀ�꣬�ٰ�tmp�ĵ�ַ��������ָ��pphead
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode *tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

void SListPushFront(SListNode** pphead, SLTDataType x)//ͷ�壬����Ҫ����һ���µĽڵ㣬Ȼ��������½ڵ��nextָ��phead��Ȼ���ٽ�ppheadָ��tmp
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)//���
{
	SListNode *tmp = BuySListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}

void SListEraseAfter(SListNode* pos)//��ɾ
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

void SListDestory(SListNode** pphead)//��ͷ��㿪ʼ��ɾ������ÿһ���ڵ㣬ֱ��ֻʣ��ͷ��㣬���freeͷ���
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

//��תһ��������
void SListReverse(SListNode** pphead)
{
	SListNode *oldh = *pphead;//����һ��oldhָ��ָ��ͷ��ʼ��ָ��ԭ�е�ͷ���
	SListNode *head = *pphead;//����һ��headָ��ָ��ͷ��ָ�򲻶ϸ��µ�ͷ���
	SListNode *tmp = head->next;//tmpʼ��ָ��oldh����һ��    
	while (tmp)
	{
		oldh->next = tmp->next;//�Ͽ�tmp����ͷָ��tmp����һ��
		tmp->next = head;//tmpÿ��ָ���µ�ͷ
		head = tmp;//��headŲ���µ�ͷ
		tmp = oldh->next;//��tmpŲ����ͷoldh����һ��
	}
	*pphead = head;//��ת�����󣬽��µ�ͷ����phead
}
void _SListReverse(SListNode** pphead)
{
	SListNode *pre = *pphead;
	SListNode *cur = pre->next;
	SListNode *next = cur;
	pre->next = NULL;//��ͷ���β
	while (next)
	{
		next = next->next;//next����һλ
		cur->next = pre;//��ԭ��ָ����һλ�ķ�תָ����һλ
		pre = cur;//��cur��pre
		cur = next;//��next��cur��curָ��next��
	}
	*pphead = pre;
}

//�������������ǵĵ�һ�������ڵ㣨�Ҷ��룩
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
	gap = abs(lenA - lenB);//�ҵ���������ĳ���֮��
	if (lenA < lenB)
	{
		longerlist = headB;
		shorterlist = headA;
	}
	for (i = 0; i < gap; i++)//�ó��������ߵ��Ͷ̵�����һ�������
	{
		longerlist = longerlist->next;
	}
	for (; longerlist&&shorterlist; longerlist = longerlist->next, shorterlist = shorterlist->next)//��������һ����ֱ���ҵ���������ͬ�ĵ�ַ����ѭ��
	{
		if (longerlist == shorterlist)
		{
			return longerlist;//�����ҵ��ĵ�ַ��������������ĵ�һ�������ڵ㣩
		}
	}
	return NULL;
}

//��һ�������뻷�ĵ�һ���ڵ㣬����޻�����NULL
SListNode *detectCycle(SListNode *head)//��������ָ��fast��slow��fast���ٶ���slow����������fast��slow��ȵ�ʱ��������ǵ�������
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
	for (; fast&&fast->next; fast = fast->next, head = head->next)//��������ʹ�ͷ�ڵ㵽�뻷�ĵ�һ��������ľ�����һ���ģ����ҵ����Ǿ�����ȵĵ�����뻷�ĵ�һ���ڵ�
	{
		if (fast == head)
		{
			return fast;
		}
	}
}
