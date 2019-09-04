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

//2�����ַ����еĿո�ת����%20
void ReplaceBlank(char *str,int len)
{
	int MLen = 0;//�����ַ��ĸ���
	int NumBlank = 0;//����ո������
	int IndexofMLen = 0;
	int Indexofnew = 0;
	int newlen = 0;
	int i = 0;//��0���±꿪ʼ����
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
	if(newlen > len)//newlen�����������Ĵ�С������һ��ҪС��lenԭ����С����Ȼ�Ų���
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
//5.1
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//�տ�ʼ��ʱ�򣬶�ָ����㣬Ȼ��p1��k-1����p2��p1ͬʱ��ʼ�ߣ���p1�ߵ����һ����ʱ��p2ָ��ľ���
	���һ���ڵ�
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

//7,1������a��ǰk����С������
//ʹ�ÿ��ŵĻ��� ��Ȼ������ʹ�öѽ������
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
	int index = Partion(arr, start, end);//ʹ����һ����Ŀ��Partion����
	if (arr == NULL || len < 1)
	{
		return;
	}
	if (arr == NULL || len < 0)
	{
		return 0;//�������鵱�в��������0
	}
	while (index != mid)
	{
		if (index > mid)
		{//˵���������
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

//7,1������a��ǰk����С������****************************************************
void swapArgs(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void dealQSort(int *arr, int start, int end)//�൱��һ����������ǰ��
{
	if (start >= end)
	{
		return;
	}
	int flag = 1;
	int i = start;
	int j = end;
	while (i<j)//��start��end������ʱ�򣬾��˳�
	{
		if (arr[i] > arr[j])//���ǰ��Ĵ��ں���ľͽ��н���
		{
			swapArgs(&arr[i], &arr[j]);
			flag = !flag;
		}
		if (flag)//����i++
		{
			i++;
		}
		else//��������ɹ����ͽ�jǰ��
		{
			j--;
		}
	}
	dealQSort(arr, start, i - 1);//����������������
	dealQSort(arr, i + 1, end);//����������������
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

//8����һ��������Ԫ�س��ִ�������һ�������
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

//9.����һ���������飬������������Ҳ�и�����������һ������������������һ�������飬������������ĺ͵����ֵ
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


//10,���ַ������ҳ���һ��ֻ����һ�ε��ַ���Ҫ��ʱ�临�Ӷ�ΪO��n��
//ʱ�临�Ӷ�ΪO(n^2)
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
//ʱ�临�Ӷ�ΪO(n)
char firstNotRepeate(char* str)
{
	const int size = 256;//��ʾ
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

//11,���ַ������ҳ���һ���ظ����ַ���Ҫ��ʱ�临�Ӷ�ΪO��n��
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

//12,һ�����������г�����������֮�⣬�������ֶ��������������ҳ�ֻ������һ�ε�����
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

//13�����������ַ������ӵ�һ����ɾ���ڶ��������е��ַ�
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

//14,�ж�һ�������Ƿ�Ϊ����������Ҫ���ǽ������ֵ�����������ԭ����������ȣ�������־��ǻ�������
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
		printf("����%d�ǻ���",num);
	}
	else
	{
		printf("����%d���ǻ�����",num);
	}
	system("pause");
	return 0;
}

//15����ο����ҵ�һ����������м�λ��
/*�趨����ָ��fast��slow����ָ����һ������ָ����������
��������ָ���ߵ��յ�ʱ����ָ���ߵ����м��λ��*/
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


//16,ʵ��pow(x,y)
/*
����pow(x,y)ʵ������x^y����x��y�η�������x��y��Ϊ������
�㷨�Ļ���˼���ǣ����ٳ˷��������ظ����ý����������磺
x^4����������˵Ļ�����Ҫ�Ĵγ˷���
������������ֽ�(x^2)*(x^2)��ֻ��Ҫ2���γ˷���
��Ϊx^2�Ľ�����ǿ����ظ����á���������������ԳƵķֽ�ָ��y��
Ȼ����x^(y/2)��ƽ����
�����㷨���£�
1 ���yΪż����ֱ�Ӽ���mypow(x, y/2)*mypow(x, y/2)��
2 ���yΪ��������y-1Ϊż�����ص��˵�һ�������
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
	if (y & 1 != 0) //����
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

//17,��һ����������������Ԫ�ص�ֵ��ӵ���k������������Ԫ�ص��±꣬Ҫ��ʱ�临�Ӷ�Ϊo(n),�ռ临�Ӷ�Ϊo(1)
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
	printf(" ���������±�Ϊ�� %d , %d ", i, j);
	system("pause");
	return 0;
}

//18���ж�һ�������ǲ���2��k�η�
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
		printf("��������2�ı���");
	}
	else
	{
		printf("�����ֲ���2�ı���");
	}
	system("pause");
	return 0;
}

//19�����ַ�������ѹ��
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

//20,ɾ���ַ�����β�Ŀո��м�������ո�ֻ�ܱ���һ����Ա�ַ���˳�򲻱�
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
	int flag = 0; //����û��ʼ����ո�
	int p = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		//�����ո� ��û��ʼ����
		if (!flag &&str[i] == '*')// �����ո� ��i�����ߵ����ǿո�ĵط�
		{
			i++;
		}
		//�������ǿո� ��û��ʼ����
		else if (!flag &&str[i] != '*')//���ǿո���ַ���ǰ��ֵ
		{
			flag = 1; //��ʼ����ո�
			str[p++] = str[i++];
		}
		//�����ո� ��ʼ������
		else if (flag &&str[i] == '*')
		{
			flag = 0; //������
			str[p++] = str[i++];
		}
		else
		{
			str[p++] = str[i++];
			flag = 1;
		}
	}
	if (str[p - 1] == '*') //��β������ո�
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


















