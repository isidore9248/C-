#pragma once

namespace Parent
{
	namespace Child1
	{
		void foo();
	}
	inline namespace Child2
	{
		void foo();
	}

}


void mynamespace_test(void);


namespace A::B::C
{
	int foo(void) ;
}