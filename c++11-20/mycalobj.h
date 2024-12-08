#pragma once

class calobj
{
public:
	int classmemfunc1(int x, int y) { return x + y; }
	static int classmemfunc2(int x, int y) { return x + y; }

};

//仿函数定义：
class CMyFunctor
{
public:
	void operator()(int x)
	{
		cout << x << endl;
	}
};



void calobj_test1(void);
void calobj_test2(void);
void calobj_test3(void);


void imitfunc_test1(void);
void calobj_test4(void);