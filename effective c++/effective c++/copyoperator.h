#pragma once

class copyoperator
{
public:
	void swap(copyoperator& rhs)
	{
		copyoperator temp;
		temp.value = rhs.value;
		temp.p = rhs.p;
		rhs.value = value;
		rhs.p = p;
		value = temp.value;
		p = temp.p;
	}

	/// <note> </note>这里需要判断一下两个指针是否指向同一片内存，防止指针被释放后再次使用
	//copyoperator& operator=(const copyoperator& rhs)
	//{
	//	if (&rhs == this) { return *this; }		//此语句影响运行效率
	//	delete p;
	//	p = new int(rhs.value);
	//	value = rhs.value;
	//	return *this;
	//}

	/// <summary> </summary>		拷贝赋值运算符优化
	/// <param name="rhs"></param>	1、这里没有使用const是因为在函数体内会使用swap函数
	///								2、没有使用引用：使用引用后还要使用一次拷贝构造，所以直接在调用函数的时候进行
	/// <returns></returns>			返回值尽量是引用类型
	/// <note> </note>				swap函数兼容了赋值的两个变量是否为同一变量，即使是也并不很耽误效率
	copyoperator& operator=(copyoperator rhs)
	{
		swap(rhs);
		return *this;
	}
private:
	int value;
	int* p;
};

class newcopy : public copyoperator
{
public:
	newcopy() {}
	newcopy(const newcopy& rhs) :copyoperator(rhs), m_name(rhs.m_name) {}
	newcopy& operator=(const newcopy& rhs)
	{
		copyoperator::operator=(rhs);
		m_name = rhs.m_name;
		return *this;
	}
private:
	string m_name;
};