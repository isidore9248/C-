#include <iostream>
using namespace std;
#include <memory>
#include "pimpl.h"
class MyPimple::MyPimple_Impl
{
public:
	explicit MyPimple_Impl(int val) :m_val(val) {}
	auto getMval() { return m_val; }
private:
	int m_val;
};

MyPimple::MyPimple(int val) :pImpl(std::make_unique<MyPimple_Impl>(val)) {}

MyPimple::~MyPimple() = default;

auto MyPimple::getOrientation() { return pImpl->getMval(); }