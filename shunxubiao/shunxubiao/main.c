#include"seqlist.h"

int main()
{
	SeqList test;
	SeqListInit(&test, 100);
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);
	SeqListRemoveAll(&test, 4);
	//SeqListBubbleSort(&test);
	//SeqListBinaryFind(&test, 1);
	//int i=SeqListFind(&test, 8);
	//printf("%d ", i);
	//SeqListInsert(&test, 3,10);
	//SeqListErase(&test, 3);
	//SeqListPopFront(&test);
	//SeqListPushFront(&test, 10);
	SeqListPrint(&test);
	SeqListDestory(&test);
	system("pause");
	return 0;
}