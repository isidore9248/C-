#pragma once
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#define MAXSIZE 4

typedef int ElementType;

/// front->□->□->□->□(rear)-> 
/// 删除操作从front端进行，添加操作从rear端进行


/// </summary>	链式结构的节点
struct Node
{
	ElementType Data;
	struct Node* Next;
};


typedef struct LinkQNode* LinkQueue;
/// </summary>	指向链式结构的头和尾指针结构
struct LinkQNode
{
	struct Node* front;
	struct Node* rear;
};
LinkQueue Ptrq;//指向头和尾指针结构的指针

struct Node* LinkQueue_Creat(void);
ElementType LinkQueue_Delete(LinkQueue Ptrq);
void LinkQueue_Add(LinkQueue Ptrq, ElementType item);

#endif // !__LINKQUEUE_H__
