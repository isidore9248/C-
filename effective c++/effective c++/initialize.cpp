#include <iostream>
using namespace std;

#include "initialize.h"

Directory::Directory()
{
	size_t numDisks = Filesystem::tfs().numDisks();
}