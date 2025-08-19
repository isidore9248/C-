#pragma once
#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MaxVertexNum 100	//��󶥵���

typedef int Vertex;		//����
typedef int Graph_WeightType;
typedef int Graph_DataType;

//�߽ڵ�
typedef struct Graph_EdgeNode* PtrToENode;
struct Graph_EdgeNode
{
	Vertex V1, V2;	//�����<V1,V2>
	Graph_WeightType Weight;	//Ȩ��
};
//���ڽӾ�����ڽӱ��о���Ҫʹ��
typedef PtrToENode MGraph_Edge;
typedef PtrToENode LGraph_Edge;

/********************************************�ڽӾ���********************************************************/
//ͼ�ڵ�
typedef struct MGraph_Node* PtrToMGraphNode;
struct MGraph_Node
{
	int Nv;//�������
	int Ne;//�ߵĸ���
	Graph_WeightType G[MaxVertexNum][MaxVertexNum];
	//��Ȩͼʱ�����бߣ���G[v][w]=1,����Ϊ0;
	//��Ȩͼʱ�����бߣ���Ϊ����ߵ�Ȩֵ������Ϊ0�������
	Graph_DataType Data[MaxVertexNum];//�涥������
};
typedef PtrToMGraphNode MGraph;	//�ڽӾ���洢��ͼ����




MGraph Graph_CreatMGraph(int VertexNum);
void Graph_InsertMGraphEdge(MGraph Graph, MGraph_Edge E);
MGraph Graph_BuildMGraph(int Nv, int Ne);
/****************DFS****************/
void Graph_MGraphDoSomething(MGraph G, int Nv);
void Graph_MGraph_DFS(MGraph Graph, int Nv);
void Graph_MGraph_DFSTraverse(MGraph Graph);



/********************************************�ڽӱ�********************************************************/
//�߽ڵ�
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;//�ڽӵ��±�
	Graph_WeightType Weight;//�˽ڵ����һ���ڵ�ıߵ�Ȩ��
	PtrToAdjVNode Next;	//ָ����һ���ڵ��ָ��
};

//�����ڵ�
typedef struct VNode
{
	PtrToAdjVNode FirstEdge;
	Graph_DataType Data;	//��������
}AdjList [MaxVertexNum];	//�ڽӱ�����

//ͼ�ڵ�
typedef struct LGraphNode* PtrToLGraphNode;
struct LGraphNode
{
	int Nv;//�������
	int Ne;//�ߵĸ���
	AdjList G;//�ڽӱ�(����)
};
typedef PtrToLGraphNode LGraph;	//�ڽӱ�洢��ͼ����




LGraph Graph_CreatLGraph(int VertexNum);
void Graph_InsertLGraphEdge(LGraph Graph, LGraph_Edge Edge);
/****************DFS****************/






#endif // !__GRAPH_H__
