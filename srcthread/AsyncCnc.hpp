#pragma once

#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>
#include <chrono>
#include <future>

int Async_func(void) { return 4; }
void Async_test1(void)
{
	//此处必须是一个有返回值的函数，不可以是void
	std::future<int> future_result = std::async(std::launch::async, Async_func);
	int result = future_result.get();	//获取该可调用对象的返回值
	std::cout << result << endl;
}

void PackagedTask_test(void)
{
	std::packaged_task<int()> task(Async_func);
	//得到future类型的对象
	auto future_result = task.get_future();		//std::future<ret_type> val_name
	std::thread t1(std::move(task));
	t1.join();
	int result = future_result.get();
	std::cout << result << endl;
}

void Promise_func(std::promise<int>& f, int setvalue) { f.set_value(setvalue); }
void Promise_test(void)
{
	std::promise<int> pobj;
	std::future<int> future_result = pobj.get_future();
	std::thread t1(Promise_func, std::ref(pobj), 89);
	t1.join();
	std::cout << future_result.get() << std::endl;
}

void Async_TotalTest(void)
{
	Async_test1();
	PackagedTask_test();
	Promise_test();
}