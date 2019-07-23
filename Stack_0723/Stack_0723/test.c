#include"stack.h"


int main()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPrint(&ps);
	printf("%d\n", StackTop(&ps));
	StackDestory(&ps);

	system("pause");
	return 0;
}