#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
using namespace std;

mutex deadlock_m1, deadlock_m2;
void deadlock_func1(void)
{
	deadlock_m1.lock();
	deadlock_m2.lock();
	deadlock_m1.unlock();
	deadlock_m2.unlock();
}
void deadlock_func2(void)
{
	deadlock_m2.lock();
	deadlock_m1.lock();
	deadlock_m2.unlock();
	deadlock_m1.unlock();
}

void deadlock_test(void)
{
	thread t1(deadlock_func1);
	thread t2(deadlock_func2);
	t1.join();
	t2.join();

	cout << "over" << endl;
}