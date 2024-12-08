#include <iostream>
using namespace std;
#include <map>

void auto_test1(void)
{
	/*****1、用auto声明多个变量，遵循自左到右的顺序*****/
	int n = 5;
	//auto = int , m : int
	auto* pn = &n, m = 10;	//若m=10.0则编译失败

	/*****2、auto会使用限定更宽的类型*****/
	auto i = true ? 5 : 8.0;	//auto：double
}

void auto_test2(void)
{
	/*****3、使用auto初始化时,目标是引用则引用属性会被忽略*****/
	int i = 5;
	int& j = i;
	//m: int
	auto m = j;
}

void auto_test3(void)
{
	/*****
	4、	当变量不是指针或者引用类型时
	推导的结果中不会保留const、volatile关键字
		当变量是指针或者引用类型时
	推导的结果中会保留const、volatile关键字
	*****/

	auto a = 3;	//auto = int

	/*以下为有const修饰的例子*/
	int temp = 666;

	const auto a1 = temp;		//auto = int

	auto a2 = a1;
	//a1 : const int
	//因为没有引用或指针，所以：auto = int	a2 : int

	const auto& a3 = temp;
	//由于有引用	a3 : const int &

	auto& a4 = a3;
	//a3 : const int &
	//a4 : const int &

	/*****5、如果目标是一个数组，则auto推导为对应类型指针*****/
	int i[5];
	auto m = i;	//auto : int*
}

void auto_test4(void)
{
	//容器遍历
	map<int, string> mp;
	mp.insert(make_pair(1, "5"));
	mp.insert(make_pair(2, "2c"));
	mp.insert(make_pair(3, "asd"));
	//map<int, string> ::iterator it = mp.begin();
	auto it = mp.begin();//将map<int, string> ::iterator 替换为auto
	for (; it != mp.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
}