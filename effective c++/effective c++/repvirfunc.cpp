#include <iostream>
#include "repvirfunc.h"

int NVI::healthvalue() const
{
	//事前工作，比如检查参数、锁定互斥锁、制造日志运转记录项
	int retVal = dohealthvalue();
	//事后工作，比如释放互斥锁、关闭日志文件
	return retVal;
}

int NVI::dohealthvalue() const { return 0; }

int FuncPtr::healthValue() const
{
	return healthFunc(*this);
}

int defaulthealthvalue(const FuncPtr& f)
{
	return 0;
}

int CallHealthQuick(const FuncPtr& f) { std::cout << "CallHealthQuick" << std::endl; return 0; }
int CallHealthSlow(const FuncPtr& f) { std::cout << "CallHealthSlow" << std::endl; return 0; }

void repvirfunc_FuncPtrtest(void)
{
	DerivedFuncPtr dfp1(CallHealthQuick);
	DerivedFuncPtr dfp2(CallHealthSlow);
	int  dfp1_value = dfp1.healthValue();
	int  dfp2_value = dfp2.healthValue();
}