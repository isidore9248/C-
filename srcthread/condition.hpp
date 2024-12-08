#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex PC_mtx;

void Consumer()
{
	for (int i = 0; i < 10; ++i)
	{
		{
			std::unique_lock<std::mutex> g_mutex(PC_mtx);
			g_queue.push(i);
			g_cv.notify_one();
			std::cout << "Producer :" << i << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
}

void Producer()
{
	while (true)
	{
		std::unique_lock<std::mutex> g_mutex(PC_mtx);
		g_cv.wait(g_mutex, []
			{
				return!g_queue.empty();
			});

		int value = g_queue.front();
		g_queue.pop();

		std::cout << "Consumer :" << value << std::endl;
	}
}

void condition_test(void)
{
	std::thread t1(Producer);
	std::thread t2(Consumer);

	t1.join();
	t2.join();
}