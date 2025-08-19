//����������������������������������������������Ϊ����棡������������������������������������������������������������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "Arraystack.h"


/// </summary>	��ջ��ʼ��
/// <param name="Ptrs"></param>
/// note: ��������������������������ջ������ʼ���������������������������������������������
void S_Arraystack_Init(S_Stack Ptrs)
{
	Ptrs->Top = -1;
}

/// </summary>	������ջ��ʼ��
/// <param name="Ptrs"></param>
/// note: ��������������������������ջ������ʼ���������������������������������������������
void D_Arraystack_Init(D_Stack Ptrs)
{
	Ptrs->Top1 = -1;
	Ptrs->Top2 = MAXSIZE2;
}

/// <summary>	����������һ���������ΪMAXSIZE1�������ջ
/// <returns></returns>	ָ�룬ָ�����ɵ������ջ
S_Stack S_ArrayStack_Creat(void)
{
	struct SingleNode CreatStack;
	S_Arraystack_Init(&CreatStack);
	S_Stack Ptrs = &CreatStack;
	return Ptrs;
}

/// <summary>	�ж�һ������ջ�Ƿ�Ϊ��
/// <param name="Ptrs"></param>	ָ�룬ָ�������ջ
/// <returns></returns>			����ջΪ���򷵻�1�����򷵻�0
int S_ArrayStack_IsEmpty(S_Stack Ptrs)
{
	if (Ptrs->Top == -1) { return 1; }
	return 0;
}


/// </summary>	��Ԫ����ջ
/// <param name="Ptrs"></param>		ָ���ջ
/// <param name="item"></param>		Ҫ��ջ��Ԫ��
void Arraystack_Push(S_Stack Ptrs,ElementType item)
{
	if ((Ptrs->Top) == MAXSIZE1 - 1)
	{
		printf("IN ERROR\n");
		return;
	}
	else
	{

		Ptrs->Data[++(Ptrs->Top)] = item;
		/*
		�ȼ���
		Ptrs->top++;
		Ptrs->Data[(Ptrs->top)] = item;
		*/
		printf("IN OK\n");
	}

}


/// </summary>	ʹջ��Ԫ�س�ջ�����س�ջ��Ԫ��
/// <param name="Ptrs"></param>	ָ��Ҫ��ջ�Ķ�ջ
/// <returns></returns>			��ջ��Ԫ��	
ElementType Arraystack_Pop(S_Stack Ptrs)
{
	ElementType Retaval;
	if (Ptrs->Top == -1)
	{
		printf("OUT ERROR\n");
		return NULL;
	}
	else
	{
		Retaval = Ptrs->Data[(Ptrs->Top)--];
	}
	printf("OUT OK\n");
	return Retaval;
}


/// </summary>		ʹĳ��Ԫ����ջ
/// <param name="Ptrs"></param>	ָ���ջ�Ľṹ��ָ��
/// <param name="item"></param>	Ҫ��ջ��Ŀ��ֵ
/// <param name="Tag"></param>	Ҫ��ջ�Ķ�ջ eg.Tag=1����Ptrs->Top1�Ķ�ջ��
/// note:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Tag��ȡ1 ,2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Arraystack_DoublePush(D_Stack Ptrs, ElementType item, int Tag)
{
	if ((Ptrs->Top2 - Ptrs->Top1) == 1)
	{
		printf("DoubleIN ERROR\n");
		return;
	}
	//�˴�����ʡ��else����Ϊ��if���������������ֱ�ӷ��أ�����ִ����һ��
	if (Tag == 1)
	{
		Ptrs->Data[++(Ptrs->Top1)] = item;
		printf("DoubleIN1 OK\n");
	}
	else
	{
		Ptrs->Data[--(Ptrs->Top2)] = item;
		printf("DoubleIN2 OK\n");
	}

}


/// </summary>		ʹջ��Ԫ�س�ջ
/// <param name="Ptrs"></param>	ָ���ջ�Ľṹ��ָ��
/// <param name="Tag"></param>	Ҫ��ջ�Ķ�ջ eg.Tag=1����Ptrs->Top1�Ķ�ջ
/// note:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Tag��ȡ1 ,2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// <returns></returns>			��ջ��Ԫ��
ElementType Arraystack_DoublePop(D_Stack Ptrs, int Tag)
{
	ElementType Retaval;
	if (Tag == 1)
	{
		if (Ptrs->Top1 == -1)
		{
			printf("DoubleOUT1 ERROR\n");
			return NULL;
		}
		else
		{
			Retaval = Ptrs->Data[(Ptrs->Top1)--];
			printf("DoubleOUT1 OK\n");
		}

	}
	else
	{
		if (Ptrs->Top2 == MAXSIZE2)
		{
			printf("DoubleOUT2 ERROR\n");
			return NULL;
		}
		else
		{
			Retaval = Ptrs->Data[(Ptrs->Top2)++];
			printf("DoubleOUT2 OK\n");
		}

	}
	return Retaval;
}





