#include"SList.h"
#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable:4996)

#if 0
//1，在一个二维数组中，每一行按照从左到右递增的顺序排列，每一列按照从上到下递增的顺序排列，输入一个整数判断是否存在这个二维数组中，时间复杂度（O（row+col））
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
	printf("该数字在数组中的下标为：<%d,%d>\n", m, n);
	system("pause");
	return 0;
}

//2，将字符串中的空格转换成%20
void StringChange(char *arr)
{
	int len = 0;//字符串原本的长度
	int newlen = 0;//在将空格进行转换后的长度
	int n = 0;//空格的个数
	while (arr[len] != '\0')//计算字符串的原本长度和新长度
	{
		if (arr[len] == ' ')
		{
			n++;
		}
		len++;
	}
	newlen = len + 2*n;
	while (len)//对元素进行从后往前的后移和插入
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

//3，求第n个斐波拉契数
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
//4,求一个无符号整形变量x在内存中二进制1的个数
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

//5.有一张单链表，编写函数求倒数第k个结点
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
//实现单链表的逆置
void SListReverse(SListNode** pphead)
{
	SListNode *oldh = *pphead;//定义一个oldh指针指向头，始终指向原有的头结点
	SListNode *head = *pphead;//定义一个head指针指向头，指向不断更新的头结点
	SListNode *tmp = head->next;//tmp始终指向oldh的下一个    
	while (tmp)
	{
		oldh->next = tmp->next;//断开tmp，旧头指向tmp的下一个
		tmp->next = head;//tmp每次指向新的头
		head = tmp;//将head挪到新的头
		tmp = oldh->next;//将tmp挪到旧头oldh的下一个
	}
	*pphead = head;//逆转结束后，将新的头赋给phead
}
void _SListReverse(SListNode** pphead)
{
	SListNode *pre = *pphead;
	SListNode *cur = pre->next;
	SListNode *next = cur;
	pre->next = NULL;//让头变成尾
	while (next)
	{
		next = next->next;//next右移一位
		cur->next = pre;//将原本指向下一位的反转指向上一位
		pre = cur;//将cur给pre
		cur = next;//将next给cur（cur指向next）
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

//10,在字符串中找出第一个只出现一次的字符，要求时间复杂度为O（n）
//时间复杂度为O(n^2)
char Find_One(int *arr)
{
	char *fast = arr;
	char *last = arr;
	while (*fast != '\0')
	{
		while (*last != '\0')
		{
			if (*fast == *last)
			{
				fast++;
			}
			else
			{
				last++;
			}
			return *fast;
		}
	}
	return 0;
}
//时间复杂度为O(n)
char firstNotRepeate(char* str)
{
	const int size = 256;//表示
	int hashTable[256];
	int i;
	if (str == NULL) {
		return '\0';
	}
	for (i = 0; i < size; i++) {
		hashTable[i] = 0;
	}
	char *pHashKey = str;
	while (*(pHashKey) != '\0')
	{
		hashTable[*(pHashKey++)]++;
	}
	pHashKey = str;
	while (*(pHashKey) != '\0')
	{
		if (hashTable[*(pHashKey)] == 1)
		{
			return *(pHashKey);
		}
		pHashKey++;
	}
	return '\0';
}
int main()
{
	char arr[] = "abaccdeff";
	char x = firstNotRepeate(arr);
	printf("%c", x);
	system("pause");
	return 0;
}

//11,在字符串中找出第一次重复的字符，要求时间复杂度为O（n）
char first_Repeate(char *str)
{
	char arr[256] = { 0 };
	int i;
	if (str == NULL)
	{
		return '\0';
	}
	char *ptr = str;
	while (*ptr != '\0')
	{
		arr[*ptr]++;
		ptr++;
	}
	ptr = str;
	while (*ptr != '\0')
	{
		if (arr[*ptr] == 2)
		{
			return *ptr;
		}
		ptr++;
	}
	return '\0';
}
int main()
{
	char arr[] = "qywyer23tdd";
	char x = first_Repeate(arr);
	printf("%c", x);
	system("pause");
	return 0;
}

//12,一个整形数组中出了两个数字之外，其他数字都出现了两个，找出只出现了一次的数字
void Find_Differ(int *arr,int len)
{
	int i,j;
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 0; i < len; i++)
	{
		sum ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if ((sum >> i) & 1)
		{
			break;
		}
	}
	for (j = 0; j < len; j++)
	{
		if ((arr[j] >> i) & 1)
		{
			sum1 ^= arr[j];
		}
		else
		{
			sum2 ^= arr[j];
		}
	}
	printf("%d , %d", sum1, sum2);
}
int main()
{	
	int arr[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_Differ(arr,len);
	system("pause");
	return 0;
}

//13，输入两个字符串，从第一串中删除第二串中所有的字符
char *Find_repeat(char *arr1, char *arr2)
{
	char *p1 = arr1;
	char *p2 = arr2;
	char *p = arr1;
	while (*p2 != '\0')
	{
		p1 = arr1;
		while (*p1 != '\0')
		{
			if (*p2 == *p1)
			{
				p = p1;
				while (*p != '\0')
				{
					*p = *(p+1);
					p++;
				}
			}
			else
			{
				p1++;
			}
		}
		p2++;
	}
	return arr1;
}
int main()
{
	char arr1[] = "They are students.";
	char arr2[] = "aeiou";
	Find_repeat(arr1, arr2);
	printf("%s", arr1);
	system("pause");
	return 0;
}

//14,判断一个数字是否为回文数（主要就是将该数字倒过来，若与原来的数字相等，则该数字就是回文数）
int Paindrome_Judge(int num)
{
	int newnum = 0;
	int n = num;
	while (num > 0)
	{
		newnum = newnum * 10 + num % 10;
		num /= 10;
	}
	if (n == newnum)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int num = 12321;
	int x = Paindrome_Judge(num);
	if (x)
	{
		printf("数字%d是回文数",num);
	}
	else
	{
		printf("数字%d不是回文数",num);
	}
	system("pause");
	return 0;
}
//19，对字符串进行压缩
void Compress(char *str)
{
	int count = 1;
	int i = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			if (count != 1)
				printf("%d", count);
			printf("%c", str[i]);
			count = 1;
		}
		i++;
	}
	printf("\n");
}

char *str_Compress(char *str)
{
	int count = 0;
	char *str1 = str;
	char *str2 = str;
	while (*str1 != '\0')
	{
		count = 1;
		while (*str1 == *(str1+1))
		{
			count++;
			str1++;
		}
		*str2 = count+48;
		*(++str2) = *str1;
		str2++;
		str1++;
	}
	*str2 = '\0';
	return str;
}
int main()
{
	char arr[] = "xxxyyyyz";
	//char *str = str_Compress(arr);
	//printf("%s\n", str);
	Compress("xxyyyz");
	Compress("xyyyz");
	Compress("xxxxx");
	Compress("aabbccdaa");
	system("pause");
	return 0;
}
#endif

	char *Delete(char *str)
{
	char *str1 = str;
	char *str2 = str;
	while (*str1 != '\0')
	{
		if (*str1 == '*'&&*(str1 + 1)=='*'||*(str1+1)=='\0')
		{
			str1++;
		}
		
		else
		{
			str1++;
		}
		while (*str1 != '*' && *str1 != 0 && str2 != 0)
		{
			*str2 = *str1;
			str2++;
			str1++;
		}
 	}
	*str2 = '\0';
	return str;
}

	void Deblank(char *str)
	{
		int flag = 0; //代表没开始处理空格
		int p = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			//遇到空格 还没开始处理
			if (!flag &&str[i] == ' ')// 遇到空格 让i往后走到不是空格的地方
			{
				i++;
			}
			//遇到不是空格 还没开始处理
			else if (!flag &&str[i] != ' ')//不是空格的字符向前赋值
			{
				flag = 1; //开始处理空格
				str[p++] = str[i++];
			}
			//遇到空格 开始处理了
			else if (flag &&str[i] == ' ')
			{
				flag = 0; //不处理
				str[p++] = str[i++];
			}
			else
			{
				str[p++] = str[i++];
				flag = 1;
			}
		}
		if (str[p - 1] == ' ') //结尾处多余空格
			str[p - 1] = '\0';
		else
			str[p] = '\0';
	}
	int main()
	{
		char str[] = " as adad q ";
		Deblank(str);
		printf("%s", str);
		return 0;
	}



int main()
{
	char arr[] = "*****as****adadq*****";
	char *str = Delete(arr);
	printf("%s\n", str);
	system("pause");
	return 0;
}