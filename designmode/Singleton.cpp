#include "Singleton.h"

//SlackerSingleton* SlackerSingleton::m_obj = nullptr;
std::atomic<SlackerSingleton*> SlackerSingleton::m_obj_atomic;
std::mutex SlackerSingleton::m_mutex;

HungrymanSingleton* HungrymanSingleton::m_obj = new HungrymanSingleton;