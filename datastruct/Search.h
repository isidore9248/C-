#pragma once
#ifndef __SEARCH_H__
#define __SEARCH_H__

#define MAXSIZE	10

typedef int Search_ElementType;

typedef struct Search_Struct* Search;
struct Search_Struct
{
	Search_ElementType Element[MAXSIZE];
	int Length;
};


void Search_StructInit(Search Ptss);
int Search_SequentialSearch(Search Ptss, Search_ElementType Item);
int Search_BinarySearch(Search Ptss, Search_ElementType Item);

#endif // !__SEARCH_H__

/*����ģ��*/
/*
struct Search_Struct SearchStruct;
int Length;
printf("���������ݳ���\n");
scanf("%d", &Length);
SearchStruct.Element[0] = 0;
for (int i = 1; i <= Length; i++)
{
	SearchStruct.Element[i] = rand();
}
SearchStruct.Length = Length;
printf("���ɵ�����������£�\n");
for (int i = 0; i <= Length; i++)
{
	printf("%d ", SearchStruct.Element[i]);
}

int Count = 0;
printf("������Ҫ���ҵ����ݣ�\n");
scanf("%d", &Count);
Count = Search_BinarySearch(&SearchStruct, Count);

printf("Count=%d\n", Count);
*/


