#include <iostream>
#include <coroutine>  // C++20 协程核心支持
#include <thread>
#include <chrono>

class intreader
{
public:
	bool await_ready()
	{
		return false;
	}
	bool await_suspend(std::coroutine_handle<> h)
	{
		std::thread thread([this, h]() mutable
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				value = 1;
				h.resume();
			}
		);
		thread.detach();
		return true;
	}
	int await_resume()
	{
		return value;
	}
private:
	int value{};
};

class Task
{
public:
	Task(std::shared_ptr<int> value_) : value(value_)
	{
	}
	int GetValue() const
	{
		return *value;
	}
private:
	std::shared_ptr<int> value;

public:
	class promise_type
	{
	public:
		promise_type() :value(std::make_shared<int>(0))
		{
		}
		//创建协程的返回值对象，即promise_type外的Task类对象
		Task get_return_object()
		{
			return Task{ value };
		}
		std::suspend_never initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void unhandled_exception() {}
		//void return_void() {}
		void return_value(int value_)
		{
			*value = value_;
		}
	private:
		std::shared_ptr<int> value;
	};
};

Task foo()
{
	intreader i1;
	int sum = co_await i1;

	intreader i2;
	sum += co_await i2;

	intreader i3;
	sum += co_await i3;

	co_return sum;
}

int main()
{
	auto task = foo();  // 必须保存返回值

	// 等待协程完成
	while (task.GetValue() == 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	std::cout << "Final sum: " << task.GetValue() << std::endl;
	return 0;
}