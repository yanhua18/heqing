#include"cqueue.h"

void QueueInit(Queue* pq)
{
	pq->front = pq->data;
	pq->rear = pq->data;
	pq->size = 0;
}


void QueueDestory(Queue* pq)
{
	pq->front = pq->data;
	pq->rear = pq->data;
	pq->size = 0;
}
//Î²²å²Ù×÷
void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size + 1 == QueueMAX)
	{
		return;
	}
	*pq->rear = x;
	pq->rear++;
	pq->size++;
	if (pq->front + QueueMAX == pq->rear)
	{
		pq->rear = pq->data;
	}
}


//Í·É¾²Ù×÷
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;
	pq->size--;
	if (pq->front - QueueMAX == pq->data)
	{
		pq->front = pq->data;
	}

}

QuDataType QueueFront(Queue* pq)
{
	return *pq->front;
}
QuDataType QueueBack(Queue* pq)
{
	return *(pq->rear - 1);
}
