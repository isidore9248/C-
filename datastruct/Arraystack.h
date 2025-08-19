#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#define ERROR -999

#define MAXSIZE1	255	//һ����ջ���������
#define MAXSIZE2	255	//������ջ���������

typedef	int ElementType;
typedef struct SingleNode* S_Stack;
/// </summary>	������ջ
struct SingleNode
{
	ElementType	Data[MAXSIZE1];	//һά���飬����Ԫ�ص�ֻ����Ϊ-999������#define ERROR -999
	int Top;					//ָ���ջ��ջ��(��Ӧ������ĽǱ�)��Top=-1��ʾ��ջ
};

typedef struct DoubleNode* D_Stack;
/// </summary>	һ���ṹ��ʵ��������ջ
struct DoubleNode
{
	ElementType	Data[MAXSIZE2];
	int Top1;					//Top1Ϊ�����ҵĶ�ջջ��λ��
	int Top2;					//Top2Ϊ���ҵ���Ķ�ջջ��λ��
	//Top1 = -1 && Top2=MAXSIZE��ʾ��ջ
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
