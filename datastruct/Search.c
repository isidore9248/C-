#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Search.h"			//����


void Search_StructInit(Search Ptss)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		Ptss->Element[i] = 0;
	}
	Ptss->Length = MAXSIZE;
}


/// <summary>	˳����ұ���ĳ��Ԫ�ص�λ�ã����������±�
/// <param name="Ptss"></param>	ָ�룬ָ��Ҫ���ҵĽṹ��
/// <param name="Item"></param>	Ŀ��Ԫ��
/// <returns></returns>			���ؽ�����±꣬�������ڣ��򷵻�0
int Search_SequentialSearch(Search Ptss, Search_ElementType Item)
{
	int SearchCount= Ptss->Length;//�������
	Ptss->Element[0] = Item;//�����ڱ�
	for (SearchCount = Ptss->Length; Ptss->Element[SearchCount] != Item; SearchCount--);
	return SearchCount;
}


/// <summary>	�ö��ַ����ұ���ĳ��Ԫ�ص�λ�ã����������±�
/// <param name="Ptss"></param>	ָ�룬ָ��Ҫ���ҵĽṹ��
/// <param name="Item"></param>	Ŀ��Ԫ��
/// <returns></returns>			���ؽ�����±꣬�������ڣ��򷵻�-1
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
