#pragma once
#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#define MAXSIZE 255
typedef int ElementType;
typedef struct ArrayQNode* ArrayQueue;
/// </summary>以下为用结构体实现循环队列，
/// front	为队列头的位置（对应数组的角标）
/// rear	为队列尾的位置（对应数组的角标）
/// 左侧为front，右侧为rear		即，front<rear
/// front-□-□-□-□-rear 
/// 删除操作从front端进行，添加操作从rear端进行
struct ArrayQNode
{
	ElementType Data[MAXSIZE];
	int rear;
	int front;
};


void ArrayQueue_Init(ArrayQueue Ptrq);
ArrayQueue ArrayQueue_CreatQueue(void);
int ArrayQueue_IsEmpty(ArrayQueue Ptrq);
void ArrayQueue_Add(ArrayQueue Ptrq, ElementType item);
ElementType ArrayQueue_Delete(ArrayQueue Ptrq);

#endif // !__ARRAYQUEUE_H__
