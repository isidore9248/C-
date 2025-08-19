#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "LinkList.h"



/// <summary></summary>					将单链表每隔ReverseNum个元素翻转一次，返回指向头节点的指针
/// <param name="Head"></param>			原链表的头指针
/// <param name="ReverseNum"></param>	每隔ReverseNum个单元节点翻转
/// <returns></returns>					反转后的链表的头指针
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