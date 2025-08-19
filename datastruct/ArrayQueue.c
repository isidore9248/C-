//!!!!!!!!!!!!以下为数组的形式实现循环队列!!!!!!!!!!!!!!!!!!!!!!!!!!
//! 如下只使用 MAXSIZE-1 个位置		#define MAXSIZE 4
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "ArrayQueue.h"

/// <summary>	初始化队列
/// <param name="Ptrq"></param>	指针，指向需要进行初始化的队列
void ArrayQueue_Init(ArrayQueue Ptrq)
{
	Ptrq->front = 0;
	Ptrq->rear = 0;
}

/// <summary>	创建并初始化队列
/// <param name=""></param>		无
/// <returns></returns>			指针，指向创建完成的队列
ArrayQueue ArrayQueue_CreatQueue(void)
{
	struct ArrayQNode ArrayQNodeStruct;
	ArrayQueue Ptaq = &ArrayQNodeStruct;
	ArrayQueue_Init(Ptaq);
	return Ptaq;
}

/// <summary>	判断循环队列是否为空
/// <param name="Ptrq"></param>	指针，指向要进行判断的队列
/// <returns></returns>			若队列为空则返回1，否则返回0
int ArrayQueue_IsEmpty(ArrayQueue Ptrq)
{
	if (Ptrq->front == Ptrq->rear) { return 1; }
	return 0;
}



/// </summary>	在队列中尾部插入元素item
/// <param name="Ptrq"></param>	结构体指针，指向要插入的队列
/// <param name="item"></param>	要插入的元素
void ArrayQueue_Add(ArrayQueue Ptrq, ElementType item)
{
	//判断队列满
	if ((Ptrq->rear + 1) % MAXSIZE == Ptrq->front)
	{
		printf("Add ERROR\n");
		return NULL;
	}
	else
	{
		Ptrq->rear = (Ptrq->rear + 1) % MAXSIZE;
		Ptrq->Data[Ptrq->rear] = item;
		printf("Add OK\n");
	}

}


ElementType ArrayQueue_Delete(ArrayQueue Ptrq)
{
	ElementType Retaval;
	//判断队列空
	if (Ptrq->rear == Ptrq->front)
	{
		printf("Delete ERROR\n");
		return NULL;
	}

	Retaval = Ptrq->front;
	Ptrq->front = (Ptrq->front + 1) % MAXSIZE;
	printf("Delete OK\n");
	return Retaval;
}




