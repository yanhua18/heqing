#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define ENDTAG '#'

typedef char BTDataType;



typedef struct BinaryTreeNode
{
	BTDataType _data;//��ǰ�ڵ��ֵ��
	struct BinaryTreeNode* _left;//ָ��ǰ�ڵ������
	struct BinaryTreeNode* _right;//ָ��ǰ�ڵ���Һ���
}BTNode;



// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a);
void BinaryTreeDestory(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);


// �ݹ����//������ȱ���
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);//������ȱ���



// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

//�ǵݹ����к������
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);



#endif