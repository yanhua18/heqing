#include"stack.h"


//ջ�ĳ�ʼ��
void StackInit(Stack *ps)
{
	ps->_capacity = N;
	ps->_a = (STDataType*)malloc(ps->_capacity*sizeof(STDataType));
	ps->_top = 0;
}

//�ݻ�ջ
void StackDestory(Stack *ps)
{
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
	ps->_a[ps->_top] = x;
	ps->_top++;
}

//ջ��βɾ��������һ���Ƚ�����Ľṹ��
void StackPop(Stack *ps)
{
	ps->_top--;
}

//����ջ����ֵ
STDataType StackTop(Stack *ps)
{
	return ps->_a[ps->_top-1];
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