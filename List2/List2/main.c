#include"List.h"

int main()
{
	List list;
	ListInit(&list);
	ListPushFront(&list, 1);
	ListPushFront(&list, 2);
	ListPushFront(&list, 3);
	ListPushFront(&list, 4);
	ListPushFront(&list, 5);
	ListPushFront(&list, 6);
	ListFind(&list, 6);
	ListInsertAfter(ListFind(&list, 6), 6);
	//ListPopFront(&list);
	//ListPopBack(&list);

	ListPrint(&list);

	ListDestory(&list);
	system("pause");
	return 0;
}