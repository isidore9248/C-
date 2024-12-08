#pragma once

class NewedPtr {
private:
	int value;
};

int GetPriority(void);
void processWidget(std::shared_ptr<NewedPtr> pNewedPtr, int priority);
void NewedPtr_test(void);
