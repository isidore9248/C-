#include "construct.h"

#include <iostream>
using namespace std;
#include <string>

NamedObject::NamedObject(string& name, const int& value)
	:namevalue(name), objectvalue(value)
{
}

void NamedObject::operator=(const NamedObject& other)
{
	namevalue = other.namevalue;
}

void construct_test1(void)
{
	string newdog("Persephone");
	string olddog("Satch");

	NamedObject p(newdog, 1);
	NamedObject s(olddog, 23);

	p = s;		//需要手动写拷贝赋值
}

void copy_test1(void)
{
	Uncopyable U1;
	Uncopyable U2;
	//Uncopyable U3(U1);	//编译错误，Uncopyable类没有拷贝构造函数
	//Uncopyable U4 = U1;	//编译错误，Uncopyable类没有拷贝构造函数
}