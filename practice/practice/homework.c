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

//2，将字符串中的空格转换成%20
void ReplaceBlank(char *str,int len)
{
	int MLen = 0;//计算字符的个数
	int NumBlank = 0;//计算空格的数组
	int IndexofMLen = 0;
	int Indexofnew = 0;
	int newlen = 0;
	int i = 0;//从0号下标开始遍历
	if(str == NULL || len <= 0)
	{
		return ;
	}
	while(str[i] != '\0')
	{
		++MLen;
		if(str[i] == ' ')
		{
			++NumBlank;
		}
		++i;
	}
	newlen = MLen + NumBlank * 2;//a%20b%20c%20d a b c d
	if(newlen > len)//newlen是扩充后数组的大小，所以一定要小于len原来大小，不然放不下
	{
		return;
	}
	IndexofMLen = MLen;
	Indexofnew = newlen;
	while(IndexofMLen >= 0 && Indexofnew >IndexofMLen)
	{
		if(str[IndexofMLen] == ' ')
		{
			str[Indexofnew--] = '0';
			str[Indexofnew--] = '2';
			str[Indexofnew--] = '%';
		}
		else
		{
			str[Indexofnew --] = str[IndexofMLen];
		}
		--IndexofMLen;
	}
}
int main()
{
	char str[30] = "a b c d";
	int len = (sizeof(str)/sizeof (str[0]));
	ReplaceBlank(str,len);
	printf("%s\n",str);
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
//5.1
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//刚开始的时候，都指向起点，然后p1走k-1步后，p2和p1同时开始走，当p1走到最后一个的时候，p2指向的就是
	最后一个节点
		ListNode *p1 = pListHead;
	ListNode *p2 = pListHead;
	if(pListHead==NULL || k == 0) {
		return NULL;
	}
	while( k-1 > 0)
	{
		if(p1->next != NULL)
		{
			p1 = p1->next;
			--k;
		}
		else
		{
			cout<<"error"<<endl;
			return NULL;
		}
	}
	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
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

//7,1求数组a中前k个最小的数字
//使用快排的划分 当然还可以使用堆进行求解
int Partion(int *arr, int left, int right)
{
	int tmp = arr[left];
	if (arr == NULL)
	{
		return -1;
	}
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
		{
			right--;
		}
		if (left >= right)
		{
			break;
		}
		else
		{
			arr[left] = arr[right];
		}
		while (left < right && arr[left] <= tmp)
		{
			left++;
		}
		if (left >= right)
		{
			break;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}
void Little_K(int *arr, int len, int k)
{
	int par = 0;
	int start = 0;
	int end = len - 1;
	int mid = len / 2;
	int index = Partion(arr, start, end);//使用上一个题目的Partion函数
	if (arr == NULL || len < 1)
	{
		return;
	}
	if (arr == NULL || len < 0)
	{
		return 0;//假设数组当中不存放数字0
	}
	while (index != mid)
	{
		if (index > mid)
		{//说明在左边找
			end = index - 1;
			index = Partion(arr, start, end);
		}
		else
		{
			start = index + 1;
			index = Partion(arr, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 12, 21, 1, 4, 2, 65, 33, 5, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Little_K(arr, len, 3);
	system("pause");
	return 0;
}

//7,1求数组a中前k个最小的数字****************************************************
void swapArgs(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void dealQSort(int *arr, int start, int end)//相当于一个二叉树的前序
{
	if (start >= end)
	{
		return;
	}
	int flag = 1;
	int i = start;
	int j = end;
	while (i<j)//当start和end交换的时候，就退出
	{
		if (arr[i] > arr[j])//如果前面的大于后面的就进行交换
		{
			swapArgs(&arr[i], &arr[j]);
			flag = !flag;
		}
		if (flag)//否则i++
		{
			i++;
		}
		else//如果交换成功，就将j前移
		{
			j--;
		}
	}
	dealQSort(arr, start, i - 1);//对左子树进行排序
	dealQSort(arr, i + 1, end);//对右子树进行排序
}
void Little_K(int *arr, int len, int k)
{
	dealQSort(arr, 0, len - 1);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 12, 21, 1, 4, 2, 65, 33, 5, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Little_K(arr, len, 6);
	system("pause");
	return 0;
}

//8，求一个数组中元素出现次数超过一半的数字
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int *arr, int start, int end)
{
	int i = start;
	int j = end;
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	while (i < j)
	{
		if (arr[i] > arr[j])
		{
			Swap(&arr[i], &arr[j]);
			flag = !flag;
		}
		flag ? i++:j--;
	}
	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}
int arrayLenHalfNum(int *arr,int len)
{
	int mid = len / 2;
	int i = 0;
	int count = 0;
	quickSort(arr, 0, len - 1);
	for (i = 0; i < len; i++)
	{
		if (arr[i] = arr[mid])
		{
			count++;
		}
	}
	if (count > mid)
	{
		return arr[mid];
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int x = arrayLenHalfNum(arr,len);
	printf("%d\n", x);
	system("pause");
	return 0;
}

//9.输入一个整形数组，数组里有正数也有负数。数组中一个或连续多个整数组成一个子数组，求所有子数组的和的最大值
int MAX_Arry(int *arr, int len)
{
	int max = arr[0];
	int sum = arr[0];
	int i = 0;
	if (arr == NULL || len <= 1)
	{
		return 0;
	}
	for(i = 1; i < len; i++)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
		if (sum > max)
		{
			max = sum;
		}
	}
	return max;
}

int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", MAX_Arry(arr, len));
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
		printf("数字%d是回文",num);
	}
	else
	{
		printf("数字%d不是回文数",num);
	}
	system("pause");
	return 0;
}

//15，如何快速找到一个单链表的中间位置
/*设定两个指针fast和slow，慢指针走一步，快指针走两步，
这样当快指针走到终点时，慢指针走到了中间的位置*/
int Find_Mid(SListNode *head)
{
	SListNode *fast = head;
	SListNode *slow = head;
	while (fast&&slow&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
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
	int x= Find_Mid(list);
	printf("%d\n", x);
	system("pause");
	return 0;
}


//16,实现pow(x,y)
/*
函数pow(x,y)实现运算x^y，即x的y次方，这里x和y都为整数。
算法的基本思想是，减少乘法次数，重复利用结算结果，例如：
x^4，如果逐个相乘的话，需要四次乘法。
如果我们这样分解(x^2)*(x^2)就只需要2两次乘法，
因为x^2的结果我们可以重复利用。所以我们最好做对称的分解指数y，
然后求x^(y/2)的平方。
具体算法如下：
1 如果y为偶数，直接计算mypow(x, y/2)*mypow(x, y/2)；
2 如果y为奇数，则y-1为偶数，回到了第一种情况。
*/
int Mypow(int x, int y)
{
	int result = 0;
	int tmp = 0;
	if (y == 1)
	{
		return x;
	}
	tmp = Mypow(x, y / 2);
	if (y & 1 != 0) //奇数
	{
		result = x * tmp * tmp;
	}
	else
	{
		result = tmp * tmp;
	}
	return result;
}
int main()
{
	int x = 2;
	int y = 3;
	int num = Mypow(x, y);
	printf("%d\n", num);
	system("pause");
	return 0;
}

//17,求一个有序数组中两个元素的值相加等于k，返回这两个元素的下标，要求时间复杂度为o(n),空间复杂度为o(1)
void Tow_Add(int *arr, int len, int k, int *a, int *b)
{
	int low = 0;
	int high = len - 1;
	int sum = 0;
	while (low <= high)
	{
		sum = arr[low] + arr[high];
		if (sum < k)
		{
			low++;
		}
		else if (sum > k)
		{
			high--;
		}
		else
		{
			*a = low;
			*b = high;
			break;
		}
	}

}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 13;
	int i = 0;
	int j = 0;
	Tow_Add(arr,len, k,&i,&j);
	printf(" 两个数的下标为： %d , %d ", i, j);
	system("pause");
	return 0;
}

//18，判断一个数字是不是2的k次方
int IsPrime(int n)
{
	if (n < 1)
	{
		return 0;
	}
	int m = n&(n - 1);
	if (m == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int n = 16;
	int x = IsPrime(n);
	if (x)
	{
		printf("该数字是2的倍数");
	}
	else
	{
		printf("该数字不是2的倍数");
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

//20,删除字符串首尾的空格，中间的连续空格只能保留一个，员字符串顺序不变
char *Delete(char *str)
{
	char *str1 = str;
	char *str2 = str;
	int flag = 0;
	while (*str1 != '\0')
	{
		if (!flag && *str1 == '*'&&*(str1 + 1)=='*'||*(str1+1)!='\0')
		{
			str1++;
		}
		else
		{
			str1++;
		}
		if (flag && *str1 == '*'&&*(str1 + 1) != '*' && *(str1 + 1) != '\0')
		{
			*str2 = '*';
			str2++;
			flag = 0;
		}
		while (*str1 != '*' && *str1 != 0 && str2 != 0)
		{
			flag = 1;
			*str2 = *str1;
			str2++;
			str1++;
		}
 	}
	*str2 = '\0';
	return str;
}
char *Deblank(char *str)
{
	int flag = 0; //代表没开始处理空格
	int p = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		//遇到空格 还没开始处理
		if (!flag &&str[i] == '*')// 遇到空格 让i往后走到不是空格的地方
		{
			i++;
		}
		//遇到不是空格 还没开始处理
		else if (!flag &&str[i] != '*')//不是空格的字符向前赋值
		{
			flag = 1; //开始处理空格
			str[p++] = str[i++];
		}
		//遇到空格 开始处理了
		else if (flag &&str[i] == '*')
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
	if (str[p - 1] == '*') //结尾处多余空格
		str[p - 1] = '\0';
	else
		str[p] = '\0';
	return str;
}
int main()
{
	char arr[] = "*****as****ada***dq*****";
	/*char *str = Deblank(arr);
	printf("%s\n", str);*/
	char *str = Delete(arr);
	printf("%s\n", str);
	system("pause");
	return 0;
}


#endif


















