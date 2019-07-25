#include"bintree.h"
#include"queue.h"

BTNode* BinaryTreeCreate(BTDataType* a)//构造一棵树
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

void BinaryTreePrevOrder(BTNode* root)//二叉树的先序遍历
{ 
	if (root != NULL)
	{
		printf("%c", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root)//二叉树的中序遍历
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c", root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root)//二叉树的后序遍历
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c", root->_data);
	}
}


void BinaryTreeLevelOrder(BTNode* root)//层次遍历
{
	Queue qu;
	BTNode *tmp;//定义的tmp始终指向队头的data，以此来判断是否有左右孩子，是否需要进行插入操作
	QueueInit(&qu);
	QueuePush(&qu, root);//在队列初始化后，先插入根节点，才能继续下列操作
	while (!QueueEmpty(&qu))//是空返回1，（！1）是表示为假，退出循环
	{
		tmp = QueueFront(&qu); //QueueFront的返回值data是BTNode *类型的，里面包含了一个树节点的data，_left, _right
		printf("%c", tmp->_data);//打印节点的值
		if (tmp->_left)//得到tmp为队列的第一个节点，判断其左孩子是否为空，不为空就让其左孩子进队列
		{
			QueuePush(&qu, tmp->_left);
		}
		if (tmp->_right)//得到tmp为队列的第一个节点，判断其右孩子是否为空，不为空就让其右孩子进队列
		{
			QueuePush(&qu, tmp->_right);
		}
		QueuePop(&qu);//删除队头（已经打印过），更换队头
	}
	QueueDestory(&qu);//摧毁队列
}