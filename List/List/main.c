#include"SList.h"

//约瑟夫环问题
int __main()
{
	SListNode *phead;
	SListNode *plast;
	SListNode *cur;
	int m = 6, n = 5;
	int i;
	SListInit(&phead);
	SListPushFront(&phead, m);
	plast = phead;
	for (i = m - 1; i >= 1; i--)
	{
		SListPushFront(&phead, i);
	}
	plast->next = phead;

	cur = plast;
	for (; m > 1; m--)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
		}
		SListEraseAfter(cur);
	}

	printf("%d", cur->data);

	free(cur);
	system("pause");
	return 0;
}


int _main()
{

	SListNode *head;
	SListInit(&head);
	SListPushFront(&head, 5);
	SListPushFront(&head, 5);
	SListPushFront(&head, 3);
	SListPushFront(&head, 5);
	SListPushFront(&head, 5);
	//SListPopFront(&head);
	SListInsertAfter(SListFind(head,4), 10);
	//SListRemove(&head, 4);
	_SListReverse(&head);


	SListPrint(head);
	system("pause");
	return 0;
}