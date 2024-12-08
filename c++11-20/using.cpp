#include <iostream>
using namespace std;
#include <map>

void using_test1(void)
{
	//类似于typedef
	using mytype = int;
	mytype a = 5;
}

template <typename T>
using mymap = map<int, T>;
void using_test2(void)
{
	mymap<int> m1;
	m1.insert(make_pair(1, 3));

	for (auto it = m1.begin(); it != m1.end(); ++it)
	{
		cout << "it->first:" << it->first <<
			" " << "it->second:" << it->second
			<< endl;
	}
}