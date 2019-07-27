#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define ENDTAG '#'

typedef char BTDataType;



typedef struct BinaryTreeNode
{
	BTDataType _data;//当前节点的值域
	struct BinaryTreeNode* _left;//指向当前节点的左孩子
	struct BinaryTreeNode* _right;//指向当前节点的右孩子
}BTNode;



// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);


// 递归遍历//深度优先遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);//广度优先遍历



// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

//非递归先中后序遍历
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);



#endif