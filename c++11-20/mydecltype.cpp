#include <iostream>
using namespace std;
#include <list>

const int func_cint() { return 1; }          // 返回值为 const int

class mydecltypeTest
{
public:
	int num;
};

void decltype_test1(void)
{
	//返回值为纯右值,所以const被忽略
	decltype(func_cint())  d = 0;

	const mydecltypeTest obj;

	//带有括号的表达式,表达式是一个左值,或者被括号()包围,推导出的是引用

	//a : int
	decltype(obj.num) a = 0;
	//b : const int&
	decltype((obj.num)) b = a;

	//加法表达式
	int n = 0, m = 0;
	//c : int
	decltype(n + m) c = 0;  // n+m 不可取地址,所以不是左值
	//e : int&
	decltype(n = n + m) e = n;   //将结果赋值给n,可以取地址,是左值
}

template<class T>
class Container
{
public:
	void func(T& c)
	{
		for (m_it = c.begin(); m_it != c.end(); ++m_it)
		{
			cout << *m_it << " ";
		}
		cout << endl;
	}
private:
	//由于auto不能用于类的非静态成员变量，所以使用decltype
	//若只有 T 则不能表达类还是对象，T()表示对象
	decltype(T().begin()) m_it;    //根据decltype确定迭代器类型
};
void decltype_test2(void)
{
	list<int> ls{ 1, 2, 3, 4, 5 };    //创建list对象
	Container<list<int> > Con;  //创建Container的对象Con
	Con.func(ls);
}