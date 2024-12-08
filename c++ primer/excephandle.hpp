#pragma once

#include <iostream>

//异常的多态
class BaseException
{
public:
	virtual ~BaseException() {}
	virtual void printError() = 0;
};
class NullPointerException : public BaseException
{
public:
	~NullPointerException() {}
	void printError() { std::cout << "Null pointer exception" << std::endl; }
};
class OutOfRangeException : public BaseException
{
public:
	~OutOfRangeException() {}
	void printError() { std::cout << "Out of range exception" << std::endl; }
};
void ThrowError()
{
	throw NullPointerException();
	throw OutOfRangeException();
}

void CatchError_test1()
{
	try { ThrowError(); }
	catch (BaseException& e) { e.printError(); }
}

//函数可抛出的异常类型

//1、可以抛出任何类型的异常
void throw_type1(int type)
{
	if (type == 1) throw 2.14f; //抛出一个float类型的值
	else if (type == 2) throw "string exception"; //抛出一个string类型的值
	else if (type == 3)throw 10; //抛出一个int型的数值
}
//2、只能抛出特定类型(int)的异常
void throw_type2(void)throw(int) { throw 1; }
//3、无法抛出异常
void throw_type3(void)throw() {}

//自定义类型的异常
class MyException : public std::exception
{
public:
	MyException() {}
	MyException(std::string new_str) { m_str = new_str; }
	~MyException() {}
	virtual const char* what() const throw()	//防止父类在子类之前抛出标准异常
	{
		return m_str.c_str();
	}
private:
	std::string m_str;
};
void MyException_test()
{
	try { throw MyException("custom exception"); }
	catch (exception& e) { std::cout << e.what(); }
}