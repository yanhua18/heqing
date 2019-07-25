#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#define N 10
typedef int STDataType;

typedef struct Stack
{
	STDataType *_a;//ָ��̬���ٵ�����
	int _top;//ջ��
	int _capacity;//����
}Stack;


//������ջ��ʵ��һ�����У�����Ҫ��ջ�߱��Ƚ��ȳ����ص㣬��ˣ�������Ҫ������ջ��ʵ��
//����һ��instackջ�����ڴ������ݣ�����һ��outstackջ����������ݡ����ǽ�instack�е�����ȫ������outstack�У��ٴ�outstack�г�����ʵ���˶��еĹ���
typedef struct Queue
{
	Stack instack;
	Stack outstack;
}Queue;//���ǽ�����ջ��װ��һ������



void My_Queue(Queue * qu);
void StackInit(Stack *ps);//ջ�ĳ�ʼ��
void StackDestory(Stack *ps);//�ݻ�ջ
void StackPush(Stack *ps, STDataType x);//ջ��β���������һ���Ƚ�����Ľṹ��
void StackPop(Stack *ps);//ջ��βɾ��������һ���Ƚ�����Ľṹ��
STDataType StackTop(Stack *ps);//����ջ����ֵ
void StackPrint(Stack *ps);//ջ�Ĵ�ӡ
int StackEmpty(Stack *ps);
int StackSize(Stack *ps);

#endif