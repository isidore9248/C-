//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!以下为链表形式表示堆栈!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//! 链表方向为从左指向右，即 S->□->□->□->□->□->
//! 左侧为堆栈的顶端，即堆栈的地址起始位置（Ptrs） Top，其中S为空结构体，只是存在一个指向下一个节点的指针
//! 任何插入与删除操作均是对 S 指向的单元进行
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "Liststack.h"


/// </summary>	建立堆栈的头节点
/// <returns></returns>	返回结构体指针，指向建立的节点
Stack Liststack_CreatStack(void)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct sNode));
	return S;
}


/// </summary>	节点初始化
/// <param name="Ptrs"></param>	要初始化的节点
void Liststack_Init(Stack Ptrs)
{
	Ptrs->Data = 0;
	Ptrs->Next = NULL;
}



/// </summary>	判断堆栈是否为空
/// <param name="S"></param>	指向要进行判断的指针
/// <returns></returns>			若堆栈为空则返回1，否则返回0
int Liststack_IsEmpty(Stack S)
{
	return (S->Next == NULL);
	/*
	等价于
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


/// </summary>	将元素item压入堆栈
/// <param name="Ptrs"></param>		结构体指针，指向要压入的堆栈
/// <param name="item"></param>		要压入的元素
void Liststack_Push(Stack Ptrs, ElementType item)
{
	Stack TempCell;
	Liststack_Init(&TempCell);
	TempCell = Liststack_CreatStack();
	TempCell->Data = item;
	TempCell->Next = Ptrs->Next;
	Ptrs->Next = TempCell;

}


/// </summary>	删除并返回栈顶元素
/// <param name="Ptrs"></param>		要删除栈顶的堆栈
/// <returns></returns>				删除的元素
ElementType Liststack_Pop(Stack Ptrs)
{
	ElementType Retaval;
	if (Liststack_IsEmpty(Ptrs) == 1)
	{
		return NULL;
	}
	else
	{
		/*找到栈顶的节点*/
		//使自己建立的节点等于栈顶的节点（通过地址进行修改）
		Stack TempCell;
		Liststack_Init(&TempCell);
		Ptrs->Next = TempCell;
		TempCell->Next = Ptrs->Next;
		Retaval = TempCell->Data;
		free(TempCell);
		return Retaval;
	}

}

