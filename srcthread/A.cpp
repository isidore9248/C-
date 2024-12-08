#include <iostream>
#include <thread>
#include <string>
#include <memory>
using namespace std;
#include "A.h"

void A::foo(void) { std::cout << "A::foo()" << std::endl; }

void A_test(void)
{
	shared_ptr<A> pta = make_shared<A>();
	thread t1(&A::foo, pta);
	if (t1.joinable()) { t1.join(); }
}