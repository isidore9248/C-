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
#include <atomic>

#include "create.hpp"
#include "A.h"
#include "mymutex.hpp"
#include "deadlock.hpp"
#include "ExclusivePkg.hpp"
#include "mycallonce.hpp"
#include "condition.hpp"
#include "threadpool.h"
#include "AsyncCnc.hpp"
#include "atomicOper.hpp"

int main()
{
	creat_test();
	creat_reftest();
	A_test();
	mutex_test();
	deadlock_test();
	ExclusivePkg_test1();
	ExclusivePkg_test2();
	mycall_once_test();
	condition_test();
	threadpool_test();
	Async_TotalTest();
	atomicOper_test();
	return 0;
}