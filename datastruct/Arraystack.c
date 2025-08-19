//！！！！！！！！！！！！！！！！！！！！！以下为数组版！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "Arraystack.h"


/// </summary>	堆栈初始化
/// <param name="Ptrs"></param>
/// note: ！！！！！！！！！！创建堆栈后必须初始化，否则程序会崩溃！！！！！！！！！！！！！！！
void S_Arraystack_Init(S_Stack Ptrs)
{
	Ptrs->Top = -1;
}

/// </summary>	两个堆栈初始化
/// <param name="Ptrs"></param>
/// note: ！！！！！！！！！！创建堆栈后必须初始化，否则程序会崩溃！！！！！！！！！！！！！！！
void D_Arraystack_Init(D_Stack Ptrs)
{
	Ptrs->Top1 = -1;
	Ptrs->Top2 = MAXSIZE2;
}

/// <summary>	创建并返回一个最大容量为MAXSIZE1的数组堆栈
/// <returns></returns>	指针，指向生成的数组堆栈
S_Stack S_ArrayStack_Creat(void)
{
	struct SingleNode CreatStack;
	S_Arraystack_Init(&CreatStack);
	S_Stack Ptrs = &CreatStack;
	return Ptrs;
}

/// <summary>	判断一个单堆栈是否为空
/// <param name="Ptrs"></param>	指针，指向数组堆栈
/// <returns></returns>			若堆栈为空则返回1，否则返回0
int S_ArrayStack_IsEmpty(S_Stack Ptrs)
{
	if (Ptrs->Top == -1) { return 1; }
	return 0;
}


/// </summary>	将元素入栈
/// <param name="Ptrs"></param>		指向堆栈
/// <param name="item"></param>		要入栈的元素
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
		等价于
		Ptrs->top++;
		Ptrs->Data[(Ptrs->top)] = item;
		*/
		printf("IN OK\n");
	}

}


/// </summary>	使栈顶元素出栈并返回出栈的元素
/// <param name="Ptrs"></param>	指向要出栈的堆栈
/// <returns></returns>			出栈的元素	
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


/// </summary>		使某个元素入栈
/// <param name="Ptrs"></param>	指向堆栈的结构体指针
/// <param name="item"></param>	要入栈的目标值
/// <param name="Tag"></param>	要入栈的堆栈 eg.Tag=1则入Ptrs->Top1的堆栈，
/// note:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Tag可取1 ,2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Arraystack_DoublePush(D_Stack Ptrs, ElementType item, int Tag)
{
	if ((Ptrs->Top2 - Ptrs->Top1) == 1)
	{
		printf("DoubleIN ERROR\n");
		return;
	}
	//此处可以省略else，因为在if处如果不符合条件直接返回，不会执行下一步
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


/// </summary>		使栈顶元素出栈
/// <param name="Ptrs"></param>	指向堆栈的结构体指针
/// <param name="Tag"></param>	要入栈的堆栈 eg.Tag=1则入Ptrs->Top1的堆栈
/// note:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Tag可取1 ,2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// <returns></returns>			出栈的元素
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





