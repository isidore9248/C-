#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include "Graph.h"	



/********************************************邻接矩阵********************************************************/

/// <summary></summary>				初始化一个有VertexNum个顶点但没有边的图
/// <param name="VertexNum"></param>顶点个数
/// <returns></returns>				指针，指向创建好的邻接矩阵图
MGraph Graph_CreatMGraph(int VertexNum)
{
	MGraph NewMGraph;
	NewMGraph = (MGraph)malloc(sizeof(struct MGraph_Node));
	NewMGraph->Nv = VertexNum;	//顶点
	NewMGraph->Ne = 0;			//边

	//顶点编号默认从0开始，到 (NewMGraph->Nv-1) 结束
	Vertex V, W;
	for (V = 0; V < NewMGraph->Nv; V++)
	{
		for (W = 0; W < NewMGraph->Nv; W++)
		{
			NewMGraph->G[V][W] = 0;	//没有边
		}
	}
	return NewMGraph;
}


/// <summary></summary>			向MGraph插入边
/// <param name="Graph"></param>要插入的图
/// <param name="E"></param>	结构体，需要赋值好要插入的边
void Graph_InsertMGraphEdge(MGraph Graph, MGraph_Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	//无向图还需要插入<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;
}


/// <summary>		创建一个完整的邻接矩阵图
/// </summary>		输入格式： 顶点下标(空格)顶点下标(空格)边的权值
/// 若顶点有数据，则在上述过程创建完后读取顶点数据(见下方结尾for循环)
/// <param name="Nv"></param>	顶点个数
/// <param name="Ne"></param>	边的个数
/// <returns></returns>			指针，指向创建好的邻接矩阵图
MGraph Graph_BuildMGraph(int Nv,int Ne)
{
	MGraph Graph=Graph_CreatMGraph(Nv);	//获得一个只有Nv个顶点但没有边的图
	Graph->Ne = Ne;	//边节点赋值
	if (Graph->Ne != 0)
	{	
		//申请边节点，只申请一次即可，每次在for循环中改变边节点的值后再插入边
		MGraph_Edge Edge = (MGraph_Edge)malloc(sizeof(struct Graph_EdgeNode));
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &Edge->V1, &Edge->V2, &Edge->Weight);
			Graph_InsertMGraphEdge(Graph, Edge);
		}

	}
	/*
	//如果顶点有数据，则读入数据
	for (int i = 0; i < Graph->Nv; i++)
	{
		scanf("%d", &Graph->Data[i]);
	}
	*/

	return Graph;
}

 

/// <summary>	对邻接矩阵图的顶点进行操作函数
/// </summary>
/// <param name="G"></param>	指针,指向要进行操作的邻接矩阵图
/// <param name="Nv"></param>	顶点,对		G->Data[MaxVertexNum]	进行操作
void Graph_MGraphDoSomething(MGraph G,int Nv)
{

}


/// <summary>	邻接矩阵的DFS(深度优先递归算法)
/// </summary>	
/// <param name="Graph"></param>	指针,指向要进行操作的邻接矩阵图
/// <param name="Nv"></param>		顶点
void Graph_MGraph_DFS(MGraph Graph, int Nv)
{
	/*	
	*	@brief	创建访问数组
	*	@note	被访问过的记为true 未访问记为false
	*/
	bool Vistied[MaxVertexNum];
	//初始化为未访问状态false
	for (int Count = 0; Count < MaxVertexNum; Count++)
	{
		Vistied[Count] = false;
	}
	//将开始的顶点改为被访问状态true
	Vistied[Nv] = true;
	//对遍历的顶点进行的操作
	Graph_MGraphDoSomething(Graph,Nv);
	//递归调用DFS
	for (int Count = 0; Count < Graph->Nv; Count++)
	{
		if (Graph->G[Nv][Count] != 0 && !Vistied[Count])
		{
			Graph_MGraph_DFS(Graph, Count);
		}
	}
}


/// <summary>	邻接矩阵图的深度遍历操作
/// </summary>	
/// <param name="Graph"></param>指针,指向要进行操作的邻接矩阵图
void Graph_MGraph_DFSTraverse(MGraph Graph)
{
	/*
	*	@brief	创建访问数组
	*	@note	被访问过的记为true 未访问记为false
	*/
	bool Vistied[MaxVertexNum];
	//初始化为未访问状态false
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



/********************************************邻接表********************************************************/

/// <summary></summary>				初始化一个有VertexNum个顶点但没有边的图
/// <param name="VertexNum"></param>顶点个数
/// <returns></returns>				指针，指向创建好的邻接表的图
LGraph Graph_CreatLGraph(int VertexNum)
{

	LGraph Graph = (LGraph)malloc(sizeof(struct LGraphNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化所有邻接表的边节点和定点表数据
	//默认编号从0开始，到(Graph->Nv-1)
	for (int i = 0; i < Graph->Nv; i++)
	{
		Graph->G[i].FirstEdge = NULL;
		Graph->G[i].Data = 0;
	}
	return Graph;
}


/// <summary></summary>			向LGraph插入边
/// <param name="Graph"></param>要插入的图
/// <param name="E"></param>	结构体，需要赋值好要插入的边
void Graph_InsertLGraphEdge(LGraph Graph, LGraph_Edge Edge)
{

	/************************ 插入边<V1,V2> ************************/
	//为V2创立新的临界点
	PtrToAdjVNode NewEdgeNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewEdgeNode2->AdjV = Edge->V2;	//下标为V2
	NewEdgeNode2->Weight = Edge->Weight;
	//将V2插入V1的表头，替换其原来的FirstEdge
	NewEdgeNode2->Next = Graph->G[Edge->V1].FirstEdge;
	Graph->G[Edge->V1].FirstEdge = NewEdgeNode2;

	/************************ 无向图需要插入边<V2,V1> ************************/
	//为V1创立新的临界点
	PtrToAdjVNode NewEdgeNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewEdgeNode1->AdjV = Edge->V1;	//下标为V1
	NewEdgeNode1->Weight = Edge->Weight;
	//将V1插入V2的表头，替换其原来的FirstEdge
	NewEdgeNode1->Next = Graph->G[Edge->V2].FirstEdge;
	Graph->G[Edge->V2].FirstEdge = NewEdgeNode1;

}



void Graph_LGraph_DFS(LGraph Graph, int Nv)
{


}


