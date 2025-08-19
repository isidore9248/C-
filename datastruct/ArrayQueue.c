//!!!!!!!!!!!!����Ϊ�������ʽʵ��ѭ������!!!!!!!!!!!!!!!!!!!!!!!!!!
//! ����ֻʹ�� MAXSIZE-1 ��λ��		#define MAXSIZE 4
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "ArrayQueue.h"

/// <summary>	��ʼ������
/// <param name="Ptrq"></param>	ָ�룬ָ����Ҫ���г�ʼ���Ķ���
void ArrayQueue_Init(ArrayQueue Ptrq)
{
	Ptrq->front = 0;
	Ptrq->rear = 0;
}

/// <summary>	��������ʼ������
/// <param name=""></param>		��
/// <returns></returns>			ָ�룬ָ�򴴽���ɵĶ���
ArrayQueue ArrayQueue_CreatQueue(void)
{
	struct ArrayQNode ArrayQNodeStruct;
	ArrayQueue Ptaq = &ArrayQNodeStruct;
	ArrayQueue_Init(Ptaq);
	return Ptaq;
}

/// <summary>	�ж�ѭ�������Ƿ�Ϊ��
/// <param name="Ptrq"></param>	ָ�룬ָ��Ҫ�����жϵĶ���
/// <returns></returns>			������Ϊ���򷵻�1�����򷵻�0
int ArrayQueue_IsEmpty(ArrayQueue Ptrq)
{
	if (Ptrq->front == Ptrq->rear) { return 1; }
	return 0;
}



/// </summary>	�ڶ�����β������Ԫ��item
/// <param name="Ptrq"></param>	�ṹ��ָ�룬ָ��Ҫ����Ķ���
/// <param name="item"></param>	Ҫ�����Ԫ��
void ArrayQueue_Add(ArrayQueue Ptrq, ElementType item)
{
	//�ж϶�����
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
	//�ж϶��п�
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




