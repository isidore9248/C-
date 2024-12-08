#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
using namespace std;

mutex ExclusivePkg_m1;
void ExclusivePkg_func1(int& val)
{
	for (int i = 0; i < 100; i++) { lock_guard<mutex> lg(ExclusivePkg_m1); val += 1; }
}
void ExclusivePkg_func2(int& val)
{
	for (int i = 0; i < 100; i++) { lock_guard<mutex> lg(ExclusivePkg_m1); val += 1; }
}

void ExclusivePkg_test1(void)
{
	int val = 0;
	thread t1(ExclusivePkg_func1, ref(val));
	thread t2(ExclusivePkg_func2, ref(val));
	t1.join();
	t2.join();

	cout << "val = " << val << endl;
}

timed_mutex ExclusivePkg_tm;
void ExclusivePkg_func3(int& val)
{
	unique_lock<timed_mutex> ul(ExclusivePkg_tm, defer_lock);
	//如果获取不到锁，则等待5秒，超时直接退出
	ul.try_lock_for(chrono::seconds(5));
	for (int i = 0; i < 2; i++) { val++; }
}

void ExclusivePkg_test2(void)
{
	int val = 2;
	thread t3(ExclusivePkg_func3, ref(val));
	t3.join();
	cout << "val = " << val << endl;
}