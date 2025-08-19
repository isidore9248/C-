#pragma once
#ifndef __ARRAYSTRING_H__
#define __ARRAYSTRING_H__

#define MAXSIZE		255

typedef char AStringElementType;

typedef struct ArrayString* AString;
struct ArrayString
{
	AStringElementType ch[MAXSIZE+1];
	//ֻʹ��1-256���±��λ��,ch[0]��Ϊ�ڱ�
	//Ϊ��������MAXSIZE��λ��,�������ﶨ��MAXSIZE+1��С������
	int Length;

};


void ArrayString_Init(AString Ptas);
void ArrayString_CreateString(AString Ptas);
int ArrayString_BF_Index(AString MainString, AString SubString, int Pos);
int ArrayString_KMP_Index(AString MainPtas, AString SubPtas, int Pos);


#endif // !__ARRAYSTRING_H__
