#include"queue.h"

//�Զ��н��г�ʼ��
void QueueInit(Queue * pq)
{
	pq->_front = NULL;
	pq->_rear = NULL;
}

//�Զ��н��дݻ�
void QueueDestory(Queue* pq)
{
	QueueNode* tmp;
	for (; pq->_front != NULL; pq->_front = pq->_front->next)
	{
		tmp = pq->_front->next;
		free(pq->_front);
		pq->_front = tmp;
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}

//����һ�����нڵ�
QueueNode* BuyQueueNode(QuDataType x)
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

//���е�β��������Ƚ��ȳ��Ľṹ��
void QueuePush(Queue* pq, QuDataType x)
{
	QueueNode* tmp = BuyQueueNode(x);
	if (pq->_rear == NULL)//���pq->rearΪ�յĻ�����˵��������л�û��һ���ڵ�
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

//���е�ͷɾ�������Ƚ��ȳ��Ľṹ��
void QueuePop(Queue* pq)
{
	QueueNode* tmp;
	if (pq->_front == NULL)
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

//�õ�ͷ���,���ص�data��BTNode *���͵ģ����������һ�����ڵ��data��_left,_right
QuDataType QueueFront(Queue* pq)
{
	if (pq->_front == NULL)
	{
		return 0;
	}
	else
	{
		return pq->_front->data;
	}
}

//�õ�β�ڵ�
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

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* pq)
{

	return pq->_front == NULL;//�ǿշ���1�����ǿշ���0
}
//���ض��нڵ����
