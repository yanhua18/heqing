#include"bintree.h"
#include"queue.h"
#include"stack.h"



// 构造一棵树
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
//递归型：前中后序遍历************************************************************************************************************************


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

//层次遍历************************************************************************************************************************

void BinaryTreeLevelOrder(BTNode* root)//层序遍历（树的广度优先搜索）
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

//非递归型：前中后序遍历************************************************************************************************************************

//非递归先序遍历
void BinaryTreePrevOrderNonR(BTNode* root)//根左右
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (cur||StackEmpty(&st))
	{
		printf("%c", cur->_data);//打印根

		if (cur->_right)//如果有右孩子，就让右孩子进栈
		{
			StackPush(&st, cur->_right);
		}
		if (cur->_left)//如果有左孩子，就让左孩子继续遍历
		{
			cur = cur->_left;
		}
		else//如果左孩子为空时，就让cur取栈顶，并释放原来的栈顶
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

//非递归中序遍历
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode * cur = root;

	Stack st;
	StackInit(&st);

	while (cur || StackEmpty(&st))//当cur为空且栈为空时，循环跳出，代表树遍历完毕
	{
		for (; cur; cur = cur->_left)
			//1，把目前的根及其所有的左孩子压栈，直到左孩子为空为止
			//2，以目前的右孩子为根，继续将它的左孩子压栈
		{
			StackPush(&st, cur);
		}

		//if (StackEmpty(&st))
		//{
			cur = StackTop(&st);
			//1，左孩子遍历完毕后，第一个没有左孩子的结点就是中序的第一个输出
			//2，如果右孩子为空，此时栈里将会是下一个要访问的结点，如果有右孩子，那么此时栈里将会是以那个右孩子
			putchar(cur->_data);
			//1，由于没有左孩子了，所以打印根（左根右）
			StackPop(&st);//出栈
			cur = cur->_right;
			//1，左孩子和根遍历结束后，遍历它的右子树
		//}
	}
	StackDestory(&st);
}

//非递归后序遍历
void BinaryTreePostOrderNonR(BTNode* root)//左右根
{
	BTNode * cur = root;

	Stack st;
	int tag[32] = { 0 };

	StackInit(&st);

	while (cur || StackEmpty(&st))//当cur为空且栈为空时，循环跳出，代表树遍历完毕
	{
		for (; cur; cur = cur->_left)//类似中序，将左孩子入栈，cur为空时，代表上一个节点的右孩子为空，只有这种情况才能进行打印
		{
			StackPush(&st, cur);//push操作会导致size+1
			tag[st._top] = 0;//由于入栈的是左孩子，所以这里的左孩子遍历标签置为0，（是否遍历完毕）
		}
		//只要上面的for只要执行一次，就不能进入while中
		while (StackEmpty(&st) && tag[st._top] == 1)//左孩子没有遍历完毕，不能进行打印
			//所以这里确保了只有左右子树都遍历完成后，才能进行打印
		{
			cur = StackTop(&st);
			putchar(cur->_data);//打印根
			StackPop(&st);//pop操作会导致size-1
			cur = NULL;//为了循环正常跳出
		}

		if (StackEmpty(&st))
		{
			tag[st._top] = 1;//进入这里证明左子树遍历完毕，左子树标签置1
			cur = StackTop(&st)->_right;//进入右子树继续遍历
		}
	}
	StackDestory(&st);
}

//判断一棵树是不是完全二叉树
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
		if (leafflag )//当出现有左孩子没有右孩子时，队列里剩余的值都只能有叶子节点，一旦出现左右孩子直接退出
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
		else if (tmp->_right&&!tmp->_left)//有右孩子没有左孩子时，一定不是完全二叉树，直接退出
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

void BinaryTreeDestory(BTNode* root)//前序遍历的摧毁
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



































//草稿部分代码###########################################################################################################
//非递归中序遍历
void _BinaryTreeInOrderNonR(BTNode* root)//左根右
{
	Stack st;
	BTNode* cur = root;
	StackInit(&st);
	while (1)
	{
		for (; cur; cur = cur->_left)//遍历每一个根的左子树，并将根和左子树压入栈中
		{
			StackPush(&st, cur);
		}
		while (1)//当左子树为空时，进入循环
		{
			cur = StackTop(&st);//取出栈顶，并打印，之后释放原栈顶
			printf("%c", cur->_data);
			StackPop(&st);

			if (cur->_right)//判断取出来的结点是否有右子树，存在就指向他的右子树，并退出循环（为了让新节点的左子树进栈）
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


//非递归后序遍历
void _BinaryTreePostOrderNonR(BTNode* root)//压根右左
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
