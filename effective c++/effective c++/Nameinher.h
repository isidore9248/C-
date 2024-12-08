#pragma once

/// <summary> 基类的函数个数
/// </summary>
/// mf1: 2 func
/// mf2: 1 func
/// mf3: 2 func
class Nameinher_publicBase
{
public:
	virtual void mf1() = 0;
	virtual void mf1(int) {}
	virtual void mf2() {}
	void mf3() {}
	void mf3(double) {}
};

/// <summary> 派生类的函数个数
/// </summary>
/// mf1: 2 func
/// mf2: 0 func
/// mf3: 2 func
/// mf4: 1 func
class Nameinher_publicDerived : public Nameinher_publicBase
{
public:
	using Nameinher_publicBase::mf1;
	using Nameinher_publicBase::mf3;

	virtual void mf1() {}
	void mf3() {}
	void mf4();
};

void Nameinher_test1(void);

class Nameinher_privateBase
{
public:
	virtual void mf1() {}
	virtual void mf1(int) {}
};
class Nameinher_privateDerived : private Nameinher_privateBase
{
public:
	void mf1() { Nameinher_privateBase::mf1(); }
};

void Nameinher_test2(void);