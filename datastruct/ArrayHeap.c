#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "ArrayHeap.h"

/// <summary></summary>		创建一个最大堆
/// <param name="MaxSize"></param>	最大堆所能存放的最大容量
/// <returns></returns>	结构指针，指向创建好的最大堆
MaxHeap ArrayHeap_CreatMaxHeap(int MaxSize)
{
	MaxHeap NewHeap = malloc(sizeof(struct Array_MaxHeap));

	//从下标为1的地方开始存放，Element[0]为哨兵
	NewHeap->Element = malloc(sizeof(ArrayHeap_ElementType) * (MaxSize + 1));
	NewHeap->Size = 0;
	NewHeap->Capacity = MaxSize;
	/*定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作*/
	NewHeap->Element[0] = MaxHeap_MaxData;

	return NewHeap;
}


/// <summary> </summary>	判断一个堆是否已满
/// <param name="Heap"></param>	结构指针，指向创建好的堆
/// <returns></returns>		true：已满		false：未满
bool ArrayHeap_IsFull(MaxHeap Heap)
{
	if (Heap->Size == Heap->Capacity) { return true; }
	return false;
}


/// <summary> </summary>	判断一个堆是否为空
/// <param name="Heap"></param>	结构指针，指向创建好的堆
/// <returns></returns>		true：空		false：不空
bool ArrayHeap_IsEmpty(MaxHeap Heap)
{
	if (Heap->Size == 0) { return true; }
	return false;
}


/// <summary></summary>		向最大堆中插入一个元素
/// <param name="Heap"></param>	结构指针，指向创建好的最大堆
/// <param name="Item"></param>	要插入的元素值
void ArrayHeap_MaxHeapInset(MaxHeap Heap, ArrayHeap_ElementType Item)
{
	if (ArrayHeap_IsFull(Heap)) { return; }

	int HeapCount = ++Heap->Size;	//HeapCount为插入元素后，最后一个元素的数组下标
	
	//当其父节点和当前节点不满足最大堆(父节点小于当前节点)
	//使用哨兵避免其和下标为0的节点比较
	for (; Heap->Element[HeapCount / 2] < Item; HeapCount /= 2)	
	{
		Heap->Element[HeapCount] = Heap->Element[HeapCount / 2];
//此处没有直接交换,而是用一个中间值Item存储要比较的值,将所有都排序好后找到节点再赋值
	}
	Heap->Element[HeapCount] = Item;
	
}



/// <summary></summary>			删除最大堆的最大元素，即根节点
/// <param name="Heap"></param>	结构指针，指向创建好的最大堆
/// <returns></returns>			删除掉的根节点的值
ArrayHeap_ElementType ArrayHeap_MaxHeapDelete(MaxHeap Heap)
{
	if (ArrayHeap_IsEmpty(Heap)) { return; }

	ArrayHeap_ElementType Retaval = Heap->Element[1];//固定删除最大元素，即根节点

	//将最后一个元素换到根节点,可认为此时Temp就是根节点,其值为删除前的最后一个节点的值
	ArrayHeap_ElementType Temp = Heap->Element[Heap->Size--];

	int Parent = 1, Child;
	
	//Parent=1					:从根节点开始和他的左右儿子开始比较
	//Parent * 2 <= Heap->Size	:确定是否有儿子
	//		Parent*2	为其左儿子的下标,若左儿子不存在则右儿子也不存在
	//Parent = Child			:进行下一层判断
	for (Parent = 1; Parent * 2 <= Heap->Size; Parent = Child)
	{
		Child = Parent * 2;	//先将Child指向该节点的左儿子
		//Child != Heap->Size	:左儿子下标是否等于目前堆的总数,即判断是否有右儿子
		//在上一级for循环中判断了是否有儿子(是否存在左儿子),所以此处只需要判断是否有右儿子
		//Heap->Element[Child] < Heap->Element[Child + 1]	:左儿子是否小于右儿子
		if ((Child != Heap->Size) && (Heap->Element[Child] < Heap->Element[Child + 1]))
		{
			Child++;	//此处条件判断的目的是为了让Child指向左右儿子中大的那个
		}

		if (Temp > Heap->Element[Child]) { break; }
		else
		{
			Heap->Element[Parent] = Heap->Element[Child];	
//此处没有直接交换,而是用一个中间值Temp存储要比较的值,将所有都排序好后找到节点再赋值
		}

	}
	Heap->Element[Parent] = Temp;

	return Retaval;
}


/// <summary></summary>		创建一个最小堆
/// <param name="MaxSize"></param>	最小堆所能存放的最大容量
/// <returns></returns>	结构指针，指向创建好的最小堆
MinHeap ArrayHeap_CreatMinHeap(int MaxSize)
{
	MinHeap NewHeap = malloc(sizeof(struct Array_MinHeap));

	NewHeap->Element = malloc(sizeof(ArrayHeap_ElementType) * (MaxSize + 1));
	NewHeap->Capacity = MaxSize;
	NewHeap->Size = 0;
	NewHeap->Element[0] = MinHeap_MinData;
	return NewHeap;
}


/// <summary></summary>		向最小堆中插入一个元素
/// <param name="Heap"></param>	结构指针，指向创建好的最小堆
/// <param name="Item"></param>	要插入的元素值
void ArrayHeap_MinHeapInset(MinHeap Heap, ArrayHeap_ElementType Item)
{
	if (ArrayHeap_IsFull(Heap)) { return; }

	int HeapCount = ++Heap->Size;	//HeapCount为插入元素后，最后一个元素的数组下标

	//当其父节点和当前节点不满足最小堆(父节点大于当前节点)
	//使用哨兵避免其和下标为0的节点比较
	for (; Heap->Element[HeapCount / 2] > Item; HeapCount /= 2)
	{
		Heap->Element[HeapCount] = Heap->Element[HeapCount / 2];
		//此处没有直接交换,而是用一个中间值Item存储要比较的值,将所有都排序好后找到节点再赋值
	}
	Heap->Element[HeapCount] = Item;

}



/// <summary></summary>			删除最小堆的最小元素，即根节点
/// <param name="Heap"></param>	结构指针，指向创建好的最小堆
/// <returns></returns>			删除掉的根节点的值
ArrayHeap_ElementType ArrayHeap_MinHeapDelete(MinHeap Heap)
{
	if (ArrayHeap_IsEmpty(Heap)) { return; }

	ArrayHeap_ElementType Retaval = Heap->Element[1];//固定删除最大元素，即根节点

	//将最后一个元素换到根节点,可认为此时Temp就是根节点,其值为删除前的最后一个节点的值
	ArrayHeap_ElementType Temp = Heap->Element[Heap->Size--];

	int Parent = 1, Child;

	//Parent=1					:从根节点开始和他的左右儿子开始比较
	//Parent * 2 <= Heap->Size	:确定是否有儿子
	//		Parent*2	为其左儿子的下标,若左儿子不存在则右儿子也不存在
	//Parent = Child			:进行下一层判断
	for (Parent = 1; Parent * 2 <= Heap->Size; Parent = Child)
	{
		Child = Parent * 2;	//先将Child指向该节点的左儿子
		//Child != Heap->Size	:左儿子下标是否等于目前堆的总数,即判断是否有右儿子
		//在上一级for循环中判断了是否有儿子(是否存在左儿子),所以此处只需要判断是否有右儿子
		//Heap->Element[Child] > Heap->Element[Child + 1]	:左儿子是否大于右儿子
		if ((Child != Heap->Size) && (Heap->Element[Child] > Heap->Element[Child + 1]))
		{
			Child++;	//此处条件判断的目的是为了让Child指向左右儿子中小的那个
		}

		if (Temp < Heap->Element[Child]) { break; }
		else
		{
			Heap->Element[Parent] = Heap->Element[Child];
			//此处没有直接交换,而是用一个中间值Temp存储要比较的值,将所有都排序好后找到节点再赋值
		}

	}
	Heap->Element[Parent] = Temp;

	return Retaval;
}

