#include <queue>
#include <functional>
#include <mutex>
#include <thread>
#include <iostream>
#include "taskqueue.h"

template<typename FuncType, typename ...Args>
void TaskQueue::enqueue(FuncType&& func, Args&&... args)
{
	std::function<void()> task =
		std::bind(std::forward<FuncType>(func), std::forward<Args>(args)...);

	m_taskqueue.emplace(std::move(task));	//把task插入末尾，避免复制和移动
}

void dosomething(int i)
{
	std::cout << "task " << i << " is running" << std::endl;
	std::cout << "task " << i << " is done" << std::endl;
}

void tastQueue_test(void)
{
	std::thread producer(
		[]
		{
			for (int i = 0; i < 10; i++)
			{
				std::lock_guard<std::mutex> lock(TaskQueue::Instance().m_mutex);
				TaskQueue::Instance().enqueue(dosomething, i);
				std::this_thread::sleep_for(std::chrono::milliseconds(300));
			}
		}
	);

	std::thread consumer(
		[]
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			{
				std::lock_guard<std::mutex> lock1(TaskQueue::Instance().m_mutex);
				while (!TaskQueue::Instance().m_taskqueue.empty())
				{
					std::function<void()> run_task = std::move(TaskQueue::Instance().m_taskqueue.front());
					TaskQueue::Instance().m_taskqueue.pop();
					run_task();
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}
			}
		}
	);

	producer.join();
	consumer.join();
}