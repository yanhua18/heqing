#include"heap.h"

void swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//堆向下调整算法
void DownJust(Heap *hp, int n)
{
	int cur = n;
	while (cur * 2 + 1<hp->_size)//如果一个堆的节点没有左节点，那么它就是叶子，所以直接跳出
	{
		if (hp->_a[cur] < hp->_a[2 * cur + 1])//如果这个节点比它的左孩子大，那么就要进行交换
		{
			if (cur*2+2 >= hp->_size //如果右孩子越界，那么直接和左孩子交换
				|| hp->_a[2 * cur + 1] >= hp->_a[2 * cur + 2])//当有左孩子没有右孩子时会越界，如果左孩子比右孩子大，那么和左孩子交换，否则和右孩子交换
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 1]);//换值
				cur = 2 * cur + 1;//换位
			}
			else
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
				cur = 2 * cur + 2;
			}
		}
		else if (cur * 2 + 2<hp->_size && hp->_a[cur] < hp->_a[2 * cur + 2])//当前节点已经比左孩子大，如果它小于右孩子且不越界，就和右孩子交换
		{
			swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
			cur = 2 * cur + 2;
		}
		else
		{
			break;//如果我比左右孩子都大，那么就不用交换
		}
	}
}

//堆的初始化（必须保证初始化后是一个堆，需要满足堆的特性：
//1，堆中某个节点的值总是不大于或不小于其父节点的值
//2，堆总是一颗完全二叉树）
void HeapInit(Heap *hp, HPDataType *a, int n)
{
	int i;
	hp->_capacity = MAXSIZE>n ? MAXSIZE:n;
	hp->_size = n;
	hp->_a=(HPDataType*)malloc(sizeof(HPDataType)* hp->_capacity);//maollc判空
	memcpy(hp->_a, a, sizeof(HPDataType)*n);//将原数组中的元素拷贝到目标数组中
	for (i = n / 2 - 1; i >= 0; i--)//从它的第一个非叶子节点（n/2-1）开始（因为叶子节点本身就是一个堆了）进行向下调整，来是这个数组成为一个堆
	{
		DownJust(hp, i);
	}
}
//堆的毁灭
void HeapDestory(Heap *hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
//堆的插入（后插）
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->_size;
	if (hp->_size == hp->_capacity)//在插入时需要 判断是否需要扩容
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	while (cur)//向上调整算法
	{
		if (hp->_a[cur] > hp->_a[(cur - 1) / 2])//判断是否比它的父节点大，大就进行交换
		{
			swap(&hp->_a[cur], &hp->_a[(cur - 1) / 2]);
			cur = (cur - 1) / 2;//并让cur变到父节点的位置
		}
		else
		{
			break;//比父节点小，就直接退出
		}
	}
}
//删除根的头节点
void HeapPop(Heap *hp)
{
	swap(hp->_a, hp->_a + hp->_size - 1);//交换根节点和最后一个节点，直接size--，就pop掉了最后一个节点
	hp->_size--;
	DownJust(hp, 0);//然后从根节点进行向下调整算法
}
//返回堆的头节点
HPDataType HeapTop(Heap *hp)
{
	if (hp->_size == 0)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];//返回数组的首元素
}
//范会当前堆的大小（节点个数）
int HeapSize_(Heap *hp)
{
	return hp->_size;//返回size
}
//判断堆是否为空
int HeapEmpty(Heap *hp)
{
	return hp->_size == 0;
}
// 堆排序
void HeapSort(Heap *hp)
{
	int tmp = hp->_size;
	while( hp->_size >= 1)//不断的进行pop操作将根移到最后一位,最后将size复原
	{
		HeapPop(hp);
	}
	hp->_size = tmp;
}

void HeapPrint(Heap *hp)
{
	int i;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}