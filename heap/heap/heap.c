#include"heap.h"

void swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//�����µ����㷨
void DownJust(Heap *hp, int n)
{
	int cur = n;
	while (cur * 2 + 1<hp->_size)//���һ���ѵĽڵ�û����ڵ㣬��ô������Ҷ�ӣ�����ֱ������
	{
		if (hp->_a[cur] < hp->_a[2 * cur + 1])//�������ڵ���������Ӵ���ô��Ҫ���н���
		{
			if (cur*2+2 >= hp->_size //����Һ���Խ�磬��ôֱ�Ӻ����ӽ���
				|| hp->_a[2 * cur + 1] >= hp->_a[2 * cur + 2])//��������û���Һ���ʱ��Խ�磬������ӱ��Һ��Ӵ���ô�����ӽ�����������Һ��ӽ���
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 1]);//��ֵ
				cur = 2 * cur + 1;//��λ
			}
			else
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
				cur = 2 * cur + 2;
			}
		}
		else if (cur * 2 + 2<hp->_size && hp->_a[cur] < hp->_a[2 * cur + 2])//��ǰ�ڵ��Ѿ������Ӵ������С���Һ����Ҳ�Խ�磬�ͺ��Һ��ӽ���
		{
			swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
			cur = 2 * cur + 2;
		}
		else
		{
			break;//����ұ����Һ��Ӷ�����ô�Ͳ��ý���
		}
	}
}

//�ѵĳ�ʼ�������뱣֤��ʼ������һ���ѣ���Ҫ����ѵ����ԣ�
//1������ĳ���ڵ��ֵ���ǲ����ڻ�С���丸�ڵ��ֵ
//2��������һ����ȫ��������
void HeapInit(Heap *hp, HPDataType *a, int n)
{
	int i;
	hp->_capacity = MAXSIZE>n ? MAXSIZE:n;
	hp->_size = n;
	hp->_a=(HPDataType*)malloc(sizeof(HPDataType)* hp->_capacity);//maollc�п�
	memcpy(hp->_a, a, sizeof(HPDataType)*n);//��ԭ�����е�Ԫ�ؿ�����Ŀ��������
	for (i = n / 2 - 1; i >= 0; i--)//�����ĵ�һ����Ҷ�ӽڵ㣨n/2-1����ʼ����ΪҶ�ӽڵ㱾�����һ�����ˣ��������µ�����������������Ϊһ����
	{
		DownJust(hp, i);
	}
}
//�ѵĻ���
void HeapDestory(Heap *hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
//�ѵĲ��루��壩
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->_size;
	if (hp->_size == hp->_capacity)//�ڲ���ʱ��Ҫ �ж��Ƿ���Ҫ����
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	while (cur)//���ϵ����㷨
	{
		if (hp->_a[cur] > hp->_a[(cur - 1) / 2])//�ж��Ƿ�����ĸ��ڵ�󣬴�ͽ��н���
		{
			swap(&hp->_a[cur], &hp->_a[(cur - 1) / 2]);
			cur = (cur - 1) / 2;//����cur�䵽���ڵ��λ��
		}
		else
		{
			break;//�ȸ��ڵ�С����ֱ���˳�
		}
	}
}
//ɾ������ͷ�ڵ�
void HeapPop(Heap *hp)
{
	swap(hp->_a, hp->_a + hp->_size - 1);//�������ڵ�����һ���ڵ㣬ֱ��size--����pop�������һ���ڵ�
	hp->_size--;
	DownJust(hp, 0);//Ȼ��Ӹ��ڵ�������µ����㷨
}
//���ضѵ�ͷ�ڵ�
HPDataType HeapTop(Heap *hp)
{
	if (hp->_size == 0)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];//�����������Ԫ��
}
//���ᵱǰ�ѵĴ�С���ڵ������
int HeapSize_(Heap *hp)
{
	return hp->_size;//����size
}
//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap *hp)
{
	return hp->_size == 0;
}
// ������
void HeapSort(Heap *hp)
{
	int tmp = hp->_size;
	while( hp->_size >= 1)//���ϵĽ���pop���������Ƶ����һλ,���size��ԭ
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