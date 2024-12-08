#pragma once
#include <iostream>
#include <vector>

void myiterator_test(void)
{
	std::vector<int> v1;
	auto it1 = v1.begin();		//iterator
	auto it2 = v1.cbegin();		//const_iterator
}