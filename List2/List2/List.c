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

void ListPushBack(List* plist, LTDataType x)//β��
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_prev;
	cur->_data = x;
	tmp->_next = cur;
	cur->_prev = tmp;
	cur->_next = plist->_head;
	plist->_head->_prev = cur;
}

void ListPopBack(List* plist)//βɾ
{
	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)//ͷ��
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = plist->_head->_next;
	cur->_data = x;
	cur->_next = tmp;
	tmp->_prev = cur;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
}

void ListPopFront(List* plist)//ͷɾ
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

void ListInsertAfter(ListNode* pos, LTDataType x)//���
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

//ɾ���������ظ�����
void ListDistinct(List* plist)
{
	ListNode *cur = plist->_head->_next;//����ͷ��dataΪ���ֵ����˲���Ҫ����ͷ����ͷ����һλ��ʼ����һֱ������ͷ��ǰһλ
	while (cur != plist->_head)
	{
		if (cur->_data == cur->_next->_data)//��cur��cur->next��ֵ��ͬʱ����ɾ��������Ǹ��ڵ�ֱ��ǰ��������ٽ���curǰ��
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}

//��������������ϲ�Ϊһ����������
void  ListMerge(List * plist1, List * plist2)
{
	ListNode *cur1 = plist1->_head->_next;
	ListNode *cur2 = plist2->_head->_next;
	ListNode * tmp1, *tmp2;
	while(cur1 != plist1->_head && cur2 != plist2->_head)//����ѭ���ĳ��ڵ�������һ�����ߵ���ͷ
	{
		if (cur1->_data > cur2->_data)//��cur1��cur2��ʱ����cur2��ָ�Ľڵ�ǰ�嵽cur1��
		{
			tmp1 = cur1->_prev; //����CUR1�ᱻ�޸ģ�������һ������******����Ҫ��һ�����ݣ���Ȼ���ƶ�curλ��ʱ�������
			tmp2 = cur2->_next; //����CUR2δ���ᱻ�޸ģ�������һ������******����Ҫ��һ�����ݣ���Ȼ���ƶ�curλ��ʱ�������

			cur1->_prev = cur2; // cur1��������cur2
			cur2->_next = cur1; // cur2��������cur1����������
			tmp1->_next = cur2; // tmp1��cur1��prev������������cur2
			cur2->_prev = tmp1; // cur2����������tmp1����������

			cur2 = tmp2; // cur2�ҵ�������һ���ڵ�
		}
		else
		{
			cur1 = cur1->_next;
		}
	}//���list2�ߵ���ͷ�ͱ�ʾ�����еĽڵ㶼�Ѿ����뵽list1���ˣ���ʱֻ��Ҫ�ͷ�ͷ����
	if (cur1 == plist1->_head)//��list1�ߵ�ͷ��list2��δ����ʱ����Ҫ��list2ʣ��Ľڵ�ӵ�list1���档
	{
		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;
		plist2->_head->_prev->_next = cur1;
		cur1->_prev = plist2->_head->_prev;
	}
	free(plist2->_head);//�ͷŵ�list2��ͷ
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