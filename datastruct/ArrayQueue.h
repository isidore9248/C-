#pragma once
#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#define MAXSIZE 255
typedef int ElementType;
typedef struct ArrayQNode* ArrayQueue;
/// </summary>����Ϊ�ýṹ��ʵ��ѭ�����У�
/// front	Ϊ����ͷ��λ�ã���Ӧ����ĽǱ꣩
/// rear	Ϊ����β��λ�ã���Ӧ����ĽǱ꣩
/// ���Ϊfront���Ҳ�Ϊrear		����front<rear
/// front-��-��-��-��-rear 
/// ɾ��������front�˽��У���Ӳ�����rear�˽���
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
