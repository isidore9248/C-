#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Search.h"			//查找


void Search_StructInit(Search Ptss)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		Ptss->Element[i] = 0;
	}
	Ptss->Length = MAXSIZE;
}


/// <summary>	顺序查找表中某个元素的位置，并返回其下标
/// <param name="Ptss"></param>	指针，指向要查找的结构体
/// <param name="Item"></param>	目标元素
/// <returns></returns>			返回结果的下标，若不存在，则返回0
int Search_SequentialSearch(Search Ptss, Search_ElementType Item)
{
	int SearchCount= Ptss->Length;//倒序查找
	Ptss->Element[0] = Item;//建立哨兵
	for (SearchCount = Ptss->Length; Ptss->Element[SearchCount] != Item; SearchCount--);
	return SearchCount;
}


/// <summary>	用二分法查找表中某个元素的位置，并返回其下标
/// <param name="Ptss"></param>	指针，指向要查找的结构体
/// <param name="Item"></param>	目标元素
/// <returns></returns>			返回结果的下标，若不存在，则返回-1
int Search_BinarySearch(Search Ptss, Search_ElementType Item)
{
	int LeftCount, RightCount, MidCount, NotFound = -1;
	
	LeftCount = 1;
	RightCount = Ptss->Length;
	while (LeftCount < RightCount)
	{
		MidCount = (LeftCount + RightCount) / 2;
		if (Ptss->Element[MidCount] < Item) { LeftCount = MidCount + 1; }
		else if (Ptss->Element[MidCount] > Item) { RightCount = MidCount - 1; }
		else { return MidCount; }

	}
	return NotFound;
}
