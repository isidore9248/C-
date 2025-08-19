#pragma once
#ifndef __HUFFMANTREE_H__
#define __HUFFMANTREE_H__

typedef struct HuffmanTree_Node* HuffmanTree;
struct HuffmanTree_Node
{
	int Weight;
	HuffmanTree Left, Right;
};






#endif // !__HUFFMANTREE_H__
