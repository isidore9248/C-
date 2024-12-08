#include "MyConst.h"
#include "HeadFile.h"

void MyConst_test(void)
{
	vector<int> vec = { 4, 23, 1 };
	//T * const iter
	const std::vector<int>::iterator iter = vec.begin();

	//const T * citer
	std::vector<int>::const_iterator citer = vec.cbegin();
}

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return lhs * rhs;
}

void rational_test(void)
{
	Rational a, b, c;
	//(a* b) = c; // 避免用作左值
	//if ((a * b) = c) {} // 检查判断是否正确
}

int TextBlock::a = 10;

void print(const TextBlock& tb) { cout << tb[0] << endl; }
void TextBlock_test(void)
{
	TextBlock tb("hello");
	const TextBlock ctb("world");

	cout << tb[0] << endl;
	cout << ctb[0] << endl;

	print(tb);
	print(ctb);
}

size_t TextBlock::lenth()const
{
	if (!lenthIsValid)
	{
		textLenth = text.length();
		lenthIsValid = true;
	}
	return textLenth;
}

const char& TextBlock::operator[](size_t position)const
{
	return ptext[position];
}

char TextBlock::operator[](size_t position)
{
	return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
}