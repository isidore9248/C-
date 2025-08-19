#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "LinkList.h"



/// <summary></summary>					��������ÿ��ReverseNum��Ԫ�ط�תһ�Σ�����ָ��ͷ�ڵ��ָ��
/// <param name="Head"></param>			ԭ�����ͷָ��
/// <param name="ReverseNum"></param>	ÿ��ReverseNum����Ԫ�ڵ㷭ת
/// <returns></returns>					��ת��������ͷָ��
LinkList_Ptr LinkListReverse(LinkList_Ptr Head, int ReverseNum)
{
	int count = 1;
	LinkList_Ptr New = Head->Next;
	LinkList_Ptr Old = New->Next;
	LinkList_Ptr Temp = Old->Next;
	while (count < ReverseNum)
	{
		Temp = Old->Next;
		Old->Next = New;
		New = Old;
		Old = Temp;
		count++;
	}
	Head->Next->Next = Old;
	return New;
}