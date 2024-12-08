#pragma once

#include <iostream>
using namespace std;

bool lenthcompare(const string&, const string&) { return true; }

bool (*pf)(const string&, const string&);

void funcPtr_test(void)
{
	//返回类型、参数类型
	pf = &lenthcompare;
	//bool judge = pf("hello", "world");

	using pf2 = bool(const string&, const string&);		//函数别名
	using pf3 = bool(*)(const string&, const string&);	//函数指针别名

	pf3 p = &lenthcompare;	//	pf3 p = lenthcompare;
	p("hello", "world");	//	p("hello", "world");
}