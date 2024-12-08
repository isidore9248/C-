#pragma once

//若想声明一个抽象类，但是除了析构函数没有别的函数
//那么需要将析构函数定义为纯虚函数，并在类外实现空定义

class PureVirtualFunc
{
public:
	virtual ~PureVirtualFunc() = 0;
};
