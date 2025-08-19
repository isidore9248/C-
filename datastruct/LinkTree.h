#pragma once
#ifndef __LINKTREE_H__
#define __LINKTREE_H__

typedef int LinkTree_ElementType;

/*��������*/
typedef struct LinkTreeNode* BinLinkTree;
struct LinkTreeNode
{
	LinkTree_ElementType Data;
	BinLinkTree Left;
	BinLinkTree Right;
};
typedef BinLinkTree	Position;	//���ڶ���������


/*��������*/
struct TriTreeNode
{
	LinkTree_ElementType Data;
	struct TriTreeNode* LeftChild;
	struct TriTreeNode* RightChild;
	struct TriTreeNode* ParentChild;
};

//������
void LinkTree_Recurrence_PreOrderTraversal(BinLinkTree Ptlt);
void LinkTree_Recurrence_InOrderTraversal(BinLinkTree Ptlt);
void LinkTree_Recurrence_PostOrderTraversal(BinLinkTree Ptlt);
void LinkTree_Stack_InOrderTraversal(BinLinkTree Ptlt);
void LinkTree_Level_OrderTraversal(BinLinkTree Ptlt);

//����Ϊ��������ʵ��Ӧ��
//void LinkTree_PreOrderCreatBinTree(BinLinkTree Ptlt);
void LinkTree_GetLeafNode(BinLinkTree Ptlt);
int LinkTree_GetHeight(BinLinkTree Ptlt);

//����������
Position LinkTree_BinSearchTree_RecursionFind(LinkTree_ElementType Item, BinLinkTree Ptlt);
Position LinkTree_BinSearchTree_IterationFind(LinkTree_ElementType Item, BinLinkTree Ptlt);
Position LinkTree_BinSearchTree_RecursionFindMin(BinLinkTree Ptlt);
Position LinkTree_BinSearchTree_IterationFindMin(BinLinkTree Ptlt);
Position LinkTree_BinSearchTree_RecursionFindMax(BinLinkTree Ptlt);
Position LinkTree_BinSearchTree_IterationFindMax(BinLinkTree Ptlt);
BinLinkTree LinkTree_BinSearchTree_Insert(LinkTree_ElementType Item, BinLinkTree Ptlt);
BinLinkTree LinkTree_BinSearchTree_Delete(LinkTree_ElementType Item, BinLinkTree Ptlt);




#endif // !__LINKTREE_H__
