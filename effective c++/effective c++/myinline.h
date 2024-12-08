#pragma once

struct
{
	inline static int x = 10;	//inline存在后，变量的定义和声明可以在一起，变量可以被分配内存
};

#define some_macro	2022L
namespace libfoo
{
#if some_macro >= 2022L
	inline
#endif
		namespace libfoo_2022
	{
		int foo(int);
		float foo(float);
	}
#if some_macro >= 2019L && some_macro < 2022L
	inline
#endif
		namespace libfoo_2019
	{
		int foo(int);
	}
}

void inlinenamespace_test(void);

void inlinefunc_test(void);

//namespace libfoo {
//	class Bar1 {};
//	inline namespace libfoo_2022
//	{
//		void foo1(Bar1) {}	//void libfoo::libfoo_2022::foo1(libfoo::Bar1)
//		class Bar2 {};
//	}
//	using namespace libfoo_2022;
//	void foo2(Bar2) {}	//	void libfoo::foo2(libfoo::libfoo 2022::Bar2)
//}

void inline_test(void);