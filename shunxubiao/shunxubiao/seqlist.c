#include"seqlist.h"


void SeqListInit(SeqList *psl, int capacity)
{
	assert(psl);
	psl->array = (SLDataType *)calloc(capacity, sizeof(SLDataType));//���붯̬�ڴ�ռ�
	psl->size = 0;
	psl->capacity = capacity;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->array)//��ֹ�ظ��ͷ�
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}
void CheckCapacity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity*sizeof(SLDataType));
		assert(psl->array);
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//���һ��x
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)//��ɾһ����
{
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//ǰ��һ����x(�����е�������ƶ�һλ�ٲ���Ҫ�����)
{
	assert(psl);
	CheckCapacity(psl);
	int i = 0;
	for (i = psl->size-1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//ǰɾһ�������ú�һ����������ǰһ������
{
	assert(psl);
	CheckCapacity(psl);
	int i = 0;
	for (i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int i = 0;
	for (i = psl->size-1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	CheckCapacity(psl);
	int i = 0;
	for (i = pos; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//�ҵ�x���ֲ��������±�
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	SeqListErase(psl, SeqListFind(psl, x));
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	psl->array[pos] = x;
}
void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size-1; i++)
	{
		for (j = 0; j < psl->size - 1 - i; j++)
		{
			if (psl->array[j + 1] < psl->array[j])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int start = 0;
	int end = psl->size - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (x>psl->array[mid])
		{
			start = mid + 1;
		}
		else if (x<psl->array[mid])
		{
			end = mid - 1;
		}
		else
		{
			printf("�ҵ���%d���±�Ϊ%d \n",x, mid);
			return mid;
		}
	}
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	SLDataType *tmp = (SLDataType *)calloc(psl->capacity, sizeof(SLDataType));//���붯̬�ڴ�ռ�
	int i, j;
	for (i = 0, j = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			tmp[j] = psl->array[i];
			j++;
		}
	}
	free(psl->array);
	psl->array = tmp;
	psl->size = j;
}
