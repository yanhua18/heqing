#include"bintree.h"
#include"queue.h"
#include"stack.h"

int main()
{
	//BTNode *BT = BinaryTreeCreate("ABD##E#H##CF##G##");
	BTNode *BT = BinaryTreeCreate("ABD##EJ###CF##G##");
	BinaryTreePrevOrder(BT);
	putchar('\n');
	BinaryTreeInOrder(BT);
	putchar('\n');
	BinaryTreePostOrder(BT);
	putchar('\n');
	BinaryTreeLevelOrder(BT);
	putchar('\n');
	BinaryTreePrevOrderNonR(BT);
	putchar('\n');
	BinaryTreeInOrderNonR(BT);
	putchar('\n');
	BinaryTreePostOrderNonR(BT);
	putchar('\n');
	printf("%d", BinaryTreeComplete(BT));
	putchar('\n');

	BinaryTreeDestory(BT);



	//Queue qu;
	//QueueInit(&qu);
	//QueuePush(&qu, 5);
	//QueuePush(&qu, 6);
	//QueuePush(&qu, 7);
	//QueuePush(&qu, 8);
	//printf("%d\n", QueueFront(&qu));
	//QueuePop(&qu);
	//printf("%d\n", QueueFront(&qu));
	//QueuePop(&qu);
	//printf("%d\n", QueueFront(&qu));
	//QueuePop(&qu);
	//printf("%d\n", QueueFront(&qu));


	//QueueDestory(&qu);
	system("pause");
	return 0;
}  