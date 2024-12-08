#pragma once

class FOBase
{
public:
	virtual void test(void) {}
};
class FOChild final :public FOBase
{
public:
	void test(void) override final {}
};
////以下操作不被允许
//class GrandChild :public Child	
////由于Child被final修饰，不可被继承
//{
//public:
//	void test(void) {}	
//	//Child类中test方法被final修饰，不可被继承
//};
