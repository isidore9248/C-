#pragma once
#ifndef __LINKLIST_H__
#define	__LINKLIST_H__


typedef struct LinkList* LinkList_Ptr;
struct LinkList
{
	int Data;
	struct LinkList* Next;
};

LinkList_Ptr LinkListReverse(LinkList_Ptr Head, int ReverseNum);

#endif // !__LINKLIST_H__
