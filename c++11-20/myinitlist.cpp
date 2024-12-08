#include <iostream>
using namespace std;

//初始化列表需要相同的类型，类似容器
template <typename T>
void myinitlist_func(initializer_list <T> ls)
{
	auto it = ls.begin();
	for (; it != ls.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void myinitlist_test1(void)
{
	myinitlist_func({ 1,4,6,12,843,23 });
}