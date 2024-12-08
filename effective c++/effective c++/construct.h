#pragma once
#include <iostream>
//using namespace std;
#include <string>
using std::string;

class NamedObject
{
public:
	NamedObject(string& name, const int& value);

	void operator=(const NamedObject& other);
private:
	string& namevalue;
	const int objectvalue;
};

void construct_test1(void);

//不希望编译器自己使用某些函数，而是希望自己调用
//如	拷贝构造函数，赋值运算符等

class Uncopyable
{
public:
	Uncopyable() {}
	~Uncopyable() {}

	//c++11中，禁止拷贝构造函数和赋值运算符
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator=(const Uncopyable&) = delete;
};

void copy_test1(void);