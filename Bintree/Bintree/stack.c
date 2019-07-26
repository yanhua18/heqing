#include"stack.h"


//栈的初始化
void StackInit(Stack *ps)
{
	assert(ps);
	ps->_capacity = N;
	ps->_a = (STDataType*)malloc(ps->_capacity*sizeof(STDataType));
	ps->_top = 0;
}

//摧毁栈
void StackDestory(Stack *ps)
{
	assert(ps);
	if (ps->_a)//防止重复释放
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_top = 0;
		ps->_capacity = 0;
	}
}


//栈的尾插操作（是一种先进后出的结构）
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

//栈的尾删操作（是一种先进后出的结构）
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

//返回栈顶的值
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

//检查是否栈空
int StackEmpty(Stack *ps)
{
	assert(ps);
	if (ps->_top == NULL)
	{
		return 0;//如果为空就返回0
	}
	else
	{
		return 1;//如果不为空就返回1
	}
}
//检查当前栈的大小
int StackSize(Stack *ps)
{
	return ps->_top;
}
