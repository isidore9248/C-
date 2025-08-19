#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "ArraySetType.h"


/// <summary> </summary>		在集合中查找元素并返回该元素所在集合的根节点下标
/// <param name="S"></param>	存放集合的数组
/// <param name="Item"></param>	需要查找的目标
/// <returns></returns>			该元素所在集合的根节点下标，若未找到则返回-1
int ArraySetType_Find(SetType S[], ArraySetType_ElementType Item)
{ 
	int i = 0;
	for ( i = 0; i < ArraySetType_MAXSIZE && S[i].Data != Item; i++);	//在找到该元素之前不做任何操作，找到后退出循环
	if (i >= ArraySetType_MAXSIZE) { return -1; }	//未找到，返回-1
	
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;	//找到该元素则返回该元素所在集合的根节点下标
}


/// <summary></summary>				将两个元素所在集合进行并集运算
/// <param name="S"></param>		存放集合的数组
/// <param name="ItemOne"></param>	集合中存在的元素1
/// <param name="ItemTwo"></param>	集合中存在的元素2
void ArraySetType_Union(SetType S[], ArraySetType_ElementType ItemOne, ArraySetType_ElementType ItemTwo)
{
	int Root1, Root2;
	Root1 = ArraySetType_Find(S, ItemOne);
	Root2 = ArraySetType_Find(S, ItemTwo);
	if (Root1 != Root2) { S[Root2].Parent = Root1; }	//将集合2的根节点接在集合1下，作为集合1根节点的子节点
}


