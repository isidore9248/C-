#pragma once

class Filesystem
{
public:
	size_t numDisks() const { return m_disk; };
	static Filesystem& tfs()	//该函数也可以放在类中，一定使用static
	{
		static Filesystem fs;	//并且全局只能有一个该对象
		return fs;
	}

private:
	Filesystem() {}
	size_t m_disk;
};

class Directory
{
public:
	Directory();
};