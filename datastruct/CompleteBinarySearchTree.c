#include <stdio.h>
#include <stdlib.h>	
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "CompleteBinarySearchTree.h"//完全二叉搜索树


/*
*调用格式 
qsort(&Array, 10, sizeof(int), Compare);
*/
int Compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}





/// <summary>存在一个已经排序(从小到大)好的数组Array[]
/// </summary>需要将其整理为完全二叉搜索树并存在一个新的数组Tree[]中
/// <param name="ArrayLeft"></param>	Array[]中数据开始存储的下标
/// <param name="ArrayRight"></param>	Array[]中数据结束存储的下标
/// <param name="TRoot"></param>		整理好的完全二叉搜索树数组根节点存放的下标
void Solve(int ArrayLeft, int ArrayRight, int TRoot)
{



}
