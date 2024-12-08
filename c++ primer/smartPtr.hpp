#pragma once

#include <iostream>
using namespace std;
#include <string>

void sharedPtr_test(void)
{
	shared_ptr<int> pint1 = make_shared<int>(42);
	pint1.reset();	//释放 pint1 的所有权，使其指向 nullptr
	auto pvec1 = make_shared<vector<string> >();
	auto pnew1(new int(1024));

	pint1.reset(pnew1);	//将 pint1 指向	pnew1的内存地址对象

	unique_ptr<int> pint2(new int(1024));	//创建 unique_ptr 对象，并将其指向一个新的 int 类型对象
}

void uniquePtr_test(void)
{
	unique_ptr<int> pint2;
	pint2.release();	//释放 pint2 的所有权，使其指向 nullptr
}