#include "Nameinher.h"

void Nameinher_test1(void)
{
	Nameinher_publicDerived obj;
	obj.mf1();	//Nameinher_publicDerived::mf1()
	obj.mf1(1);	//Nameinher_Base::mf1(int)
	obj.mf2();
	obj.mf3();	//Nameinher_publicDerived::mf3()
	obj.mf3(3.2);	//Nameinher_Base::mf3(double)
}

void Nameinher_test2(void)
{
	Nameinher_privateDerived obj;
	obj.mf1();
}