#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Arraystack.h"	//�����ջ
#include "ArrayQueue.h"	//�������
#include "LinkTree.h"	//���������


/// <summary>	�ݹ鷨����(��������)����������
/// <param name="Ptlt"></param>		ָ�룬ָ��Ҫ�����Ķ�����
void LinkTree_Recurrence_PreOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		printf("%d\n", Ptlt->Data);
		LinkTree_Recurrence_PreOrderTraversal(Ptlt->Left);
		LinkTree_Recurrence_PreOrderTraversal(Ptlt->Right);
	}
}


/// <summary>	�ݹ鷨����(�󡢸�����)����������
/// <param name="Ptlt"></param>		ָ�룬ָ��Ҫ�����Ķ�����
void LinkTree_Recurrence_InOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		LinkTree_Recurrence_InOrderTraversal(Ptlt->Left);
		printf("%d\n", Ptlt->Data);
		LinkTree_Recurrence_InOrderTraversal(Ptlt->Right);
	}
}


/// <summary>	�ݹ鷨����(���ҡ���)����������
/// <param name="Ptlt"></param>		ָ�룬ָ��Ҫ�����Ķ�����
void LinkTree_Recurrence_PostOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		LinkTree_Recurrence_PostOrderTraversal(Ptlt->Left);
		LinkTree_Recurrence_PostOrderTraversal(Ptlt->Right);
		printf("%d\n", Ptlt->Data);
	}
}



/// <summary>	��ջ��(�ǵݹ�)ʵ���������������
/// <param name="Ptlt"></param>		ָ�룬ָ��Ҫ�����Ķ�����
void LinkTree_Stack_InOrderTraversal(BinLinkTree Ptlt)
{
	BinLinkTree LinkTree = Ptlt;	//ת��Ҫ���б�����������
	S_Stack LinkTree_ArrayS_Stack = S_ArrayStack_Creat();	//��������ʼ����ջ
	while (LinkTree || !S_ArrayStack_IsEmpty(LinkTree_ArrayS_Stack))
	{
		while (LinkTree)
		{
			Arraystack_Push(LinkTree_ArrayS_Stack, LinkTree);	//���ڵ���ջ
			LinkTree = LinkTree->Left;
		}
		if (!S_ArrayStack_IsEmpty(LinkTree_ArrayS_Stack))
		{
			LinkTree=Arraystack_Pop(LinkTree_ArrayS_Stack);		//�ڵ��ջ������LinkTree
			
			/*�������ʱ������һ������Arraystack_Push֮ǰ*/
			printf("%d\n", LinkTree->Data);		
			
			LinkTree = LinkTree->Right;		//ת��������
		}

	}

}



/// <summary>	�������������
/// <param name="Ptlt"></param>
void LinkTree_Level_OrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt) { return; }

	ArrayQueue Queue = ArrayQueue_CreatQueue();
	BinLinkTree LinkTree = Ptlt;

	ArrayQueue_Add(Queue, LinkTree);	//�Ƚ��ڵ����

	while (!ArrayQueue_IsEmpty(Queue))
	{
		LinkTree = ArrayQueue_Delete(Queue);
		printf("%d\n", LinkTree->Data);
		if(LinkTree->Left){ ArrayQueue_Add(Queue, LinkTree->Left); }
		if(LinkTree->Right){ ArrayQueue_Add(Queue, LinkTree->Right); }
	}

}

//�����㷨����������
void LinkTree_PreOrderCreatBinTree(BinLinkTree Ptlt)
{
	int Data;
	scanf(&Data);

	if (Data == '#') { Ptlt = NULL; }
	else
	{
		Ptlt->Data = Data;
		LinkTree_PreOrderCreatBinTree(Ptlt->Left);
		LinkTree_PreOrderCreatBinTree(Ptlt->Right);
	}
	return;

}

/*
typedef struct BiNode{
TElemType data;
struct BiNode *child,*rchild;//���Һ���ָ��
}BiNode,*BiTree;
*/




/// <summary>	���������������Ҷ�ӽڵ�(û���ӽڵ�Ľڵ�)���ɵݹ��㷨���������ʵ��
/// <param name="Ptlt"></param>	ָ�룬ָ�������
void LinkTree_GetLeafNode(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		if (!Ptlt->Left && !Ptlt->Right) { printf("%d\n", Ptlt->Data); }
		LinkTree_GetLeafNode(Ptlt->Left);
		LinkTree_GetLeafNode(Ptlt->Right);

	}

}


/// <summary>	���㲢���ض������ĸ߶ȣ��ɵݹ��㷨�ĺ������ʵ��
/// <param name="Ptlt"></param>	ָ�룬ָ�������
///	˼·�� MaxHeight=Max(LeftHeight,RightHeight)+1
int LinkTree_GetHeight(BinLinkTree Ptlt)
{
	int LeftHeight = 0, RightHeight = 0, MaxHeight = 0;
	if (Ptlt)
	{
		LeftHeight= LinkTree_GetHeight(Ptlt->Left);		//�����������
		RightHeight= LinkTree_GetHeight(Ptlt->Right);	//�����������
		
		////MaxHeight=Max(LeftHeight,RightHeight)+1
		MaxHeight = (LeftHeight > RightHeight) ? LeftHeight : RightHeight;	
		return (MaxHeight + 1);
	}
	return 0;	//�������Ϊ0

}


/// <summary>	�ݹ鷨Ѱ�Ҷ�����������Ԫ��
/// <param name="Item"></param>	Ҫ���ҵ�Ԫ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
/// <note>	typedef BinLinkTree	Position;	//���ڶ���������
Position LinkTree_BinSearchTree_RecursionFind(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	if (!Ptlt)	{return NULL;}	//��Ϊ�ս�if
	
	//����Ϊ�ǿ�
	if (Item > Ptlt->Data)
	{
		return LinkTree_BinSearchTree_RecursionFind(Item, Ptlt->Right);
	}
	else if(Item<Ptlt->Left)
	{
		return LinkTree_BinSearchTree_RecursionFind(Item, Ptlt->Left);
	}
	else	//Item==Ptlt->Left
	{
		return Ptlt;
	}
}


/// <summary>	�ǵݹ�(������)Ѱ�Ҷ�����������Ԫ��
/// <param name="Item"></param>	Ҫ���ҵ�Ԫ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
/// <note>	typedef BinLinkTree	Position;	//���ڶ���������
Position LinkTree_BinSearchTree_IterationFind(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	while (Ptlt)	//���ǿ�ʱ��ѭ��
	{
		if (Item > Ptlt->Data)
		{
			Ptlt = Ptlt->Right;
		}
		else if (Item < Ptlt->Data)
		{
			Ptlt = Ptlt->Left;
		}
		else
		{
			return Ptlt;
		}
	}
	return NULL;	//��Ϊ��ֱ���˳�
}

/// <summary>	�ݹ鷨������СԪ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
Position LinkTree_BinSearchTree_RecursionFindMin(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }		//��Ϊ��
	
	if (!Ptlt->Left) { return Ptlt; }	//������Ϊ��
	return LinkTree_BinSearchTree_RecursionFindMin(Ptlt->Left); 	
}

/// <summary>	�ǵݹ�(������)������СԪ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
Position LinkTree_BinSearchTree_IterationFindMin(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	while (Ptlt->Left)	//��������Ϊ��
	{
		Ptlt = Ptlt->Left;
	}
	return Ptlt;
}

/// <summary>	�ݹ鷨�������Ԫ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
Position LinkTree_BinSearchTree_RecursionFindMax(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	if (Ptlt->Right)
	{
		return LinkTree_BinSearchTree_RecursionFindMax(Ptlt->Right);
	}
	return Ptlt;	//	Ptlt->Right==NULL;
}

/// <summary>	�ǵݹ�(������)�������Ԫ��
/// <param name="Ptlt"></param>	ָ�룬ָ�����������������
/// <returns></returns>	��Ԫ�صĽڵ�ָ��
Position LinkTree_BinSearchTree_IterationFindMax(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	while (Ptlt->Right)
	{
		Ptlt = Ptlt->Right;
	}
	return Ptlt;
}


/// <summary></summary>	������������в���ĳ��Ԫ��
/// <param name="Item"></param>	Ҫ�����Ԫ��ֵ
/// <param name="Ptlt"></param>	�ṹָ�룬ָ��������ĸ��ڵ�
/// <returns></returns>		ԭ�����������ĸ��ڵ�
BinLinkTree LinkTree_BinSearchTree_Insert(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	if (!Ptlt)	//ԭ��Ϊ��
	{
		Ptlt = (BinLinkTree)malloc(sizeof(struct LinkTreeNode));
		Ptlt->Data = Item;
		Ptlt->Left = NULL;
		Ptlt->Right = NULL;
		return Ptlt;
	}

	//������������Ϊ��
	if (Item < Ptlt->Data)
	{
		Ptlt->Left = LinkTree_BinSearchTree_Insert(Item, Ptlt->Left);
	}
	else if(Item>Ptlt->Data)
	{
		Ptlt->Right = LinkTree_BinSearchTree_Insert(Item, Ptlt->Right);
	}
	//��Item�Ѵ���,�������κβ���,Ӧ���⴫���Ŀ��ֵ
	return Ptlt;
}

/// <summary></summary>		ɾ�������������е�Ԫ�ؽڵ�
/// <param name="Item"></param>	Ҫɾ����Ԫ�ص�ֵ
/// <param name="Ptlt"></param>	�ṹָ�룬ָ��������ĸ��ڵ�
/// <returns></returns>			�ṹָ�룬ָ��ɾ����Ķ��������������ڵ�
BinLinkTree LinkTree_BinSearchTree_Delete(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	Position TempNode;

	if (!Ptlt) { return NULL; }
	if (Item < Ptlt->Data)
	{
		Ptlt->Left = LinkTree_BinSearchTree_Delete(Item, Ptlt->Left);
	}
	else if (Item > Ptlt->Data)
	{
		Ptlt->Right = LinkTree_BinSearchTree_Delete(Item, Ptlt->Right);
	}

	else if (Item == Ptlt->Data)	//�ҵ�ɾ���Ľڵ�
	{
		if (Ptlt->Left && Ptlt->Right)	//ɾ���ڵ�����Һ��Ӿ���Ϊ��
		{
			TempNode = LinkTree_BinSearchTree_RecursionFindMin(Ptlt->Right);//�ҵ�����������СԪ��
			//ת��Ϊɾ��(����ռ�)����������С�Ľڵ㣬��Ҫɾ���Ľڵ��ֵ�ı�
			Ptlt->Data = TempNode->Data;
			Ptlt->Right = LinkTree_BinSearchTree_Delete(Item, Ptlt->Right);
		}
		else      //ɾ���ڵ���һ������Ϊ��
		{
			TempNode = Ptlt;
			if (!Ptlt->Left)	//������Ϊ��
			{
				Ptlt = Ptlt->Right;
			}
			else if (!Ptlt->Right)	//������Ϊ��
			{
				Ptlt = Ptlt->Left;
			}
			//����Ϊ����ָ��NULL

			free(TempNode);
		}

		return Ptlt;
	}




}
