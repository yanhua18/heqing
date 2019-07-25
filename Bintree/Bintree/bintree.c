#include"bintree.h"
#include"queue.h"

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


void BinaryTreeLevelOrder(BTNode* root)//��α���
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