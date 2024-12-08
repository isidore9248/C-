#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
using namespace std;

int a = 0;
mutex mtx;
void mutex_func(void) {
	for (int i = 0; i < 10000; i++) { mtx.lock(); a++; mtx.unlock(); }
}

void mutex_test(void)
{
	thread t1(mutex_func);
	thread t2(mutex_func);
	t1.join();
	t2.join();
	cout << "a = " << a << endl;
}