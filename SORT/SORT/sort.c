#include"sort.h"
//�鲢����******************************************************************************
void dealMergeSort(int *arr, int*tmp, int start, int end)//ʱ�临�Ӷ�:nlogn
{
	if (start >= end)//����Ҷ��
	{
		return;
	}
	int mid = (start + end) / 2;//����������
	dealMergeSort(arr, tmp, start, mid);//����������
	dealMergeSort(arr, tmp, mid + 1, end);//����������
	//��ʵ����һ���������ĺ������
	int a = start;
	int b = mid + 1;
	int c = a;
	int i;
	for (; a <= mid && b <= end;c++)//��a,b��ĳһ��Ԫ����ȫ��������c,ѭ������
	{
		if (arr[a] >= arr[b])//��֤mid��ߵ�ֵ�����ұߵ�С
		{
			tmp[c] = arr[b];
			b++;
		}
		else
		{
			tmp[c] = arr[a];
			a++;
		}
	}
	for (; a <= mid; a++,c++)//�����b��ȫ��������c,�ͽ�aʣ�ಿ�ֿ�����c
	{
		tmp[c] = arr[a];
	}
	for (; b <= end; b++, c++)//�����a��ȫ��������c,�ͽ�bʣ�ಿ�ֿ�����c
	{
		tmp[c] = arr[b];
	}
	for (i = 0; i <= end; i++)//tmpֻ��һ����ʱ��������Ҫ��tmp�е�ֵ������arr��
	{
		arr[i] = tmp[i];
	}
}

void mergeSort(int *arr, int n)
{
	int *tmp = (int *)malloc(n*sizeof(int));
	dealMergeSort(arr, tmp, 0, n - 1);
	free(tmp);
}
void printArray(int*arr, int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	putchar('\n');
}

//��������*******************************************************************************************
void swapArgs(int *a, int *b)
{
	int tmp=0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void dealQSort(int *arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int flag = 1;
	int i = start;
	int j = end;
	while(i<j)//��start��end������ʱ�򣬾��˳�
	{
		if (arr[i] > arr[j])//���ǰ��Ĵ��ں���ľͽ��н���
		{
			swapArgs(&arr[i], &arr[j]);
			flag = !flag;
		}
		if (flag)//��������ɹ����ͽ�jǰ��
		{
			j--;
		}
		else//�����iǰ��
		{
			i++;
		}
	}
	dealQSort(arr, start, i-1);//����������������
	dealQSort(arr, i + 1, end);//����������������
}
void quickSort(int *arr, int n)
{
	dealQSort(arr, 0, n - 1);
}