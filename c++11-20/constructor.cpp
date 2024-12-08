#include <iostream>
using namespace std;
#include <string>
#include "constructor.h"
void constructor_test(void)
{
	//构造
	ConChild c1(520, 13.14);
	cout << "int: " << c1.m_i << ", double: " << c1.m_j << endl;
	ConChild c2(520, 13.14, "i love you");
	cout << "int: " << c2.m_i << ", double: "
		<< c2.m_j << ", string: " << c2.m_k << endl;

	//使用父类的隐藏函数
	c1.func();
}