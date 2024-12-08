#pragma once

void lvalue_test1(void)
{
	int i = 0;
	int&& j = 9;	//右值引用

	//error		右值引用不能绑定左值
	//int && k = i;	//左值引用

	int&& p = static_cast<int&&>(i);	//将左值转换为右值引用

	//使用move
	int&& r = std::move(i);	//将左值转换为右值引用

	int&& q = static_cast<std::remove_reference<decltype(i)>::type&&>(i);
	//std::remove_reference 去除 i 的引用特性（如果有）
	//然后通过 static_cast 将结果转换为右值引用。
	//这个过程确保了即使 i 已经是一个引用类型，转换仍然有效。
}

template <typename T>
void lazy_func(T&& t) {}

void lvalue_func1(int&& i);	//右值引用作为参数
/*万能引用作为参数*/
//传入类型如果是左值引用，则会被转化为左值引用
//传入类型如果是右值或右值引用，则会被转化为右值引用
template <typename T>
void lvalue_func2(T&& t)
{
	lvalue_func(static_cast<T&&>(t));	//完美转发，不会产生临时对象，避免拷贝
}

void lvalue_func3(const int&) {}
void lvalue_func3(int&&) {}

//forward
template<typename T>
void lvalue_test2(T&& t)
{
	//在模板里t是引用类型
	lvalue_func3(t);		//调用的是左值引用版本
	lvalue_func3(std::forward<T>(t));	//调用的是右值引用版本
}