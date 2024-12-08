#include <iostream>
using namespace std;
#include <functional>

/*----------function----start-------------*/
//1、绑定一个普通函数
int function_func1(int a, int b)
{
	return a + b;
}
void function_bind_test1(void)
{
	function<int(int, int)> func1 = function_func1;
	cout << func1(3, 7) << endl;
}

//2、绑定以静态类成员函数
class func_bind_T1
{
public:
	static int sub(int a, int b)
	{
		cout << a << " - " << b << " = " << a - b << endl;
		return a - b;
	}
};
void function_bind_test2(void)
{
	function<int(int, int)> func2 = func_bind_T1::sub;
	func2(4, 7);
}

//3、绑定一个仿函数
class func_bind_T2
{
public:
	int operator()(int a, int b)
	{
		cout << a << " * " << b << " = " << a * b << endl;
		return a * b;
	}
};
void function_bind_test3(void)
{
	func_bind_T2 t2;
	function<int(int, int)> func3 = t2;
	func3(3, 9);
}

//4、回调函数
class func_bind_T3
{
public:
	func_bind_T3(const function<void()>& f) :
		callback(f) {}

	void notify()
	{
		callback();
	}
private:
	function<void()> callback;
};
void function_bind_test4(void)
{
	func_bind_T3 t3(function_bind_test3);
	t3.notify();
}

/*----------function----end-------------*/

/*----------bind----start-------------*/

void func_bind_out(int x, int y)
{
	cout << x << " " << y << endl;
}
void function_bind_test5(void)
{
	// 使用绑定器绑定可调用对象和参数, 并调用得到的仿函数
	bind(func_bind_out, 1, 2)();
	bind(func_bind_out, placeholders::_1, 2)(10);

	// 调用时第一个参数没有被使用
	bind(func_bind_out, 2, placeholders::_2)(10, 20);
}

class func_bind_T4
{
public:
	void output(int x, int y)
	{
		cout << "x: " << x << ", y: " << y << endl;
	}
	int m_number = 100;
};
void function_bind_test6(void)
{
	func_bind_T4 t4;
}