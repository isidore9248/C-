#pragma once
#include <iostream>
#include <mutex>
#include <string>

class mycall_once
{
public:
	//declaration
	static std::unique_ptr<mycall_once> instance;
	static std::once_flag once_flag;

	mycall_once(const mycall_once& c) = delete;
	mycall_once& operator=(const mycall_once& c) = delete;
	static mycall_once& getinstance()
	{
		//static mycall_once* calobj = nullptr;
		//if (!calobj) { calobj = new mycall_once; }
		//return *calobj;

		static mycall_once calobj;
		return calobj;
	}

	static mycall_once& getinstance_plus()
	{
		std::call_once(once_flag, [&]()
			{
				instance.reset(new mycall_once);
				cout << "creaing" << endl;
			}
		);
		return *instance;
	}

	void print(std::string str)
	{
		std::cout << /*__TIME__ <<*/ std::endl << str << std::endl;
	}

private:
	mycall_once() {}
};
//defination
std::once_flag mycall_once::once_flag;
std::unique_ptr<mycall_once> mycall_once::instance;

void callonce_func1(string str)
{
	mycall_once::getinstance_plus().print(str);
}

void mycall_once_test()
{
	thread t1(callonce_func1, "777");
	thread t2(callonce_func1, "888");
	t1.join();
	t2.join();
}