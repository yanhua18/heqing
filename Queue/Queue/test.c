#include"queue.h"
int main()
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);
	QueuePush(&qu, 4);
	QueuePush(&qu, 5);
	/*printf("%d\n", QueueFront(&qu));
	QueuePop(&qu);
	printf("%d\n", QueueFront(&qu));
	QueuePop(&qu);
	printf("%d\n", QueueFront(&qu));
	QueuePop(&qu);
	printf("%d\n", QueueFront(&qu));
	QueuePop(&qu);*/
	printf("%d\n", QueueBack(&qu));
	QueueDestory(&qu);

	system("pause");
	return 0;
}