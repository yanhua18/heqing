#include"List.h"

int main()
{
	List list1;
	List list2;
	ListInit(&list1);
	ListInit(&list2);
	ListPushFront(&list1, 7);
	ListPushFront(&list1, 5);
	ListPushFront(&list1, 3);
	ListPushFront(&list1, 1);
	ListPushFront(&list2, 9);
	ListPushFront(&list2, 6);
	ListPushFront(&list2, 4);
	ListMerge(&list1, &list2);

	//ListDistinct(&list);
	//ListFind(&list, 6);
	//ListInsertAfter(ListFind(&list, 6), 6);
	//ListPopFront(&list);
	//ListPopBack(&list);

	ListPrint(&list1);

	ListDestory(&list1);
	system("pause");
	return 0;
}