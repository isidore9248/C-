/*
此文件为用数组的形式保存树状集合，其中根节点的Parent=-1
Parent为父节点的在数组中的下标
*/

#pragma once
#ifndef __ARRAYSETTYPE_H__
#define	__ARRAYSETTYPE_H__

#define ArraySetType_MAXSIZE	10	//此为数组的最大长度


typedef int ArraySetType_ElementType;

typedef struct ArraySetType SetType;
struct ArraySetType
{
	ArraySetType_ElementType Data;
	int Parent;
};


int ArraySetType_Find(SetType S[], ArraySetType_ElementType Item);
void ArraySetType_Union(SetType S[], ArraySetType_ElementType ItemOne, ArraySetType_ElementType ItemTwo);






#endif // !__ARRAYSETTYPE_H__
