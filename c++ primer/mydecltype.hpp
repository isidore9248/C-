#pragma once

template<typename T>
T mydeclvalfunc(const T& t)
{
	return t;
}

void mydeclval_test1(void)
{
	decltype(mydeclvalfunc(1))  x = 0;
	decltype(mydeclvalfunc(1))  y;

	int i = 5, j = 34, k = 123l;
	decltype((i)) p = j;	//p的类型是 int & ,在此处绑定为j
}