#include"queue.h"

//对队列进行初始化
void QueueInit(Queue * pq)
{
	pq->_front = NULL;
	pq->_rear = NULL;
}

//对队列进行摧毁
void QueueDestory(Queue* pq)
{
	QueueNode* tmp;
	for (; pq->_front != pq->_rear; pq->_front = pq->_front->next)
	{
		tmp = pq->_front->next;
		free(pq->_front);
		pq->_front = tmp;
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}

//申请一个队列节点
QueueNode* BuyQueueNode(QuDataType x)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

//队列的尾插操作（先进先出的结构）
void QueuePush(Queue* pq, QuDataType x)
{
	QueueNode* tmp = BuyQueueNode(x);
	if (pq->_rear == NULL)//如果pq->rear为空的话，就说明这个队列还没有一个节点
	{
		pq->_front = tmp;
		pq->_rear = tmp;
	}
	else
	{
		pq->_rear->next = tmp;
		pq->_rear = tmp;
	}
}

//队列的头删操作（先进先出的结构）
void QueuePop(Queue* pq)
{
	QueueNode* tmp;
	if (pq->_front == pq->_rear)
	{
		return;
	}
	else
	{
		tmp = pq->_front->next;
		free(pq->_front);
		pq->_front = tmp;
	}
}

//得到头结点
QuDataType QueueFront(Queue* pq)
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	else
	{
		return pq->_front->data;
	}
}

//得到尾节点
QuDataType QueueBack(Queue * pq)
{
	if (pq->_front == pq->_rear)
	{
		return 0;
	}
	else
	{
		return pq->_rear->data;
	}
}

//判断队列是否为空
int QueueEmpty(Queue* pq)
{
	if (pq->_front == pq->_front)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//返回队列节点个数
int QueueSize(Queue* pq)
{
	return pq->_front - pq->_front;
}