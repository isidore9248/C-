//����Ϊ������ʵ�ֶѣ���Ϊ��ȫ����������ʽ,���ڵ�Ϊ�����±�Ϊ1�ĵط��洢
//����
#pragma once
#ifndef __ARRAYHEAP_H__
#define	__ARRAYHEAP_H__

typedef int ArrayHeap_ElementType;

#define MaxHeap_MaxData 1000

typedef struct Array_MaxHeap* MaxHeap;
struct Array_MaxHeap
{
	ArrayHeap_ElementType* Element;	//����������ʽ�Ķ�
	//���±�Ϊ1�ĵط���ʼ��ţ�Element[0]Ϊ�ڱ�

	int Size;			//��ǰԪ�صĸ���
	int Capacity;		//�ѵ��������
};


MaxHeap ArrayHeap_CreatMaxHeap(int MaxSize);
bool ArrayHeap_IsFull(MaxHeap Heap);
bool ArrayHeap_IsEmpty(MaxHeap Heap);
void ArrayHeap_MaxHeapInset(MaxHeap Heap, ArrayHeap_ElementType Item);
ArrayHeap_ElementType ArrayHeap_MaxHeapDelete(MaxHeap Heap);


//��С��
#define MinHeap_MinData	-1001
typedef struct Array_MinHeap* MinHeap;
struct Array_MinHeap 
{
	ArrayHeap_ElementType* Element;	//����������ʽ�Ķ�
	//���±�Ϊ1�ĵط���ʼ��ţ�Element[0]Ϊ�ڱ�

	int Size;			//��ǰԪ�صĸ���
	int Capacity;		//�ѵ��������
};

MinHeap ArrayHeap_CreatMinHeap(int MaxSize);
//bool ArrayHeap_IsFull(MaxHeap Heap);
//bool ArrayHeap_IsEmpty(MaxHeap Heap);
void ArrayHeap_MinHeapInset(MinHeap Heap, ArrayHeap_ElementType Item);
ArrayHeap_ElementType ArrayHeap_MinHeapDelete(MinHeap Heap);


#endif // !__ARRAYHEAP_H__
