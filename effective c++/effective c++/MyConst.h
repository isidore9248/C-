#pragma once
#include "HeadFile.h"

//const在指针中的使用
void MyConst_test(void);

//const在函数中的使用
class Rational { };
const Rational operator*(const Rational& lhs, const Rational& rhs);
void rational_test(void);

//const在类的成员函数中的使用
class TextBlock
{
public:
	TextBlock(string str) :text(str) {}
	~TextBlock() {}

	//此处前面的const是由于后面有const，后面的const避免修改，自然有了前面的const
	//对于是否有const形成的重构，尽量使用non-const调用const版本，避免出现错误
	const char& operator[](size_t position)const;
	char operator[](size_t position);

	size_t lenth()const;

private:
	char* ptext;
	string text;
	static int a;	//declaration

	//mutable 可以使用在const函数中，表示该函数对类的成员变量进行修改，但不影响const性质
	mutable size_t textLenth;
	mutable bool lenthIsValid;
};

void TextBlock_test(void);
