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
	else
	{
		return NULL;
	}
}

//����ջ����ֵ
STDataType StackTop(Stack *ps)
{
	assert(ps);
	if (ps->_top != 0)
	{
		return ps->_a[ps->_top - 1];
	}
	else
	{
		return NULL;
	}
}

//����Ƿ�ջ��
int StackEmpty(Stack *ps)
{
	assert(ps);
	if (ps->_top == NULL)
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
