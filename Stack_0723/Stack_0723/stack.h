#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<Windows.h>
#define N 10
typedef int STDataType;

typedef struct Stack
{
	STDataType *_a;//指向动态开辟的数组
	int _top;//栈顶
	int _capacity;//容量
}Stack;

void StackInit(Stack *ps);//栈的初始化
void StackDestory(Stack *ps);//摧毁栈
void StackPush(Stack *ps, STDataType x);//栈的尾插操作（是一种先进后出的结构）
void StackPop(Stack *ps);//栈的尾删操作（是一种先进后出的结构）
STDataType StackTop(Stack *ps);//返回栈顶的值
void StackPrint(Stack *ps);//栈的打印

#endif