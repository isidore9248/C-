#pragma once
#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MaxVertexNum 100	//最大顶点数

typedef int Vertex;		//顶点
typedef int Graph_WeightType;
typedef int Graph_DataType;

//边节点
typedef struct Graph_EdgeNode* PtrToENode;
struct Graph_EdgeNode
{
	Vertex V1, V2;	//有向边<V1,V2>
	Graph_WeightType Weight;	//权重
};
//在邻接矩阵和邻接表中均需要使用
typedef PtrToENode MGraph_Edge;
typedef PtrToENode LGraph_Edge;

/********************************************邻接矩阵********************************************************/
//图节点
typedef struct MGraph_Node* PtrToMGraphNode;
struct MGraph_Node
{
	int Nv;//顶点个数
	int Ne;//边的个数
	Graph_WeightType G[MaxVertexNum][MaxVertexNum];
	//无权图时：若有边，则G[v][w]=1,否则为0;
	//有权图时：若有边，则为两点边的权值，否则为0或无穷大
	Graph_DataType Data[MaxVertexNum];//存顶点数据
};
typedef PtrToMGraphNode MGraph;	//邻接矩阵存储的图类型




MGraph Graph_CreatMGraph(int VertexNum);
void Graph_InsertMGraphEdge(MGraph Graph, MGraph_Edge E);
MGraph Graph_BuildMGraph(int Nv, int Ne);
/****************DFS****************/
void Graph_MGraphDoSomething(MGraph G, int Nv);
void Graph_MGraph_DFS(MGraph Graph, int Nv);
void Graph_MGraph_DFSTraverse(MGraph Graph);



/********************************************邻接表********************************************************/
//边节点
typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;//邻接点下标
	Graph_WeightType Weight;//此节点和上一个节点的边的权重
	PtrToAdjVNode Next;	//指向下一个节点的指针
};

//顶点表节点
typedef struct VNode
{
	PtrToAdjVNode FirstEdge;
	Graph_DataType Data;	//顶点数据
}AdjList [MaxVertexNum];	//邻接表类型

//图节点
typedef struct LGraphNode* PtrToLGraphNode;
struct LGraphNode
{
	int Nv;//顶点个数
	int Ne;//边的个数
	AdjList G;//邻接表(数组)
};
typedef PtrToLGraphNode LGraph;	//邻接表存储的图类型




LGraph Graph_CreatLGraph(int VertexNum);
void Graph_InsertLGraphEdge(LGraph Graph, LGraph_Edge Edge);
/****************DFS****************/






#endif // !__GRAPH_H__
