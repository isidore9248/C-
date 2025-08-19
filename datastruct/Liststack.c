//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!����Ϊ������ʽ��ʾ��ջ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! ������Ϊ����ָ���ң��� S->��->��->��->��->��->
//! ���Ϊ��ջ�Ķ��ˣ�����ջ�ĵ�ַ��ʼλ�ã�Ptrs�� Top������SΪ�սṹ�壬ֻ�Ǵ���һ��ָ����һ���ڵ��ָ��
//! �κβ�����ɾ���������Ƕ� S ָ��ĵ�Ԫ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "Liststack.h"


/// </summary>	������ջ��ͷ�ڵ�
/// <returns></returns>	���ؽṹ��ָ�룬ָ�����Ľڵ�
Stack Liststack_CreatStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct sNode));
	return S;
}


/// </summary>	�ڵ��ʼ��
/// <param name="Ptrs"></param>	Ҫ��ʼ���Ľڵ�
void Liststack_Init(Stack Ptrs)
{
	Ptrs->Data = 0;
	Ptrs->Next = NULL;
}



/// </summary>	�ж϶�ջ�Ƿ�Ϊ��
/// <param name="S"></param>	ָ��Ҫ�����жϵ�ָ��
/// <returns></returns>			����ջΪ���򷵻�1�����򷵻�0
int Liststack_IsEmpty(Stack S)
{
	return (S->Next == NULL);
	/*
	�ȼ���
	if (S->Next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/

}


/// </summary>	��Ԫ��itemѹ���ջ
/// <param name="Ptrs"></param>		�ṹ��ָ�룬ָ��Ҫѹ��Ķ�ջ
/// <param name="item"></param>		Ҫѹ���Ԫ��
void Liststack_Push(Stack Ptrs, ElementType item)
{
	Stack TempCell;
	Liststack_Init(&TempCell);
	TempCell = Liststack_CreatStack();
	TempCell->Data = item;
	TempCell->Next = Ptrs->Next;
	Ptrs->Next = TempCell;

}


/// </summary>	ɾ��������ջ��Ԫ��
/// <param name="Ptrs"></param>		Ҫɾ��ջ���Ķ�ջ
/// <returns></returns>				ɾ����Ԫ��
ElementType Liststack_Pop(Stack Ptrs)
{
	ElementType Retaval;
	if (Liststack_IsEmpty(Ptrs) == 1)
	{
		return NULL;
	}
	else
	{
		/*�ҵ�ջ���Ľڵ�*/
		//ʹ�Լ������Ľڵ����ջ���Ľڵ㣨ͨ����ַ�����޸ģ�
		Stack TempCell;
		Liststack_Init(&TempCell);
		Ptrs->Next = TempCell;
		TempCell->Next = Ptrs->Next;
		Retaval = TempCell->Data;
		free(TempCell);
		return Retaval;
	}

}

