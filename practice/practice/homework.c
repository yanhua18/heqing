//1，在一个二维数组中，每一行按照从左到右递增的顺序排列，每一列按照从上到下递增的顺序排列，输入一个整数判断是否存在这个二维数组中，时间复杂度（O（row+col））
#include<stdio.h>
#include<windows.h>
//int search(int *arr[][4], int data, int *m, int *n)
//{
//	int i = 0, j = *n-1;
//	while (i <*m && j >=0 )
//	{
//		if (arr[i][j] < data)
//		{
//			i++;
//		}
//		if (arr[i][j] > data)
//		{
//			j--;
//		}
//		if (arr[i][j] == data)
//		{
//			*m = i;
//			*n = j;
//			return;
//		}
//	}
//	*m = -1;
//	*n = -1;
//}
//int main()
//{
//	int i = 4, j = 4;
//	int arr[4][4] = 
//	  { 1, 2, 8, 9,
//		2, 4, 9, 12,
//		4, 7, 10, 13,
//		6, 8, 11, 15 };
//	int data = 7;
//	int m = 4, n = 4;
//	search(arr, data, &m, &n);
//	printf("该数字在数组中的下标为：<%d,%d>\n", m, n);
//	system("pause");
//	return 0;
//}
//2，将字符串中的空格转换成%20
#if 0
char * change(char *arr1,char *arr2)
{
	char arr[20];
	int i = 0;
	char *_arr2 = arr2;
	while (i < 20)
	{
		while (*arr1 != '\0')
		{
			if (*arr1 == ' ')
			{
				for (; *_arr2 != '\0'; _arr2++)
				{
					arr[i] = *_arr2;
					i++;
				}
				_arr2 = arr2;
				arr1++;
			}
			else
			{
				arr[i] = *arr1;
				arr1++;
				i++;
			}
		}
		arr[i] = '\0';
		printf("%s\n", arr);
		return;
	}
}
int main()
{
	char arr1[] = "abc defgx yz";
	char arr2[] = "%20";
	change(arr1, arr2);
	system("pause");
	return 0;
}
#endif
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