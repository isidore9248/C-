#pragma once
//#include <algorithm>
class myswap
{
public:
	myswap() = default;
	myswap(const myswap& rhs);
	myswap& operator=(myswap  rhs);

	void swap(myswap& rhs);
private:
	int* pImpl = nullptr;
};

void swap(myswap& lhs, myswap& rhs);

namespace std
{
	// 声明swap模板函数的特化版本
	template<>
	void swap<myswap>(myswap& lhs, myswap& rhs);
}

void myswap_test1(void);

namespace MY_SWAP
{
	template<class T>
	class templated_myswap
	{
	public:
		void swap(templated_myswap& rhs);
	};

	template<typename T>
	void swap(templated_myswap<T>& lhs, templated_myswap<T>& rhs);
}

void myswap_test2(void);
