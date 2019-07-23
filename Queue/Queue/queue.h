#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<Windows.h>

typedef int QuDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QuDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue * pq);//对队列进行初始化
void QueueDestory(Queue* pq);//对队列进行摧毁
QueueNode* BuyQueueNode(QuDataType x);//申请一个队列节点
void QueuePush(Queue* pq, QuDataType x);//队列的尾插操作（先进先出的结构）
void QueuePop(Queue* pq);//队列的头删操作（先进先出的结构）
QuDataType QueueFront(Queue* pq);//得到头结点
QuDataType QueueBack(Queue * pq);//得到尾节点
int QueueEmpty(Queue* pq);//判断队列是否为空
int QueueSize(Queue* pq);//返回队列节点个数


#endif