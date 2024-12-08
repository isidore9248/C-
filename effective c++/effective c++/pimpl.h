#pragma	once

class MyPimple
{
public:
	explicit MyPimple(int val);
	~MyPimple();
	auto getOrientation();

private:
	class MyPimple_Impl;
	std::unique_ptr<MyPimple_Impl> pImpl;
};