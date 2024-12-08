#include <iostream>
using namespace std;

template <typename T, typename U>
//在c++14后可以不加返回类型后置,直接使用auto
auto add(T t, U u)      /*-> decltype(t + u) */
{
	return t + u;
}

void retpostset(void)
{
	int a = 4;
	double b = 5.2;
	auto c = add(a, b);
	cout << c << endl;
}