#include"SList.h"
#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable:4996)
#if 0
//1����һ����ά�����У�ÿһ�а��մ����ҵ�����˳�����У�ÿһ�а��մ��ϵ��µ�����˳�����У�����һ�������ж��Ƿ���������ά�����У�ʱ�临�Ӷȣ�O��row+col����
int search(int *arr[][4], int data, int *m, int *n)
{
	int i = 0, j = *n-1;
	while (i <*m && j >=0 )
	{
		if (arr[i][j] < data)
		{
			i++;
		}
		if (arr[i][j] > data)
		{
			j--;
		}
		if (arr[i][j] == data)
		{
			*m = i;
			*n = j;
			return;
		}
	}
	*m = -1;
	*n = -1;
}
int main()
{
	int i = 4, j = 4;
	int arr[4][4] = 
	  { 1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	int data = 7;
	int m = 4, n = 4;
	search(arr, data, &m, &n);
	printf("�������������е��±�Ϊ��<%d,%d>\n", m, n);
	system("pause");
	return 0;
}

//2�����ַ����еĿո�ת����%20
void StringChange(char *arr)
{
	int len = 0;//�ַ���ԭ���ĳ���
	int newlen = 0;//�ڽ��ո����ת����ĳ���
	int n = 0;//�ո�ĸ���
	while (arr[len] != '\0')//�����ַ�����ԭ�����Ⱥ��³���
	{
		if (arr[len] == ' ')
		{
			n++;
		}
		len++;
	}
	newlen = len + 2*n;
	while (len)//��Ԫ�ؽ��дӺ���ǰ�ĺ��ƺͲ���
	{
		if (arr[len] == ' ')
		{
			arr[newlen] = '0';
			newlen--;
			arr[newlen] = '2';
			newlen--;
			arr[newlen] = '%';

		}
		else
		{
			arr[newlen] = arr[len];
		}
		len--;
		newlen--;
	}
}
int main()
{
	char arr[20] = "abc defgx yz";
	StringChange(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//3�����n��쳲�������
int _Fibonacci(int n)
{
	int arr[100];
	int i;
	arr[0] = 1;
	arr[1] = 1;
	for (i = 2; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[i-1];
}
int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int x = Fibonacci(7);
	printf("%d\n", x);
	system("pause");
	return 0;
}
//4,��һ���޷������α���x���ڴ��ж�����1�ĸ���
int _Get_number(int n)
{
	int i;
	int num = 0;
	for (i = 31; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			num++;
		}
	}
	return num;
}
int Get_number(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main()
{
	unsigned int a = 255;
	int num = Get_number(a);
	printf("%d", num);
	system("pause");
	return 0;
}

//5.��һ�ŵ�������д����������k�����
int Get_Locate(SListNode** pphead, int k)
{
	SListNode *p, *q;
	p = *pphead;
	q = *pphead;
	int count = 0;
	while (q != NULL)
	{
		count++;
		if (count > k)
		{
			p = p->next;
		}
		q = q->next;
	}
	if (k > count)
	{
		return -1;
	}
	return p->data;
}
int main()
{
	SListNode *list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 8);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 4);
	SListPushFront(&list, 6);
	SListPushFront(&list, 5);
	SListPushFront(&list, 8);
	SListPrint(list);
	printf("\n");
	int x = Get_Locate(&list, 2);
	printf("%d\n", x);
	system("pause");
	return 0;
}
//ʵ�ֵ����������
void SListReverse(SListNode** pphead)
{
	SListNode *oldh = *pphead;//����һ��oldhָ��ָ��ͷ��ʼ��ָ��ԭ�е�ͷ���
	SListNode *head = *pphead;//����һ��headָ��ָ��ͷ��ָ�򲻶ϸ��µ�ͷ���
	SListNode *tmp = head->next;//tmpʼ��ָ��oldh����һ��    
	while (tmp)
	{
		oldh->next = tmp->next;//�Ͽ�tmp����ͷָ��tmp����һ��
		tmp->next = head;//tmpÿ��ָ���µ�ͷ
		head = tmp;//��headŲ���µ�ͷ
		tmp = oldh->next;//��tmpŲ����ͷoldh����һ��
	}
	*pphead = head;//��ת�����󣬽��µ�ͷ����phead
}
void _SListReverse(SListNode** pphead)
{
	SListNode *pre = *pphead;
	SListNode *cur = pre->next;
	SListNode *next = cur;
	pre->next = NULL;//��ͷ���β
	while (next)
	{
		next = next->next;//next����һλ
		cur->next = pre;//��ԭ��ָ����һλ�ķ�תָ����һλ
		pre = cur;//��cur��pre
		cur = next;//��next��cur��curָ��next��
	}
	*pphead = pre;
}
int main()
{
	SListNode *list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 8);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 4);
	SListPushFront(&list, 6);
	SListPushFront(&list, 5);
	SListPushFront(&list, 8);
	SListPrint(list);
	printf("\n");
	SListReverse(&list);
	SListPrint(list);
	system("pause");
	return 0;
}
#endif