#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Arraystack.h"	//数组堆栈
#include "ArrayQueue.h"	//数组队列
#include "LinkTree.h"	//链表二叉树


/// <summary>	递归法先序(根、左、右)遍历二叉树
/// <param name="Ptlt"></param>		指针，指向要遍历的二叉树
void LinkTree_Recurrence_PreOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		printf("%d\n", Ptlt->Data);
		LinkTree_Recurrence_PreOrderTraversal(Ptlt->Left);
		LinkTree_Recurrence_PreOrderTraversal(Ptlt->Right);
	}
}


/// <summary>	递归法中序(左、根、右)遍历二叉树
/// <param name="Ptlt"></param>		指针，指向要遍历的二叉树
void LinkTree_Recurrence_InOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		LinkTree_Recurrence_InOrderTraversal(Ptlt->Left);
		printf("%d\n", Ptlt->Data);
		LinkTree_Recurrence_InOrderTraversal(Ptlt->Right);
	}
}


/// <summary>	递归法后序(左、右、根)遍历二叉树
/// <param name="Ptlt"></param>		指针，指向要遍历的二叉树
void LinkTree_Recurrence_PostOrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		LinkTree_Recurrence_PostOrderTraversal(Ptlt->Left);
		LinkTree_Recurrence_PostOrderTraversal(Ptlt->Right);
		printf("%d\n", Ptlt->Data);
	}
}



/// <summary>	堆栈法(非递归)实现中序遍历二叉树
/// <param name="Ptlt"></param>		指针，指向要遍历的二叉树
void LinkTree_Stack_InOrderTraversal(BinLinkTree Ptlt)
{
	BinLinkTree LinkTree = Ptlt;	//转换要进行遍历操作的树
	S_Stack LinkTree_ArrayS_Stack = S_ArrayStack_Creat();	//创建并初始化堆栈
	while (LinkTree || !S_ArrayStack_IsEmpty(LinkTree_ArrayS_Stack))
	{
		while (LinkTree)
		{
			Arraystack_Push(LinkTree_ArrayS_Stack, LinkTree);	//将节点入栈
			LinkTree = LinkTree->Left;
		}
		if (!S_ArrayStack_IsEmpty(LinkTree_ArrayS_Stack))
		{
			LinkTree=Arraystack_Pop(LinkTree_ArrayS_Stack);		//节点出栈并赋给LinkTree
			
			/*先序遍历时将下面一行置于Arraystack_Push之前*/
			printf("%d\n", LinkTree->Data);		
			
			LinkTree = LinkTree->Right;		//转向右子树
		}

	}

}



/// <summary>	层序遍历二叉树
/// <param name="Ptlt"></param>
void LinkTree_Level_OrderTraversal(BinLinkTree Ptlt)
{
	if (Ptlt) { return; }

	ArrayQueue Queue = ArrayQueue_CreatQueue();
	BinLinkTree LinkTree = Ptlt;

	ArrayQueue_Add(Queue, LinkTree);	//先将节点入队

	while (!ArrayQueue_IsEmpty(Queue))
	{
		LinkTree = ArrayQueue_Delete(Queue);
		printf("%d\n", LinkTree->Data);
		if(LinkTree->Left){ ArrayQueue_Add(Queue, LinkTree->Left); }
		if(LinkTree->Right){ ArrayQueue_Add(Queue, LinkTree->Right); }
	}

}

//先序算法创建二叉树
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
struct BiNode *child,*rchild;//左右孩子指针
}BiNode,*BiTree;
*/




/// <summary>	输出二叉树中所有叶子节点(没有子节点的节点)，由递归算法的先序遍历实现
/// <param name="Ptlt"></param>	指针，指向二叉树
void LinkTree_GetLeafNode(BinLinkTree Ptlt)
{
	if (Ptlt)
	{
		if (!Ptlt->Left && !Ptlt->Right) { printf("%d\n", Ptlt->Data); }
		LinkTree_GetLeafNode(Ptlt->Left);
		LinkTree_GetLeafNode(Ptlt->Right);

	}

}


/// <summary>	计算并返回二叉树的高度，由递归算法的后序遍历实现
/// <param name="Ptlt"></param>	指针，指向二叉树
///	思路： MaxHeight=Max(LeftHeight,RightHeight)+1
int LinkTree_GetHeight(BinLinkTree Ptlt)
{
	int LeftHeight = 0, RightHeight = 0, MaxHeight = 0;
	if (Ptlt)
	{
		LeftHeight= LinkTree_GetHeight(Ptlt->Left);		//求左子树深度
		RightHeight= LinkTree_GetHeight(Ptlt->Right);	//求右子树深度
		
		////MaxHeight=Max(LeftHeight,RightHeight)+1
		MaxHeight = (LeftHeight > RightHeight) ? LeftHeight : RightHeight;	
		return (MaxHeight + 1);
	}
	return 0;	//空树深度为0

}


/// <summary>	递归法寻找二叉搜索树的元素
/// <param name="Item"></param>	要查找的元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
/// <note>	typedef BinLinkTree	Position;	//用于二叉搜索树
Position LinkTree_BinSearchTree_RecursionFind(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	if (!Ptlt)	{return NULL;}	//树为空进if
	
	//以下为非空
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


/// <summary>	非递归(迭代法)寻找二叉搜索树的元素
/// <param name="Item"></param>	要查找的元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
/// <note>	typedef BinLinkTree	Position;	//用于二叉搜索树
Position LinkTree_BinSearchTree_IterationFind(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	while (Ptlt)	//树非空时进循环
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
	return NULL;	//树为空直接退出
}

/// <summary>	递归法查找最小元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
Position LinkTree_BinSearchTree_RecursionFindMin(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }		//树为空
	
	if (!Ptlt->Left) { return Ptlt; }	//左子树为空
	return LinkTree_BinSearchTree_RecursionFindMin(Ptlt->Left); 	
}

/// <summary>	非递归(迭代法)查找最小元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
Position LinkTree_BinSearchTree_IterationFindMin(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	while (Ptlt->Left)	//左子树不为空
	{
		Ptlt = Ptlt->Left;
	}
	return Ptlt;
}

/// <summary>	递归法查找最大元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
Position LinkTree_BinSearchTree_RecursionFindMax(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	if (Ptlt->Right)
	{
		return LinkTree_BinSearchTree_RecursionFindMax(Ptlt->Right);
	}
	return Ptlt;	//	Ptlt->Right==NULL;
}

/// <summary>	非递归(迭代法)查找最大元素
/// <param name="Ptlt"></param>	指针，指向二叉搜索树的树根
/// <returns></returns>	该元素的节点指针
Position LinkTree_BinSearchTree_IterationFindMax(BinLinkTree Ptlt)
{
	if (!Ptlt) { return NULL; }

	while (Ptlt->Right)
	{
		Ptlt = Ptlt->Right;
	}
	return Ptlt;
}


/// <summary></summary>	向二叉搜索树中插入某个元素
/// <param name="Item"></param>	要插入的元素值
/// <param name="Ptlt"></param>	结构指针，指向二叉树的根节点
/// <returns></returns>		原二叉搜索树的根节点
BinLinkTree LinkTree_BinSearchTree_Insert(LinkTree_ElementType Item, BinLinkTree Ptlt)
{
	if (!Ptlt)	//原树为空
	{
		Ptlt = (BinLinkTree)malloc(sizeof(struct LinkTreeNode));
		Ptlt->Data = Item;
		Ptlt->Left = NULL;
		Ptlt->Right = NULL;
		return Ptlt;
	}

	//二叉搜索树不为空
	if (Item < Ptlt->Data)
	{
		Ptlt->Left = LinkTree_BinSearchTree_Insert(Item, Ptlt->Left);
	}
	else if(Item>Ptlt->Data)
	{
		Ptlt->Right = LinkTree_BinSearchTree_Insert(Item, Ptlt->Right);
	}
	//若Item已存在,不进行任何操作,应避免传入此目标值
	return Ptlt;
}

/// <summary></summary>		删除二叉搜索树中的元素节点
/// <param name="Item"></param>	要删除的元素的值
/// <param name="Ptlt"></param>	结构指针，指向二叉树的根节点
/// <returns></returns>			结构指针，指向删除后的二叉树搜索树根节点
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

	else if (Item == Ptlt->Data)	//找到删除的节点
	{
		if (Ptlt->Left && Ptlt->Right)	//删除节点的左右孩子均不为空
		{
			TempNode = LinkTree_BinSearchTree_RecursionFindMin(Ptlt->Right);//找到右子树中最小元素
			//转化为删除(清除空间)右子树中最小的节点，将要删除的节点的值改变
			Ptlt->Data = TempNode->Data;
			Ptlt->Right = LinkTree_BinSearchTree_Delete(Item, Ptlt->Right);
		}
		else      //删除节点有一个孩子为空
		{
			TempNode = Ptlt;
			if (!Ptlt->Left)	//左子树为空
			{
				Ptlt = Ptlt->Right;
			}
			else if (!Ptlt->Right)	//右子树为空
			{
				Ptlt = Ptlt->Left;
			}
			//若均为空则指向NULL

			free(TempNode);
		}

		return Ptlt;
	}




}
