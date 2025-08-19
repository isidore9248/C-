#include <iostream>
#include <memory>
#include "factory.h"

void ProductA::Show()
{
	std::cout << "ProductA::Show()" << std::endl;
}

void ProductB::Show()
{
	std::cout << "ProductB::Show()" << std::endl;
}

void Simplefactory_test(void)
{
	std::shared_ptr<AbstractProduct> ProPtr(SimpleFactory::CreatProduct(SimpleFactory::enum_type::A));
	ProPtr->Show();
	ProPtr.reset(SimpleFactory::CreatProduct(SimpleFactory::enum_type::B));
	ProPtr->Show();
}

AbstractProduct* FactoryA::CreateProduct()
{
	return new ProductA;
}

AbstractProduct* FactoryB::CreateProduct()
{
	return new ProductB;
}

void factory_test(void)
{
	std::shared_ptr<AbstractFactory> AbstractPtr(new FactoryB);
	std::shared_ptr<AbstractProduct> ProductPtr(AbstractPtr->CreateProduct());
	ProductPtr->Show();
}