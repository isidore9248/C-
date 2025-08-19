#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "LinkTree.h"	//���������
#include "ArrayTree.h"	//��̬���������


/// <summary>	�ṹ�����ʼ��
/// <param name="T"></param>	��Ҫ��ʼ���Ľṹ����
/// <param name="ArrayNumber"></param>	����Ĵ�С
void ArrayTree_BinTreeNode_ArrayInit(struct ArrayTree_BinTreeNode T[],int ArrayNumber)
{
	for (int i = 0; i < ArrayNumber; i++)
	{
		T[i].Element = '\0';
		T[i].Left = -1;
		T[i].Right = -1;
	}
}


/// <summary>	���������������ظ��ڵ��λ���±�
/// <param name="T"></param>	�ýṹ�����ʾ�Ķ�����
/// <param name="BinTreeNode_Number"></param>	�ṹ����Ĵ�С(���ǽǱ�)
/// <returns></returns>		���������ڵ��λ���±�
int ArrayTree_BuildTree(struct ArrayTree_BinTreeNode T[], int BinTreeNode_Number)
{
	int Root = -1;//Ϊ�����±꣬��Ϊ-1��Ϊ����
	//int BinTreeNode_Number = 0;	//Ҫ���һ������Ϊ���Ľڵ����
	//scanf("%d", &BinTreeNode_Number);
	if (BinTreeNode_Number)
	{
		//��������Check[BinTreeNode_Number]
		int* Check = (int*)malloc(sizeof(int) * BinTreeNode_Number);
		for (int i = 0; i < BinTreeNode_Number; i++)
		{
			Check[i] = 0;
		}
		ArrayTree_ElementType CharLeft, CharRight;
		printf("�����ʽΪ�� �ַ�(�ո�)�ַ�(�ո�)�ַ�(�س�)\n");
		printf("��ֱ��Ӧ���ڵ����ݡ�������±ꡢ�Ҷ����±�(���� # ����սڵ�)\n");
		for (int i = 0; i < BinTreeNode_Number; i++)
		{
			
			//printf("\n");
			scanf("%c %c %c", &T[i].Element, &CharLeft, &CharRight);
			/*������Ӵ���*/
			if (CharLeft != '#')
			{
				T[i].Left = CharLeft - '0';
				Check[T[i].Left] = 1;
			}
			else { Check[T[i].Left] = Null; }		//#define	Null	-1
			/*���Ҷ��Ӵ���*/
			if (CharRight != '#')
			{
				T[i].Right = CharRight - '0';
				Check[T[i].Right] = 1;
			}
			else { Check[T[i].Right] = Null; }
		}
		/*Ѱ�Ҹ��ڵ㲢����Root*/
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








