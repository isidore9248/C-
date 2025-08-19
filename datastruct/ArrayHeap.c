#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "ArrayHeap.h"

/// <summary></summary>		����һ������
/// <param name="MaxSize"></param>	�������ܴ�ŵ��������
/// <returns></returns>	�ṹָ�룬ָ�򴴽��õ�����
MaxHeap ArrayHeap_CreatMaxHeap(int MaxSize)
{
	MaxHeap NewHeap = malloc(sizeof(struct Array_MaxHeap));

	//���±�Ϊ1�ĵط���ʼ��ţ�Element[0]Ϊ�ڱ�
	NewHeap->Element = malloc(sizeof(ArrayHeap_ElementType) * (MaxSize + 1));
	NewHeap->Size = 0;
	NewHeap->Capacity = MaxSize;
	/*���塰�ڱ���Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������*/
	NewHeap->Element[0] = MaxHeap_MaxData;

	return NewHeap;
}


/// <summary> </summary>	�ж�һ�����Ƿ�����
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õĶ�
/// <returns></returns>		true������		false��δ��
bool ArrayHeap_IsFull(MaxHeap Heap)
{
	if (Heap->Size == Heap->Capacity) { return true; }
	return false;
}


/// <summary> </summary>	�ж�һ�����Ƿ�Ϊ��
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õĶ�
/// <returns></returns>		true����		false������
bool ArrayHeap_IsEmpty(MaxHeap Heap)
{
	if (Heap->Size == 0) { return true; }
	return false;
}


/// <summary></summary>		�������в���һ��Ԫ��
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õ�����
/// <param name="Item"></param>	Ҫ�����Ԫ��ֵ
void ArrayHeap_MaxHeapInset(MaxHeap Heap, ArrayHeap_ElementType Item)
{
	if (ArrayHeap_IsFull(Heap)) { return; }

	int HeapCount = ++Heap->Size;	//HeapCountΪ����Ԫ�غ����һ��Ԫ�ص������±�
	
	//���丸�ڵ�͵�ǰ�ڵ㲻��������(���ڵ�С�ڵ�ǰ�ڵ�)
	//ʹ���ڱ���������±�Ϊ0�Ľڵ�Ƚ�
	for (; Heap->Element[HeapCount / 2] < Item; HeapCount /= 2)	
	{
		Heap->Element[HeapCount] = Heap->Element[HeapCount / 2];
//�˴�û��ֱ�ӽ���,������һ���м�ֵItem�洢Ҫ�Ƚϵ�ֵ,�����ж�����ú��ҵ��ڵ��ٸ�ֵ
	}
	Heap->Element[HeapCount] = Item;
	
}



/// <summary></summary>			ɾ�����ѵ����Ԫ�أ������ڵ�
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õ�����
/// <returns></returns>			ɾ�����ĸ��ڵ��ֵ
ArrayHeap_ElementType ArrayHeap_MaxHeapDelete(MaxHeap Heap)
{
	if (ArrayHeap_IsEmpty(Heap)) { return; }

	ArrayHeap_ElementType Retaval = Heap->Element[1];//�̶�ɾ�����Ԫ�أ������ڵ�

	//�����һ��Ԫ�ػ������ڵ�,����Ϊ��ʱTemp���Ǹ��ڵ�,��ֵΪɾ��ǰ�����һ���ڵ��ֵ
	ArrayHeap_ElementType Temp = Heap->Element[Heap->Size--];

	int Parent = 1, Child;
	
	//Parent=1					:�Ӹ��ڵ㿪ʼ���������Ҷ��ӿ�ʼ�Ƚ�
	//Parent * 2 <= Heap->Size	:ȷ���Ƿ��ж���
	//		Parent*2	Ϊ������ӵ��±�,������Ӳ��������Ҷ���Ҳ������
	//Parent = Child			:������һ���ж�
	for (Parent = 1; Parent * 2 <= Heap->Size; Parent = Child)
	{
		Child = Parent * 2;	//�Ƚ�Childָ��ýڵ�������
		//Child != Heap->Size	:������±��Ƿ����Ŀǰ�ѵ�����,���ж��Ƿ����Ҷ���
		//����һ��forѭ�����ж����Ƿ��ж���(�Ƿ���������),���Դ˴�ֻ��Ҫ�ж��Ƿ����Ҷ���
		//Heap->Element[Child] < Heap->Element[Child + 1]	:������Ƿ�С���Ҷ���
		if ((Child != Heap->Size) && (Heap->Element[Child] < Heap->Element[Child + 1]))
		{
			Child++;	//�˴������жϵ�Ŀ����Ϊ����Childָ�����Ҷ����д���Ǹ�
		}

		if (Temp > Heap->Element[Child]) { break; }
		else
		{
			Heap->Element[Parent] = Heap->Element[Child];	
//�˴�û��ֱ�ӽ���,������һ���м�ֵTemp�洢Ҫ�Ƚϵ�ֵ,�����ж�����ú��ҵ��ڵ��ٸ�ֵ
		}

	}
	Heap->Element[Parent] = Temp;

	return Retaval;
}


/// <summary></summary>		����һ����С��
/// <param name="MaxSize"></param>	��С�����ܴ�ŵ��������
/// <returns></returns>	�ṹָ�룬ָ�򴴽��õ���С��
MinHeap ArrayHeap_CreatMinHeap(int MaxSize)
{
	MinHeap NewHeap = malloc(sizeof(struct Array_MinHeap));

	NewHeap->Element = malloc(sizeof(ArrayHeap_ElementType) * (MaxSize + 1));
	NewHeap->Capacity = MaxSize;
	NewHeap->Size = 0;
	NewHeap->Element[0] = MinHeap_MinData;
	return NewHeap;
}


/// <summary></summary>		����С���в���һ��Ԫ��
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õ���С��
/// <param name="Item"></param>	Ҫ�����Ԫ��ֵ
void ArrayHeap_MinHeapInset(MinHeap Heap, ArrayHeap_ElementType Item)
{
	if (ArrayHeap_IsFull(Heap)) { return; }

	int HeapCount = ++Heap->Size;	//HeapCountΪ����Ԫ�غ����һ��Ԫ�ص������±�

	//���丸�ڵ�͵�ǰ�ڵ㲻������С��(���ڵ���ڵ�ǰ�ڵ�)
	//ʹ���ڱ���������±�Ϊ0�Ľڵ�Ƚ�
	for (; Heap->Element[HeapCount / 2] > Item; HeapCount /= 2)
	{
		Heap->Element[HeapCount] = Heap->Element[HeapCount / 2];
		//�˴�û��ֱ�ӽ���,������һ���м�ֵItem�洢Ҫ�Ƚϵ�ֵ,�����ж�����ú��ҵ��ڵ��ٸ�ֵ
	}
	Heap->Element[HeapCount] = Item;

}



/// <summary></summary>			ɾ����С�ѵ���СԪ�أ������ڵ�
/// <param name="Heap"></param>	�ṹָ�룬ָ�򴴽��õ���С��
/// <returns></returns>			ɾ�����ĸ��ڵ��ֵ
ArrayHeap_ElementType ArrayHeap_MinHeapDelete(MinHeap Heap)
{
	if (ArrayHeap_IsEmpty(Heap)) { return; }

	ArrayHeap_ElementType Retaval = Heap->Element[1];//�̶�ɾ�����Ԫ�أ������ڵ�

	//�����һ��Ԫ�ػ������ڵ�,����Ϊ��ʱTemp���Ǹ��ڵ�,��ֵΪɾ��ǰ�����һ���ڵ��ֵ
	ArrayHeap_ElementType Temp = Heap->Element[Heap->Size--];

	int Parent = 1, Child;

	//Parent=1					:�Ӹ��ڵ㿪ʼ���������Ҷ��ӿ�ʼ�Ƚ�
	//Parent * 2 <= Heap->Size	:ȷ���Ƿ��ж���
	//		Parent*2	Ϊ������ӵ��±�,������Ӳ��������Ҷ���Ҳ������
	//Parent = Child			:������һ���ж�
	for (Parent = 1; Parent * 2 <= Heap->Size; Parent = Child)
	{
		Child = Parent * 2;	//�Ƚ�Childָ��ýڵ�������
		//Child != Heap->Size	:������±��Ƿ����Ŀǰ�ѵ�����,���ж��Ƿ����Ҷ���
		//����һ��forѭ�����ж����Ƿ��ж���(�Ƿ���������),���Դ˴�ֻ��Ҫ�ж��Ƿ����Ҷ���
		//Heap->Element[Child] > Heap->Element[Child + 1]	:������Ƿ�����Ҷ���
		if ((Child != Heap->Size) && (Heap->Element[Child] > Heap->Element[Child + 1]))
		{
			Child++;	//�˴������жϵ�Ŀ����Ϊ����Childָ�����Ҷ�����С���Ǹ�
		}

		if (Temp < Heap->Element[Child]) { break; }
		else
		{
			Heap->Element[Parent] = Heap->Element[Child];
			//�˴�û��ֱ�ӽ���,������һ���м�ֵTemp�洢Ҫ�Ƚϵ�ֵ,�����ж�����ú��ҵ��ڵ��ٸ�ֵ
		}

	}
	Heap->Element[Parent] = Temp;

	return Retaval;
}

