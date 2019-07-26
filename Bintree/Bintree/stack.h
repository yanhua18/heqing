#ifndef _STACK_H_
#define _STACK_H_
#include"bintree.h"
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#define N 20
typedef BTNode * STDataType;

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

int StackEmpty(Stack *ps);
int StackSize(Stack *ps);

#endif