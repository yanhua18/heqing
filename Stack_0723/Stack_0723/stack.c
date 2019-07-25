#include"stack.h"


//ջ�ĳ�ʼ��
void StackInit(Stack *ps)
{
	assert(ps);
	ps->_capacity = N;
	ps->_a = (STDataType*)malloc(ps->_capacity*sizeof(STDataType));
	ps->_top = 0;
}

//�ݻ�ջ
void StackDestory(Stack *ps)
{
	assert(ps);
	if (ps->_a)//��ֹ�ظ��ͷ�
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}
}


//ջ��β���������һ���Ƚ�����Ľṹ��
void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)malloc(ps->_capacity*sizeof(STDataType));
		assert(ps->_a);
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

//ջ��βɾ��������һ���Ƚ�����Ľṹ��
void StackPop(Stack *ps)
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

//����ջ����ֵ
STDataType StackTop(Stack *ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

//����Ƿ�ջ��
int StackEmpty(Stack *ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;//���Ϊ�վͷ���0
	}
	else
	{
		return 1;//�����Ϊ�վͷ���1
	}
}
//��鵱ǰջ�Ĵ�С
int StackSize(Stack *ps)
{
	return ps->_top;
}
//ջ�Ĵ�ӡ
void StackPrint(Stack *ps)
{
	int i = 0;
	for (i = 0; i < ps->_top; i++)
	{
		printf("%d\n", ps->_a[i]);
	}
}


void My_Queue(Queue * qu)
{
	StackInit(&qu->instack);
	StackInit(&qu->outstack);
	StackPush(&qu->instack, 1);
	StackPush(&qu->instack, 2);
	StackPush(&qu->instack, 3);
	if (StackEmpty(&qu->outstack) == 0)
	{
		while (StackEmpty(&qu->instack) != 0)
		{
			StackPush(&qu->outstack, StackTop(&qu->instack));
			//printf("%d\n", StackTop(&qu->outstack));
			StackPop(&qu->instack);
		}
	}
	if (StackEmpty(&qu->instack) == 0)
	{ 
		while (StackEmpty(&qu->outstack) != 0)
		{
		printf("%d\n", StackTop(&qu->outstack));
		StackPush(&qu->instack, StackTop(&qu->outstack));
		StackPop(&qu->outstack);
		}
	}
}