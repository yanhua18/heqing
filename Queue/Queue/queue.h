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

void QueueInit(Queue * pq);//�Զ��н��г�ʼ��
void QueueDestory(Queue* pq);//�Զ��н��дݻ�
QueueNode* BuyQueueNode(QuDataType x);//����һ�����нڵ�
void QueuePush(Queue* pq, QuDataType x);//���е�β��������Ƚ��ȳ��Ľṹ��
void QueuePop(Queue* pq);//���е�ͷɾ�������Ƚ��ȳ��Ľṹ��
QuDataType QueueFront(Queue* pq);//�õ�ͷ���
QuDataType QueueBack(Queue * pq);//�õ�β�ڵ�
int QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pq);//���ض��нڵ����


#endif