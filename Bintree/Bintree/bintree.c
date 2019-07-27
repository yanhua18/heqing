#include"bintree.h"
#include"queue.h"
#include"stack.h"



// ����һ����
BTNode* BinaryTreeCreate(BTDataType* a)//����һ����
{
	static int i = 0;
	if (a[i] == ENDTAG)
	{
		i++;
		return NULL;
	}
	else
	{
		BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
		cur->_data = a[i];
		i++;
		cur->_left = BinaryTreeCreate(a);
		cur->_right = BinaryTreeCreate(a);
		return cur;
	}
}
//�ݹ��ͣ�ǰ�к������************************************************************************************************************************


void BinaryTreePrevOrder(BTNode* root)//���������������
{ 
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root)//���������������
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//�������ĺ������
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}

//��α���************************************************************************************************************************

void BinaryTreeLevelOrder(BTNode* root)//������������Ĺ������������
{
	Queue qu;
	BTNode *tmp;//�����tmpʼ��ָ���ͷ��data���Դ����ж��Ƿ������Һ��ӣ��Ƿ���Ҫ���в������
	QueueInit(&qu);
	QueuePush(&qu, root);//�ڶ��г�ʼ�����Ȳ�����ڵ㣬���ܼ������в���
	while (!QueueEmpty(&qu))//�ǿշ���1������1���Ǳ�ʾΪ�٣��˳�ѭ��
	{
		tmp = QueueFront(&qu); //QueueFront�ķ���ֵdata��BTNode *���͵ģ����������һ�����ڵ��data��_left, _right
		printf("%c", tmp->_data);//��ӡ�ڵ��ֵ
		if (tmp->_left)//�õ�tmpΪ���еĵ�һ���ڵ㣬�ж��������Ƿ�Ϊ�գ���Ϊ�վ��������ӽ�����
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right)//�õ�tmpΪ���еĵ�һ���ڵ㣬�ж����Һ����Ƿ�Ϊ�գ���Ϊ�վ������Һ��ӽ�����
		{
			QueuePush(&qu, tmp->_right);
		}
		QueuePop(&qu);//ɾ����ͷ���Ѿ���ӡ������������ͷ
	}
	QueueDestory(&qu);//�ݻٶ���
}

//�ǵݹ��ͣ�ǰ�к������************************************************************************************************************************

//�ǵݹ��������
void BinaryTreePrevOrderNonR(BTNode* root)//������
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (cur||StackEmpty(&st))
	{
		printf("%c", cur->_data);//��ӡ��

		if (cur->_right)//������Һ��ӣ������Һ��ӽ�ջ
		{
			StackPush(&st, cur->_right);
		}
		if (cur->_left)//��������ӣ��������Ӽ�������
		{
			cur = cur->_left;
		}
		else//�������Ϊ��ʱ������curȡջ�������ͷ�ԭ����ջ��
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

//�ǵݹ��������
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st);

	while (cur || StackEmpty(&st))//��curΪ����ջΪ��ʱ��ѭ���������������������
	{
		for (; cur; cur = cur->_left)
			//1����Ŀǰ�ĸ��������е�����ѹջ��ֱ������Ϊ��Ϊֹ
			//2����Ŀǰ���Һ���Ϊ������������������ѹջ
		{
			StackPush(&st, cur);
		}

		//if (StackEmpty(&st))
		//{
			cur = StackTop(&st);
			//1�����ӱ�����Ϻ󣬵�һ��û�����ӵĽ���������ĵ�һ�����
			//2������Һ���Ϊ�գ���ʱջ�ｫ������һ��Ҫ���ʵĽ�㣬������Һ��ӣ���ô��ʱջ�ｫ�������Ǹ��Һ���
			putchar(cur->_data);
			//1������û�������ˣ����Դ�ӡ��������ң�
			StackPop(&st);//��ջ
			cur = cur->_right;
			//1�����Ӻ͸����������󣬱�������������
		//}
	}
	StackDestory(&st);
}

//�ǵݹ�������
void BinaryTreePostOrderNonR(BTNode* root)//���Ҹ�
{
	BTNode * cur = root;

	Stack st;
	int tag[32] = { 0 };

	StackInit(&st);

	while (cur || StackEmpty(&st))//��curΪ����ջΪ��ʱ��ѭ���������������������
	{
		for (; cur; cur = cur->_left)//�������򣬽�������ջ��curΪ��ʱ��������һ���ڵ���Һ���Ϊ�գ�ֻ������������ܽ��д�ӡ
		{
			StackPush(&st, cur);//push�����ᵼ��size+1
			tag[st._top] = 0;//������ջ�������ӣ�������������ӱ�����ǩ��Ϊ0�����Ƿ������ϣ�
		}
		//ֻҪ�����forֻҪִ��һ�Σ��Ͳ��ܽ���while��
		while (StackEmpty(&st) && tag[st._top] == 1)//����û�б�����ϣ����ܽ��д�ӡ
			//��������ȷ����ֻ������������������ɺ󣬲��ܽ��д�ӡ
		{
			cur = StackTop(&st);
			putchar(cur->_data);//��ӡ��
			StackPop(&st);//pop�����ᵼ��size-1
			cur = NULL;//Ϊ��ѭ����������
		}

		if (StackEmpty(&st))
		{
			tag[st._top] = 1;//��������֤��������������ϣ���������ǩ��1
			cur = StackTop(&st)->_right;//������������������
		}
	}
	StackDestory(&st);
}

//�ж�һ�����ǲ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode *tmp;
	int leafflag = 0;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueEmpty(&qu))
	{
		tmp = QueueFront(&qu); 
		printf("%c", tmp->_data);
		QueuePop(&qu);
		if (leafflag )//������������û���Һ���ʱ��������ʣ���ֵ��ֻ����Ҷ�ӽڵ㣬һ���������Һ���ֱ���˳�
		{
			if (tmp->_left || tmp->_right)
			{
				return 0;
			}
			continue;
		}
		if (tmp->_left&&tmp->_right)
		{
			QueuePush(&qu, tmp->_left);
			QueuePush(&qu, tmp->_right);
		}
		else if (tmp->_right&&!tmp->_left)//���Һ���û������ʱ��һ��������ȫ��������ֱ���˳�
		{
			return 0;
		}
		else
		{
			leafflag = 1;
			if (tmp->_left)
			{
				QueuePush(&qu, tmp->_left);
			}
		}
	}
	QueueDestory(&qu);
}

void BinaryTreeDestory(BTNode* root)//ǰ������Ĵݻ�
{
	BTNode *left;
	BTNode *right;
	if (root)
	{
		left = root->_left;
		right = root->_right;
		free(root);
		BinaryTreeDestory(left);
		BinaryTreeDestory(right);
	}
}



































//�ݸ岿�ִ���###########################################################################################################
//�ǵݹ��������
void _BinaryTreeInOrderNonR(BTNode* root)//�����
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (1)
	{
		for (; cur; cur = cur->_left)//����ÿһ����������������������������ѹ��ջ��
		{
			StackPush(&st, cur);
		}
		while (1)//��������Ϊ��ʱ������ѭ��
		{
			cur = StackTop(&st);//ȡ��ջ��������ӡ��֮���ͷ�ԭջ��
			printf("%c", cur->_data);
			StackPop(&st);

			if (cur->_right)//�ж�ȡ�����Ľ���Ƿ��������������ھ�ָ�����������������˳�ѭ����Ϊ�����½ڵ����������ջ��
			{
				cur = cur->_right;
				break;
			}
			if (!StackEmpty(&st))
			{
				StackDestory(&st);
				return;
			}
		}
	}
}

int SeqFind(BTNode* src[], int size, BTNode* f)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (src[i] == f)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}


//�ǵݹ�������
void _BinaryTreePostOrderNonR(BTNode* root)//ѹ������
{
	Stack st;
	BTNode * cur = root;
	BTNode * visited[20];
	int size;
	StackInit(&st);
	StackPush(&st, root);
	while (1)
	{
		if (cur->_right)
		{
			if (!SeqFind(visited, size, cur->_right))
			{
				StackPush(&st, cur->_right);
				visited[size] = cur->_right;
				size++;
			}
		}
		if (cur->_left)
		{
			if (!SeqFind(visited, size, cur->_right))
			{
				StackPush(&st, cur->_left);
				visited[size] = cur->_right;
				size++;
				cur = cur->_left;
			}
		}
		else
		{
			cur = StackTop(&st);
			printf("%c", cur->_data);
			StackPop(&st);
		}
	}
}
