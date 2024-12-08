#pragma once

//委托构造函数-----start
class ConstructorTest
{
public:
    ConstructorTest() {};
    ConstructorTest(int max):m_max(max > 0 ? max : 100)
    {
    }

    //使用委托构造函数后，将初始化责任转移给另一个构造函数
    //所以只能在函数主体进行赋值操作
    ConstructorTest(int max, int min): ConstructorTest(max)
    {
        m_min = min > 0 && min < m_max ? min : 1;
    }

    ConstructorTest(int max, int min, int mid) :ConstructorTest(max, min)
    {
        this->m_middle = mid < max && mid > min ? mid : 50;
    }

private:
    int m_min;
    int m_max;
    int m_middle;
};
//委托构造函数-----end



//继承构造函数-----start
class ConBase
{
public:
    ConBase(int i) :m_i(i) {}
    ConBase(int i, double j) :m_i(i), m_j(j) {}
    ConBase(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    void func() { cout << "ConBase::func()" << endl; }
    void func(int) { cout << "ConBase::func(int)" << endl; }

//private:
    int m_i;
    double m_j;
    string m_k;
};
class ConChild : public ConBase
{
public:
    using ConBase::ConBase; 
    using ConBase::func;    
    //可以省略以下部分代码
    /*Child(int i) :ConBase(i) {}
    Child(int i, double j) :ConBase(i, j) {}
    Child(int i, double j, string k) :ConBase(i, j, k) {}*/

    void func(int, double) { cout << "ConChild::func(int,double)" << endl; }
};

void constructor_test(void);
//继承构造函数-----end