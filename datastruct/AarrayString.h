#pragma once
#ifndef __ARRAYSTRING_H__
#define __ARRAYSTRING_H__

#define MAXSIZE		255

typedef char AStringElementType;

typedef struct ArrayString* AString;
struct ArrayString
{
	AStringElementType ch[MAXSIZE+1];
	//只使用1-256的下标的位置,ch[0]作为哨兵
	//为了满足有MAXSIZE个位置,所以这里定义MAXSIZE+1大小的数组
	int Length;

};


void ArrayString_Init(AString Ptas);
void ArrayString_CreateString(AString Ptas);
int ArrayString_BF_Index(AString MainString, AString SubString, int Pos);
int ArrayString_KMP_Index(AString MainPtas, AString SubPtas, int Pos);


#endif // !__ARRAYSTRING_H__
