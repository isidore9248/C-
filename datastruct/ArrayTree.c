#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "LinkTree.h"	//链表二叉树
#include "ArrayTree.h"	//静态链表二叉树


/// <summary>	结构数组初始化
/// <param name="T"></param>	需要初始化的结构数组
/// <param name="ArrayNumber"></param>	数组的大小
void ArrayTree_BinTreeNode_ArrayInit(struct ArrayTree_BinTreeNode T[],int ArrayNumber)
{
	for (int i = 0; i < ArrayNumber; i++)
	{
		T[i].Element = '\0';
		T[i].Left = -1;
		T[i].Right = -1;
	}
}


/// <summary>	建立二叉树并返回根节点的位置下标
/// <param name="T"></param>	用结构数组表示的二叉树
/// <param name="BinTreeNode_Number"></param>	结构数组的大小(不是角标)
/// <returns></returns>		二叉树根节点的位置下标
int ArrayTree_BuildTree(struct ArrayTree_BinTreeNode T[], int BinTreeNode_Number)
{
	int Root = -1;//为根的下标，若为-1则为空树
	//int BinTreeNode_Number = 0;	//要求第一次输入为树的节点个数
	//scanf("%d", &BinTreeNode_Number);
	if (BinTreeNode_Number)
	{
		//申请数组Check[BinTreeNode_Number]
		int* Check = (int*)malloc(sizeof(int) * BinTreeNode_Number);
		for (int i = 0; i < BinTreeNode_Number; i++)
		{
			Check[i] = 0;
		}
		ArrayTree_ElementType CharLeft, CharRight;
		printf("输入格式为： 字符(空格)字符(空格)字符(回车)\n");
		printf("其分别对应：节点内容、左儿子下标、右儿子下标(输入 # 代表空节点)\n");
		for (int i = 0; i < BinTreeNode_Number; i++)
		{
			
			//printf("\n");
			scanf("%c %c %c", &T[i].Element, &CharLeft, &CharRight);
			/*对左儿子处理*/
			if (CharLeft != '#')
			{
				T[i].Left = CharLeft - '0';
				Check[T[i].Left] = 1;
			}
			else { Check[T[i].Left] = Null; }		//#define	Null	-1
			/*对右儿子处理*/
			if (CharRight != '#')
			{
				T[i].Right = CharRight - '0';
				Check[T[i].Right] = 1;
			}
			else { Check[T[i].Right] = Null; }
		}
		/*寻找根节点并赋给Root*/
		int i = 0;
		for (i = 0; i < BinTreeNode_Number; i++)
		{
			if (!Check[i])
			{
				break;
			}
		}
		Root = i;
		//free(Check);
	}
	return Root;
}








