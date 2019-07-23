#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<Windows.h>
#define N 10
typedef int STDataType;

typedef struct Stack
{
	STDataType *_a;//ָ��̬���ٵ�����
	int _top;//ջ��
	int _capacity;//����
}Stack;

void StackInit(Stack *ps);//ջ�ĳ�ʼ��
void StackDestory(Stack *ps);//�ݻ�ջ
void StackPush(Stack *ps, STDataType x);//ջ��β���������һ���Ƚ�����Ľṹ��
void StackPop(Stack *ps);//ջ��βɾ��������һ���Ƚ�����Ľṹ��
STDataType StackTop(Stack *ps);//����ջ����ֵ
void StackPrint(Stack *ps);//ջ�Ĵ�ӡ

#endif