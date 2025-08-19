//以下为用数组实现堆，堆为完全二叉树的形式,根节点为数组下标为1的地方存储
//最大堆
#pragma once
#ifndef __ARRAYHEAP_H__
#define	__ARRAYHEAP_H__

typedef int ArrayHeap_ElementType;

#define MaxHeap_MaxData 1000

typedef struct Array_MaxHeap* MaxHeap;
struct Array_MaxHeap
{
	ArrayHeap_ElementType* Element;	//建立数组形式的堆
	//从下标为1的地方开始存放，Element[0]为哨兵

	int Size;			//当前元素的个数
	int Capacity;		//堆的最大容量
};


MaxHeap ArrayHeap_CreatMaxHeap(int MaxSize);
bool ArrayHeap_IsFull(MaxHeap Heap);
bool ArrayHeap_IsEmpty(MaxHeap Heap);
void ArrayHeap_MaxHeapInset(MaxHeap Heap, ArrayHeap_ElementType Item);
ArrayHeap_ElementType ArrayHeap_MaxHeapDelete(MaxHeap Heap);


//最小堆
#define MinHeap_MinData	-1001
typedef struct Array_MinHeap* MinHeap;
struct Array_MinHeap 
{
	ArrayHeap_ElementType* Element;	//建立数组形式的堆
	//从下标为1的地方开始存放，Element[0]为哨兵

	int Size;			//当前元素的个数
	int Capacity;		//堆的最大容量
};

MinHeap ArrayHeap_CreatMinHeap(int MaxSize);
//bool ArrayHeap_IsFull(MaxHeap Heap);
//bool ArrayHeap_IsEmpty(MaxHeap Heap);
void ArrayHeap_MinHeapInset(MinHeap Heap, ArrayHeap_ElementType Item);
ArrayHeap_ElementType ArrayHeap_MinHeapDelete(MinHeap Heap);


#endif // !__ARRAYHEAP_H__
