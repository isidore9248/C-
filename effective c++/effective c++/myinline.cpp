#include <iostream>
#include "myinline.h"

int libfoo::libfoo_2022::foo(int) { return 0; }

void inlinenamespace_test(void)
{
	std::cout << libfoo::foo(5) << std::endl;
	//存在同名函数，编译器会自动调用inline函数
}

inline void inline_func(void) {}
void (*pinline_func) () = inline_func;
void inlinefunc_test(void)
{
	inline_func();	//可能是inline
	pinline_func();	//通过指针可能不是inline的
}

void inline_test(void)
{
	//libfoo::Bar1 bar1;
	//libfoo::Bar2 bar2;

	//foo1(bar1);	//根据传入的参数确定命名空间，调用Bar1的foo1()函数
}