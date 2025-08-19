#pragma once

class AbstractProduct
{
public:
	virtual void Show() = 0;
	virtual ~AbstractProduct() {}
};

class ProductA : public AbstractProduct
{
public:
	virtual void Show() override;
};

class ProductB : public AbstractProduct {
public:
	virtual void Show() override;
};

/// <summary></summary>	有且仅有一个工厂类
class SimpleFactory
{
public:
	//如果有扩充，则很难维护，所以最好不要扩充
	enum class enum_type :char { A, B };
	static AbstractProduct* CreatProduct(enum_type type)
	{
		AbstractProduct* RetPtr = nullptr;
		switch (type)
		{
		case SimpleFactory::enum_type::A:
			RetPtr = new ProductA;
			break;
		case SimpleFactory::enum_type::B:
			RetPtr = new ProductB;
			break;
		default:
			break;
		}
		return RetPtr;
	}
};

void Simplefactory_test(void);

/*-----------简单工厂模式------end-----------*/

/*-----------工厂模式------start-----------*/

class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
	virtual ~AbstractFactory() {}
};

class FactoryA :public AbstractFactory
{
public:
	AbstractProduct* CreateProduct() override;
	virtual ~FactoryA() { std::cout << "FactoryA Destructor" << std::endl; }
};

class FactoryB :public AbstractFactory
{
public:
	AbstractProduct* CreateProduct() override;
	virtual ~FactoryB() { std::cout << "FactoryB Destructor" << std::endl; }
};

void factory_test(void);

/*-----------工厂模式------end-----------*/
