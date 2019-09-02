#include"sort.h"

#if 0
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
	for (; a <= mid && b <= end;c++)//��ʱ��mid���������Ѿ����򣬵�a,b��ĳһ��Ԫ����ȫ��������c,ѭ������
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
//ǰ��ָ��汾##########################################################################
void swapArgs(int *a, int *b)
{
	int tmp=0;
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
		else//�����i����
		{
			i++;
		}
	}
	dealQSort(arr, start, i-1);//����������������
	dealQSort(arr, i + 1, end);//����������������
}



//�ڿӷ��汾########################################################################
void dealquickSort(int *arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int flag = 1;
	int i = start;
	int j = end;
	int tmp = arr[start];
	while (i<j)//��start��end������ʱ�򣬾��˳�
	{
		if (flag&&tmp > arr[j])
		{
			arr[i] = arr[j];
			flag = !flag;
		}
		if (!flag&&tmp < arr[i])
		{
			arr[j] = arr[i];
			flag = !flag;
		}
		flag ? j-- : i++;
	}
	arr[i] = tmp;
	dealquickSort(arr, start, i - 1);//����������������
	dealquickSort(arr, i + 1, end);//����������������
}


void quickSort(int *arr, int n)
{
	dealquickSort(arr, 0, n - 1);
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



//hoare��####################################################################################################
void swapArgs(int *a, int *b)
{
	int tmp=0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int * arr, int n)
{
	int i, j;
	int tmp;

	for (i = 1; i < n; i++)
	{
		tmp = arr[i];

		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}

		arr[j] = tmp;
	}
}


int Partition(int * arr, int start, int end)
{
	int mid = (start + end) / 2;

	if (arr[start] > arr[mid])
	{
		swapArgs(arr + start, arr + mid);
	}
	if (arr[mid] > arr[end])
	{
		swapArgs(arr + mid, arr + end);
	}
	if (arr[start] > arr[mid])
	{
		swapArgs(arr + start, arr + mid);
	}

	if (end - start <= 2)
	{
		return mid;
	}

	swapArgs(arr + mid, arr + end - 1);

	int i = start + 1;
	int j = end - 2;

	while (arr[i] < arr[end - 1])
	{
		i++;
	}

	while (arr[j] > arr[end - 1])
	{
		j--;
	}

	while (i < j)
	{
		swapArgs(arr + i, arr + j);
		j--, i++;

		while (arr[i] < arr[end - 1])
		{
			i++;
		}

		while (arr[j] > arr[end - 1])
		{
			j--;
		}
	}

	swapArgs(arr + i, arr + end - 1);
	return i;
}
void dealHQSort(int * arr, int start, int end)
{
	if (end - start > INSERT_SORT_LENTH)
	{
		int pivot = Partition(arr, start, end);
		dealHQSort(arr, start, pivot - 1);
		dealHQSort(arr, pivot + 1, end);
	}
	else
	{
		InsertSort(arr + start, end - start + 1);
	}
}

void HQSort(int * arr, int n)
{
	dealHQSort(arr, 0, n - 1);
	//QuickSortNonR(arr, 0, n - 1);
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

#endif

//ϣ������****************************************************************************************************
void ShellSort(int * arr, int n)
{
	int i, j, k;
	int tmp;
	int gap = n / 2;

	for (; gap > 0; gap /= 2)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = k + gap; i < n; i += gap)
			{
				tmp = arr[i];

				for (j = i; j > 0 && arr[j - gap] > tmp; j -= gap)
				{
					arr[j] = arr[j - gap];
				}

				arr[j] = tmp;
			}
		}
	}
}

