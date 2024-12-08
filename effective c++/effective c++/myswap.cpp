#include <algorithm>
#include <iostream>
#include "myswap.h"

void myswap::swap(myswap& rhs)
{
	using std::swap;
	swap(pImpl, rhs.pImpl);
}

myswap::myswap(const myswap& rhs)
{
	if (rhs.pImpl == nullptr)
	{
		pImpl = nullptr;
	}
	else
	{
		pImpl = new int;
		*pImpl = *rhs.pImpl;
	}
}

myswap& myswap::operator=(myswap rhs)
{
	this->swap(rhs);
	return *this;
}

void swap(myswap& lhs, myswap& rhs) { lhs.swap(rhs); }

//标准库内模板全特化
namespace std
{
	template<>
	void swap<myswap>(myswap& lhs, myswap& rhs)
	{
		lhs.swap(rhs);
	}
}

void myswap_test1(void)
{
	myswap a, b;
	using std::swap;
	swap(a, b);			//调用	void swap(myswap& lhs, myswap& rhs)
	std::swap(a, b);	//调用std内的swap模板特化
}

namespace MY_SWAP
{
	template<class T>
	void templated_myswap<T>::swap(templated_myswap& rhs)
	{ /*此处省略*/
	}

	template<typename T>
	void swap(templated_myswap<T>& lhs, templated_myswap<T>& rhs)
	{
		lhs.swap(rhs);
	}
}

void myswap_test2(void)
{
	using namespace MY_SWAP;
	templated_myswap<int> a, b;
	swap(a, b);
}