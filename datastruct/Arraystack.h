#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#define ERROR -999

#define MAXSIZE1	255	//一个堆栈的最大容量
#define MAXSIZE2	255	//两个堆栈的最大容量

typedef	int ElementType;
typedef struct SingleNode* S_Stack;
/// </summary>	创建堆栈
struct SingleNode
{
	ElementType	Data[MAXSIZE1];	//一维数组，其中元素的只不可为-999，由于#define ERROR -999
	int Top;					//指向堆栈的栈顶(对应于数组的角标)，Top=-1表示空栈
};

typedef struct DoubleNode* D_Stack;
/// </summary>	一个结构体实现两个堆栈
struct DoubleNode
{
	ElementType	Data[MAXSIZE2];
	int Top1;					//Top1为从左到右的堆栈栈顶位置
	int Top2;					//Top2为从右到左的堆栈栈顶位置
	//Top1 = -1 && Top2=MAXSIZE表示空栈
};


void S_Arraystack_Init(S_Stack Ptrs);
void D_Arraystack_Init(D_Stack Ptrs);
S_Stack S_ArrayStack_Creat(void);
int S_ArrayStack_IsEmpty(S_Stack Ptrs);
void Arraystack_Push(S_Stack Ptrs, ElementType item);
ElementType Arraystack_Pop(S_Stack Ptrs);
void Arraystack_DoublePush(D_Stack Ptrs, ElementType item, int Tag);
ElementType Arraystack_DoublePop(D_Stack Ptrs, int Tag);


#endif // !__ARRAYSTACK_H__
