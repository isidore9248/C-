#pragma once
#ifndef __LISTSTACK_H__
#define __LISTSTACK_H__

typedef int ElementType;

typedef struct sNode* Stack;
struct sNode
{
	ElementType Data;
	Stack Next;
};


Stack Liststack_CreatStack(void);
void Liststack_Init(Stack Ptrs);
int Liststack_IsEmpty(Stack S);
void Liststack_Push(Stack Ptrs, ElementType item);
ElementType Liststack_Pop(Stack Ptrs);


#endif // !__LISTSTACK_H__
