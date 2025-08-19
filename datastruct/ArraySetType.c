#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "ArraySetType.h"


/// <summary> </summary>		�ڼ����в���Ԫ�ز����ظ�Ԫ�����ڼ��ϵĸ��ڵ��±�
/// <param name="S"></param>	��ż��ϵ�����
/// <param name="Item"></param>	��Ҫ���ҵ�Ŀ��
/// <returns></returns>			��Ԫ�����ڼ��ϵĸ��ڵ��±꣬��δ�ҵ��򷵻�-1
int ArraySetType_Find(SetType S[], ArraySetType_ElementType Item)
{ 
	int i = 0;
	for ( i = 0; i < ArraySetType_MAXSIZE && S[i].Data != Item; i++);	//���ҵ���Ԫ��֮ǰ�����κβ������ҵ����˳�ѭ��
	if (i >= ArraySetType_MAXSIZE) { return -1; }	//δ�ҵ�������-1
	
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i;	//�ҵ���Ԫ���򷵻ظ�Ԫ�����ڼ��ϵĸ��ڵ��±�
}


/// <summary></summary>				������Ԫ�����ڼ��Ͻ��в�������
/// <param name="S"></param>		��ż��ϵ�����
/// <param name="ItemOne"></param>	�����д��ڵ�Ԫ��1
/// <param name="ItemTwo"></param>	�����д��ڵ�Ԫ��2
void ArraySetType_Union(SetType S[], ArraySetType_ElementType ItemOne, ArraySetType_ElementType ItemTwo)
{
	int Root1, Root2;
	Root1 = ArraySetType_Find(S, ItemOne);
	Root2 = ArraySetType_Find(S, ItemTwo);
	if (Root1 != Root2) { S[Root2].Parent = Root1; }	//������2�ĸ��ڵ���ڼ���1�£���Ϊ����1���ڵ���ӽڵ�
}


