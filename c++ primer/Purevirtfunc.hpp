#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base() = 0;
	virtual void doSomething() = 0;
};
class Derived : public Base
{
public:
	~Derived() {}
	void doSomething() { cout << "Derived::doSomething()" << endl; }
};