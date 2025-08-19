#pragma once
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#define MAXSIZE 4

typedef int ElementType;

/// front->��->��->��->��(rear)-> 
/// ɾ��������front�˽��У���Ӳ�����rear�˽���


/// </summary>	��ʽ�ṹ�Ľڵ�
struct Node
{
	ElementType Data;
	struct Node* Next;
};


typedef struct LinkQNode* LinkQueue;
/// </summary>	ָ����ʽ�ṹ��ͷ��βָ��ṹ
struct LinkQNode
{
	struct Node* front;
	struct Node* rear;
};
LinkQueue Ptrq;//ָ��ͷ��βָ��ṹ��ָ��

struct Node* LinkQueue_Creat(void);
ElementType LinkQueue_Delete(LinkQueue Ptrq);
void LinkQueue_Add(LinkQueue Ptrq, ElementType item);

#endif // !__LINKQUEUE_H__
