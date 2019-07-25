#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#define N 10
typedef int STDataType;

typedef struct Stack
{
	STDataType *_a;//指向动态开辟的数组
	int _top;//栈顶
	int _capacity;//容量
}Stack;


//用两个栈来实现一个队列，就是要让栈具备先进先出的特点，因此，我们需要有两个栈来实现
//定义一个instack栈，用于存入数据，定义一个outstack栈用于输出数据。我们将instack中的数据全部存入outstack中，再从outstack中出来就实现了队列的功能
typedef struct Queue
{
	Stack instack;
	Stack outstack;
}Queue;//我们将两个栈封装成一个队列



void My_Queue(Queue * qu);
void StackInit(Stack *ps);//栈的初始化
void StackDestory(Stack *ps);//摧毁栈
void StackPush(Stack *ps, STDataType x);//栈的尾插操作（是一种先进后出的结构）
void StackPop(Stack *ps);//栈的尾删操作（是一种先进后出的结构）
STDataType StackTop(Stack *ps);//返回栈顶的值
void StackPrint(Stack *ps);//栈的打印
int StackEmpty(Stack *ps);
int StackSize(Stack *ps);

#endif