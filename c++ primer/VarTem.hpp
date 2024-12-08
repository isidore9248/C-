#pragma once

//老版本
void VarFunc() {}
template<typename T, typename... Args>
void VarFunc(const T& t, const Args&... args)
{
	if (sizeof...(args) == 0)
	{
		cout << t << endl;
		return;
	}
	cout << t << "  ";
	return VarFunc(args...);
}

//c++17 按条件编译
template<typename T, typename... Args>
void VarFunc_cpp17_conditional(const T& t, const Args&... args)
{
	// 使用 if constexpr 来检查剩余参数的数量
	if constexpr (sizeof...(args) == 0)
	{
		// 如果没有更多的参数，则输出当前参数并结束递归
		std::cout << t << std::endl;
	}
	else
	{
		//如果还有更多参数，则输出当前参数并递归调用自身
		std::cout << t << "  ";
		VarFunc_cpp17_conditional(args...);
	}
}

//c++17  折叠表达式
template<typename... Args>
void VarFunc_cpp17_fold(const Args&... args)
{
	((cout << args << "  "), ..., (cout << endl));
}

template<typename... Args>
auto sum(Args...args)
{
	return (... + args);	//从左到右计算表达式
	//return (args +...);		//从右到左计算表达式
}

void VarTem_test(void)
{
	VarFunc_cpp17_fold("3", 123, 'c', 152, 4, 2);
	VarFunc_cpp17_conditional("hello", "c", 123, "iasjd");
	VarFunc(666, 126734);
	cout << sum(4, 1, 5);
}