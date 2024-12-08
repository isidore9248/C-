#pragma once

#include <iostream>
using namespace std;
#include <functional>
using namespace std::placeholders;

int add(int a, int b) { return a + b; }
void func_bind_out(int x, int y) { cout << x << " " << y << endl; }
void bind_test(void)
{
	/*调用格式1:*/
	//将bind绑定的函数存储起来
	auto f = bind(add, 2, placeholders::_1);
	cout << "f=" << f(1) << endl;		//等价于调用add(2,1)

	/*调用格式2:*/
	//
	bind(func_bind_out, 1, 2)();
	bind(func_bind_out, 2, _2)(10, 20);
}