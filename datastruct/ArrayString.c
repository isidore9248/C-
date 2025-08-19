/*************���鴮���±�Ϊ1�������ַ��ʼ���,�±�Ϊ0�����鵥Ԫ��Ϊ�ڱ�******************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "AarrayString.h"	//���鴮


/// <summary>	���鴮�ĳ�ʼ��
/// <param name="ArrayString"></param>	ָ�룬ָ��Ҫ��ʼ�����ַ���
void ArrayString_Init(AString Ptas)
{
	for (int i = 0; i <= MAXSIZE; i++)
	{
		Ptas->ch[i] = '\0';
	}
	Ptas->Length = 0;
}


/// <summary>	����һ��������������ͬ�Ĵ�
/// <note>		���±�Ϊ1�ĵط���ʼ���
/// <param name="Ptas"></param>	�ṹ��ָ�룬ָ����Ҫ�����Ľṹ�崮
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


/// <summary>	��BF���鿴�������Ӵ��������е�λ��
/// <param name="MainPtas"></param>	ָ�룬ָ������
/// <param name="SubPtas"></param>	ָ�룬ָ���Ӵ�
/// <param name="Pos"></param>		Ҫ�������ĵڼ����ַ���ʼ�Ƚ�
/// <returns></returns>				�Ӵ��������ĵ�һ���ַ���λ�ã����������򷵻�0
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
