#include"heap.h"

#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
	int a[] = { 1, 6, 3, 7, 9, 8 };
	Heap hp;
	HeapInit(&hp, a, ARRSIZE(a));
	//HeapPrint(&hp);
	HeapPush(&hp,20);
	//HeapPop(&hp);
	//HeapSort(&hp);
	HeapPrint(&hp);

	system("pause");
	return 0;
}