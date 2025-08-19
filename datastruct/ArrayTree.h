#pragma once
//��̬����(����)������
#ifndef __ARRAYTREE_H__
#define __ARRAYTREE_H__


#define ArrayTree_MAXSIZE 10
#define	Null			  -1

typedef char ArrayTree_ElementType;
typedef int ArrayTree_BinTree;

struct ArrayTree_BinTreeNode
{
	ArrayTree_ElementType Element;
	ArrayTree_BinTree Left;		//������������е��±�
	ArrayTree_BinTree Right;	//�Ҷ����������е��±�
};

void ArrayTree_BinTreeNode_ArrayInit(struct ArrayTree_BinTreeNode T[], int ArrayNumber);
int ArrayTree_BuildTree(struct ArrayTree_BinTreeNode T[], int BinTreeNode_Number);

#endif // !__ARRAYTREE_H__
