#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"bintree.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

typedef BTNode * QuDataType;//需要传入整个节点，对他进行push和pop操作

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



#endif