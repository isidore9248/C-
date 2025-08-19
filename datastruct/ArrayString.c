/*************数组串从下标为1的数组地址开始存放,下标为0的数组单元作为哨兵******************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "AarrayString.h"	//数组串


/// <summary>	数组串的初始化
/// <param name="ArrayString"></param>	指针，指向要初始化的字符串
void ArrayString_Init(AString Ptas)
{
	for (int i = 0; i <= MAXSIZE; i++)
	{
		Ptas->ch[i] = '\0';
	}
	Ptas->Length = 0;
}


/// <summary>	生成一个与输入内容相同的串
/// <note>		从下标为1的地方开始存放
/// <param name="Ptas"></param>	结构体指针，指向需要赋给的结构体串
void ArrayString_CreateString(AString Ptas)
{
	char TestString[MAXSIZE + 1];
	gets(TestString);

	int Ptas_Count = 1;
	int TestS_Count = 0;
	int TestLen = strlen(TestString);
	Ptas->Length = TestLen;
	for (Ptas_Count = 1; Ptas_Count <= TestLen; Ptas_Count++)
	{
		(Ptas->ch[Ptas_Count]) = TestString[TestS_Count];
		TestS_Count++;
	}
}


/// <summary>	用BF法查看并返回子串在主串中的位置
/// <param name="MainPtas"></param>	指针，指向主串
/// <param name="SubPtas"></param>	指针，指向子串
/// <param name="Pos"></param>		要从主串的第几个字符开始比较
/// <returns></returns>				子串在主串的第一个字符的位置，若不存在则返回0
int ArrayString_BF_Index(AString MainPtas, AString SubPtas,int Pos)
{
	int MainString_Count = Pos;
	int SubString_Count = 1;

	while (MainString_Count<= MainPtas->Length && SubString_Count<= SubPtas->Length)
	{
		if (MainPtas->ch[MainString_Count] == SubPtas->ch[SubString_Count])
		{
			MainString_Count++;
			SubString_Count++;
		}
		else
		{
			MainString_Count = MainString_Count - SubString_Count + 2;
			SubString_Count = 1;
		}

	}
	if (SubString_Count > SubPtas->Length)
	{
		return MainString_Count - SubPtas->Length;
	}
	return 0;

}

int next[MAXSIZE];

void ArrayString_GetNext(AString Ptas)
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < Ptas->Length)
	{
		if (j == 0 || Ptas->ch[i] == Ptas->ch[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}

	}

}

int nextval[MAXSIZE];

void ArrayString_GetNextval(AString Ptas)
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < Ptas->Length)
	{
		if (j == 0 || Ptas->ch[i] == Ptas->ch[j])
		{
			++i;
			++j;
			
			if (Ptas->ch[i] != Ptas->ch[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}

	}


}

int ArrayString_KMP_Index(AString MainPtas, AString SubPtas, int Pos)
{
	int MainString_Count = Pos;
	int SubString_Count = 1;
	while (MainString_Count <= MainPtas->Length && SubString_Count <= SubPtas->Length)
	{
		if (SubString_Count == 0 || MainPtas->ch[MainString_Count] == SubPtas->ch[SubString_Count])
		{
			MainString_Count++;
			SubString_Count++;
		}
		else
		{
			SubString_Count = next[SubString_Count];

		}

	}
	
	if (SubString_Count > SubPtas->Length)
	{
		return MainString_Count - SubPtas->Length;
	}
	return 0;
}
