#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>

void myfor_test1(void)
{
	vector<int> vt{ 1,4,6,2,8,3,6 };
	for (auto& item : vt)//引用的item可以修改，如果是非引用则只是值传递
	{
		cout << item++ << "  ";
	}
	cout << endl;

	for (const auto& item : vt)
	{
		cout << item << "  ";
	}
	cout << endl;
}

void myfor_test2(void)
{
	map<int, string> m{
		{1, "lucy"},{2, "lily"},{3, "tom"}
	};

	// 基于范围的for循环方式
	for (auto& it : m)
	{
		cout << "id: " << it.first << ", name: " << it.second << endl;
	}

	// 普通的for循环方式
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "id: " << it->first << ", name: " << it->second << endl;
	}
}