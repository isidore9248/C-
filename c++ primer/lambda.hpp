#pragma once

#include <iostream>
using namespace std;

void lambda_func1(int x, int y)
{
	int a = 0, b = 6;
	[=, &x]()mutable -> void	//如果没有mutable则只能读，不能写
		//但副本和本体的内存依然不同
		{
			int c = a;
			int d = x;
			b++;	//需要存在mutable关键字才可以修改拷贝副本
			cout << b << endl;
		}();	//此处需要加上()才表示被调用，
	//()内填入的参数根据[]后()内的定义而定
}

void lambda_func2(void)
{
	using lambda_cppfunc = int(*)(int, int);
	lambda_cppfunc lambdafunc = [](int x, int y) {return x + y; };
	cout << lambdafunc(123, 5) << endl;
}

void lambda_test1(void)
{
	lambda_func1(5, 6);
	lambda_func2();
}