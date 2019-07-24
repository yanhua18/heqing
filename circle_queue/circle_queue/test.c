#include"cqueue.h"


int main()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePush(&pq, 7);
	//printf("%d",QueueFront(&pq));
	QueuePop(&pq);
	printf("%d", QueueBack(&pq));
	QueueDestory(&pq);




	system("pause");
	return 0;
}