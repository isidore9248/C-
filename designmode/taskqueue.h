#pragma once

class TaskQueue {
public:
	friend void tastQueue_test(void);

	TaskQueue(const TaskQueue&) = delete;
	TaskQueue& operator=(const TaskQueue&) = delete;

	static TaskQueue& Instance()
	{
		static TaskQueue instance;
		return instance;
	}

	template<typename FuncType, typename ...Args>
	void enqueue(FuncType&& func, Args&&... args);

private:
	TaskQueue() = default;
	std::queue<std::function<void()>> m_taskqueue;
	std::mutex m_mutex;
};

void tastQueue_test(void);
