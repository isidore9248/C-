#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Graph.h"	



/********************************************�ڽӾ���********************************************************/

/// <summary></summary>				��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
/// <param name="VertexNum"></param>�������
/// <returns></returns>				ָ�룬ָ�򴴽��õ��ڽӾ���ͼ
MGraph Graph_CreatMGraph(int VertexNum)
{
	MGraph NewMGraph;
	NewMGraph = (MGraph)malloc(sizeof(struct MGraph_Node));
	NewMGraph->Nv = VertexNum;	//����
	NewMGraph->Ne = 0;			//��

	//������Ĭ�ϴ�0��ʼ���� (NewMGraph->Nv-1) ����
	Vertex V, W;
	for (V = 0; V < NewMGraph->Nv; V++)
	{
		for (W = 0; W < NewMGraph->Nv; W++)
		{
			NewMGraph->G[V][W] = 0;	//û�б�
		}
	}
	return NewMGraph;
}


/// <summary></summary>			��MGraph�����
/// <param name="Graph"></param>Ҫ�����ͼ
/// <param name="E"></param>	�ṹ�壬��Ҫ��ֵ��Ҫ����ı�
void Graph_InsertMGraphEdge(MGraph Graph, MGraph_Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//����ͼ����Ҫ����<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}


/// <summary>		����һ���������ڽӾ���ͼ
/// </summary>		�����ʽ�� �����±�(�ո�)�����±�(�ո�)�ߵ�Ȩֵ
/// �����������ݣ������������̴�������ȡ��������(���·���βforѭ��)
/// <param name="Nv"></param>	�������
/// <param name="Ne"></param>	�ߵĸ���
/// <returns></returns>			ָ�룬ָ�򴴽��õ��ڽӾ���ͼ
MGraph Graph_BuildMGraph(int Nv,int Ne)
{
	MGraph Graph=Graph_CreatMGraph(Nv);	//���һ��ֻ��Nv�����㵫û�бߵ�ͼ
	Graph->Ne = Ne;	//�߽ڵ㸳ֵ
	if (Graph->Ne != 0)
	{	
		//����߽ڵ㣬ֻ����һ�μ��ɣ�ÿ����forѭ���иı�߽ڵ��ֵ���ٲ����
		MGraph_Edge Edge = (MGraph_Edge)malloc(sizeof(struct Graph_EdgeNode));
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &Edge->V1, &Edge->V2, &Edge->Weight);
			Graph_InsertMGraphEdge(Graph, Edge);
		}

	}
	/*
	//������������ݣ����������
	for (int i = 0; i < Graph->Nv; i++)
	{
		scanf("%d", &Graph->Data[i]);
	}
	*/

	return Graph;
}

 

/// <summary>	���ڽӾ���ͼ�Ķ�����в�������
/// </summary>
/// <param name="G"></param>	ָ��,ָ��Ҫ���в������ڽӾ���ͼ
/// <param name="Nv"></param>	����,��		G->Data[MaxVertexNum]	���в���
void Graph_MGraphDoSomething(MGraph G,int Nv)
{

}


/// <summary>	�ڽӾ����DFS(������ȵݹ��㷨)
/// </summary>	
/// <param name="Graph"></param>	ָ��,ָ��Ҫ���в������ڽӾ���ͼ
/// <param name="Nv"></param>		����
void Graph_MGraph_DFS(MGraph Graph, int Nv)
{
	/*	
	*	@brief	������������
	*	@note	�����ʹ��ļ�Ϊtrue δ���ʼ�Ϊfalse
	*/
	bool Vistied[MaxVertexNum];
	//��ʼ��Ϊδ����״̬false
	for (int Count = 0; Count < MaxVertexNum; Count++)
	{
		Vistied[Count] = false;
	}
	//����ʼ�Ķ����Ϊ������״̬true
	Vistied[Nv] = true;
	//�Ա����Ķ�����еĲ���
	Graph_MGraphDoSomething(Graph,Nv);
	//�ݹ����DFS
	for (int Count = 0; Count < Graph->Nv; Count++)
	{
		if (Graph->G[Nv][Count] != 0 && !Vistied[Count])
		{
			Graph_MGraph_DFS(Graph, Count);
		}
	}
}


/// <summary>	�ڽӾ���ͼ����ȱ�������
/// </summary>	
/// <param name="Graph"></param>ָ��,ָ��Ҫ���в������ڽӾ���ͼ
void Graph_MGraph_DFSTraverse(MGraph Graph)
{
	/*
	*	@brief	������������
	*	@note	�����ʹ��ļ�Ϊtrue δ���ʼ�Ϊfalse
	*/
	bool Vistied[MaxVertexNum];
	//��ʼ��Ϊδ����״̬false
	for (int Count = 0; Count < MaxVertexNum; Count++)
	{
		Vistied[Count] = false;
	}

	for (int Nv = 0; Nv < Graph->Nv; Nv++)
	{
		if (!Vistied[Nv])
		{
			Graph_MGraph_DFS(Graph, Nv);
		}
	}

}



/********************************************�ڽӱ�********************************************************/

/// <summary></summary>				��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
/// <param name="VertexNum"></param>�������
/// <returns></returns>				ָ�룬ָ�򴴽��õ��ڽӱ��ͼ
LGraph Graph_CreatLGraph(int VertexNum)
{

	LGraph Graph = (LGraph)malloc(sizeof(struct LGraphNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ�������ڽӱ�ı߽ڵ�Ͷ��������
	//Ĭ�ϱ�Ŵ�0��ʼ����(Graph->Nv-1)
	for (int i = 0; i < Graph->Nv; i++)
	{
		Graph->G[i].FirstEdge = NULL;
		Graph->G[i].Data = 0;
	}
	return Graph;
}


/// <summary></summary>			��LGraph�����
/// <param name="Graph"></param>Ҫ�����ͼ
/// <param name="E"></param>	�ṹ�壬��Ҫ��ֵ��Ҫ����ı�
void Graph_InsertLGraphEdge(LGraph Graph, LGraph_Edge Edge)
{

	/************************ �����<V1,V2> ************************/
	//ΪV2�����µ��ٽ��
	PtrToAdjVNode NewEdgeNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewEdgeNode2->AdjV = Edge->V2;	//�±�ΪV2
	NewEdgeNode2->Weight = Edge->Weight;
	//��V2����V1�ı�ͷ���滻��ԭ����FirstEdge
	NewEdgeNode2->Next = Graph->G[Edge->V1].FirstEdge;
	Graph->G[Edge->V1].FirstEdge = NewEdgeNode2;

	/************************ ����ͼ��Ҫ�����<V2,V1> ************************/
	//ΪV1�����µ��ٽ��
	PtrToAdjVNode NewEdgeNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewEdgeNode1->AdjV = Edge->V1;	//�±�ΪV1
	NewEdgeNode1->Weight = Edge->Weight;
	//��V1����V2�ı�ͷ���滻��ԭ����FirstEdge
	NewEdgeNode1->Next = Graph->G[Edge->V2].FirstEdge;
	Graph->G[Edge->V2].FirstEdge = NewEdgeNode1;

}



void Graph_LGraph_DFS(LGraph Graph, int Nv)
{


}


