#include <iostream>
using namespace std;

namespace Parent
{
	namespace Child1
	{
		void foo()
		{
			cout << "Child1::foo()" << endl;
		}
	}
	inline namespace Child2
		//相当于删除Chilld2空间，直接写在Parent内
	{
		void foo()
		{
			cout << "Child2::foo()" << endl;
		}
	}
}	//namespace Parent

void mynamespace_test(void)
{
	//嵌套命名空间
	//含有inline命名空间的可以不写空间名称
	//没有inline的需要写空间名称
	Parent::foo();			//调用的是Child2的函数
	Parent::Child2::foo();	//兼容老代码
	Parent::Child1::foo();	//调用的是Child1的函数
}

//c++17
namespace A::B::C
{
	int foo(void) { return 5; };
}
/*
等价于
namespace A
{
	namespace B
	{
		namespace C{int foo(void) { return 5; };}
	}
}
*/

//c++20 内联命名空间
//inline 可以出现在除第一个命名空间外的任意命名空间
namespace animal::inline dog
{
}