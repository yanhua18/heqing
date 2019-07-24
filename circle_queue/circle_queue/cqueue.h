#ifndef _CQUEUE_H_
#define _CQUEUE_H_


#include<stdio.h>
#include<Windows.h>

#define QueueMAX 5
typedef int QuDataType;

typedef struct Queue
{
	QuDataType data[QueueMAX];
	QuDataType *front;
	QuDataType *rear;
	size_t size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);



#endif