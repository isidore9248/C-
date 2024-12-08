#pragma once

class repvirfuncBase
{
public:
	virtual int healthvalue()const;
};

//1、non-virtual interface (NVI)
class NVI
{
public:
	int healthvalue()const;
private:
	virtual int dohealthvalue()const;
};

//2、funcptr
class FuncPtr;
int defaulthealthvalue(const FuncPtr& f);
class FuncPtr
{
public:
	using HealthCalcFunc = int (*)(const FuncPtr& f);
	explicit FuncPtr(HealthCalcFunc f = defaulthealthvalue) :healthFunc(f) {}
	int healthValue()const;
private:
	HealthCalcFunc healthFunc;
};

class DerivedFuncPtr :public FuncPtr
{
public:
	explicit DerivedFuncPtr(HealthCalcFunc hcf = defaulthealthvalue) :FuncPtr(hcf) {}
};

int CallHealthQuick(const FuncPtr& f);
int CallHealthSlow(const FuncPtr& f);

void repvirfunc_FuncPtrtest(void);

//3、