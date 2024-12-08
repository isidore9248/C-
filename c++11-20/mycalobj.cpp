#include <iostream>
using namespace std;
#include "mycalobj.h"

//1、普通函数
int calobj_commonfunc(int x, int y) { return x + y; }
//c:
typedef int(*cfunc1)(int, int);
//cpp:
using cppfunc1 = int(*)(int, int);
void calobj_test1(void)
{
	cfunc1 c1 = calobj_commonfunc;
	cout << c1(2, 45) << endl;
	cppfunc1 cpp1 = calobj_commonfunc;
	cout << cpp1(23, 23) << endl;
}

//2、类成员函数

//c:
typedef int (calobj::* cfunc2)(int, int);
//cpp:
using cppfunc2 = int (calobj::*)(int, int);
void calobj_test2(void)
{
	calobj cal1;
	cppfunc2 cpp2 = &calobj::classmemfunc1;
	cout << (cal1.*cpp2)(3, 5) << endl;
}

//3、类静态函数
//类的static函数属于类,不属于对象,
//当作全局函数对待,但需要创建对象

//c:
typedef int(*cfunc3)(int, int);
//cpp:
using cppfun3 = int(*)(int, int);
void calobj_test3(void)
{
	calobj cal2;
	cppfun3 cpp3 = calobj::classmemfunc2;
	cout << cpp3(2, 5) << endl;
}

//4、仿函数
void imitfunc_test1(void)
{
	CMyFunctor C1;
	C1(16);	//调用格式
}
//c:
typedef void (CMyFunctor::* cfunc4)(int);
//cpp:
using cppfunc4 = void(CMyFunctor::*)(int);
void calobj_test4(void)
{
	CMyFunctor C2;
	//调用格式1
	cppfunc4 cpp4 = &CMyFunctor::operator();
	(C2.*cpp4)(6);
	//调用格式2
	C2(3);
}