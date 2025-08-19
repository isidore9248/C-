/*
���ļ�Ϊ���������ʽ������״���ϣ����и��ڵ��Parent=-1
ParentΪ���ڵ���������е��±�
*/

#pragma once
#ifndef __ARRAYSETTYPE_H__
#define	__ARRAYSETTYPE_H__

#define ArraySetType_MAXSIZE	10	//��Ϊ�������󳤶�


typedef int ArraySetType_ElementType;

typedef struct ArraySetType SetType;
struct ArraySetType
{
	ArraySetType_ElementType Data;
	int Parent;
};


int ArraySetType_Find(SetType S[], ArraySetType_ElementType Item);
void ArraySetType_Union(SetType S[], ArraySetType_ElementType ItemOne, ArraySetType_ElementType ItemTwo);






#endif // !__ARRAYSETTYPE_H__
