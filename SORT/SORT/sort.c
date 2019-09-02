#include"sort.h"

#if 0
//归并排序******************************************************************************
void dealMergeSort(int *arr, int*tmp, int start, int end)//时间复杂度:nlogn
{
	if (start >= end)//到了叶子
	{
		return;
	}
	int mid = (start + end) / 2;//分左右子树
	dealMergeSort(arr, tmp, start, mid);//遍历左子树
	dealMergeSort(arr, tmp, mid + 1, end);//遍历右子树
	//其实这是一个二叉树的后序遍历
	int a = start;
	int b = mid + 1;
	int c = a;
	int i;
	for (; a <= mid && b <= end;c++)//此时的mid左右两边已经有序，当a,b中某一个元素完全拷贝到了c,循环跳出
	{
		if (arr[a] >= arr[b])//保证mid左边的值都比右边的小
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
	for (; a <= mid; a++,c++)//如果是b完全拷贝到了c,就将a剩余部分拷贝到c
	{
		tmp[c] = arr[a];
	}
	for (; b <= end; b++, c++)//如果是a完全拷贝到了c,就将b剩余部分拷贝到c
	{
		tmp[c] = arr[b];
	}
	for (i = 0; i <= end; i++)//tmp只是一个临时变量，需要将tmp中的值拷贝到arr中
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

//快速排序*******************************************************************************************
//前后指针版本##########################################################################
void swapArgs(int *a, int *b)
{
	int tmp=0;
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
	while(i<j)//当start和end交换的时候，就退出
	{
		if (arr[i] > arr[j])//如果前面的大于后面的就进行交换
		{
			swapArgs(&arr[i], &arr[j]);
			flag = !flag;
		}
		if (flag)//如果交换成功，就将j前移
		{
			j--;
		}
		else//否则就i后移
		{
			i++;
		}
	}
	dealQSort(arr, start, i-1);//对左子树进行排序
	dealQSort(arr, i + 1, end);//对右子树进行排序
}



//挖坑法版本########################################################################
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
	while (i<j)//当start和end交换的时候，就退出
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
	dealquickSort(arr, start, i - 1);//对左子树进行排序
	dealquickSort(arr, i + 1, end);//对右子树进行排序
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



//hoare法####################################################################################################
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

//希尔排序****************************************************************************************************
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

