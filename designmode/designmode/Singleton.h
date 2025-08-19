#pragma once
#include <iostream>
#include <mutex>
#include <atomic>
#include <queue>
#include <functional>
//懒汉模式
//使用的时候才创建对象
class SlackerSingleton
{
public:
	SlackerSingleton(const SlackerSingleton& obj) = delete;
	SlackerSingleton& operator=(const SlackerSingleton& obj) = delete;
	//静态函数只能使用静态变量,不能使用this指针
	static SlackerSingleton* GetPtrInstance()
	{
		SlackerSingleton* obj = m_obj_atomic.load();
		//双重检查锁定,在多线程下当实例对象被创建出来以后可以保证线程安全,同时提高效率
		if (obj == nullptr)
		{
			std::lock_guard<std::mutex> m_lock(m_mutex);
			obj = m_obj_atomic.load();
			if (obj == nullptr)
			{
				obj = new SlackerSingleton;
				m_obj_atomic.store(obj);
			}
		}
		return obj;
	}
	//c++11支持 且 没有线程安全问题
	static SlackerSingleton& GetRefInstance()
	{
		static SlackerSingleton obj;
		return obj;
	}
	void print() const {}
private:
	SlackerSingleton() = default;
	//static SlackerSingleton* m_obj;
	static std::atomic<SlackerSingleton*> m_obj_atomic;
	static std::mutex m_mutex;
};

//饿汉模式
class HungrymanSingleton
{
public:
	HungrymanSingleton(const HungrymanSingleton& obj) = delete;
	HungrymanSingleton& operator=(const HungrymanSingleton& obj) = delete;
	static HungrymanSingleton* GetPtrInstance()
	{
		return m_obj;
	}
	void print() const {}
private:
	HungrymanSingleton() = default;
	static HungrymanSingleton* m_obj;
};
