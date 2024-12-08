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

std::atomic<int> atomicOper_sharedvalue = 0;
void atomicOper_func(void)
{
	for (int i = 0; i < 1000000; i++) { atomicOper_sharedvalue++; }
}
void atomicOper_test(void)
{
	std::thread t1(atomicOper_func);
	std::thread t2(atomicOper_func);
	t1.join();
	t2.join();
	std::cout << "atomicOper_sharedvalue = " << atomicOper_sharedvalue << std::endl;
}