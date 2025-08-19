//!!!!!!!!!!!!以下为链表的形式实现循环队列!!!!!!!!!!!!!!!!!!!!!!!!!!
//! 如下只使用 MAXSIZE-1 个位置
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include "LinkQueue.h"

struct Node* LinkQueue_Creat(void)
{
	struct Node* S;
	S = (struct Node*)malloc(sizeof(struct Node));
	return S;
}

ElementType LinkQueue_Delete(LinkQueue Ptrq)
{
	if (Ptrq->front == NULL)
	{
		printf("Delete ERROR\n");
		return NULL;
	}
	struct Node* FrontCell = Ptrq->front;
	ElementType Retaval;
	if (Ptrq->front == Ptrq->rear)
	{
		Ptrq->front = NULL;
		Ptrq->rear = NULL;
	}
	else
	{
		Ptrq->front = Ptrq->front->Next;
	}
	Retaval = FrontCell->Data;
	printf("Delete OK\n");
	free(FrontCell);
	return Retaval;

}

void LinkQueue_Add(LinkQueue Ptrq, ElementType item)
{
	struct Node* S = LinkQueue_Creat();
	if (!S) { return; }
	S->Data = item;
	S->Next = NULL;

	Ptrq->rear->Next = S;//将新创建的S节点连接至原本的队列末尾
	Ptrq->rear = S;//修改原来的队列末尾

}
