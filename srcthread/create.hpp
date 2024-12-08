#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>
using namespace std;

void thread_func1(string msg)
{
	cout << msg << endl;
}

void thread_func2(int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << i << endl;
	}
	cout << endl;
}

void creat_test(void)
{
	//创建线程
	thread t1(thread_func1, "hello thread");
	thread t2(thread_func2, 10000);
	if (t1.joinable() && t2.joinable())
	{
		//等待线程结束
		t1.join();
		t2.join();
		//分离主线程和子线程
		//t1.detach();
	}
}

void thread_func3(int& x) { x += 1; }
void creat_reftest(void)
{
	int a = 4;
	thread t3(thread_func3, ref(a));
	cout << a << endl;
	if (t3.joinable()) { t3.join(); }
}