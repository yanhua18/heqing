#include"stack.h"


//栈的初始化
void StackInit(Stack *ps)
{
	ps->_capacity = N;
	ps->_a = (STDataType*)malloc(ps->_capacity*sizeof(STDataType));
	ps->_top = 0;
}

//摧毁栈
void StackDestory(Stack *ps)
{
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
	ps->_a[ps->_top] = x;
	ps->_top++;
}

//栈的尾删操作（是一种先进后出的结构）
void StackPop(Stack *ps)
{
	ps->_top--;
}

//返回栈顶的值
STDataType StackTop(Stack *ps)
{
	return ps->_a[ps->_top-1];
}

//栈的打印
void StackPrint(Stack *ps)
{
	int i = 0;
	for (i = 0; i < ps->_top; i++)
	{
		printf("%d\n", ps->_a[i]);
	}
}