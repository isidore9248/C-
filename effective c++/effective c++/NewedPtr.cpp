#include <iostream>
#include <memory>
#include "NewedPtr.h"

int GetPriority(void)
{
	return 1;
}

void processWidget(std::shared_ptr<NewedPtr> pNewedPtr, int priority) {  }

void NewedPtr_test(void)
{
	std::shared_ptr<NewedPtr> pNewedPtr(new NewedPtr);
	processWidget(pNewedPtr, GetPriority());
}