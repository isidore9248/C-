#include "nonMemFri.h"
#include <iostream>
using namespace std;

namespace nonMemFri
{
	void NonMemFri::clearCache()const {  }
	void NonMemFri::clearHistory() const {}
	void NonMemFri::removeCookies()const {}

	void clearAll(NonMemFri& MF)
	{
		MF.clearCache();
		MF.clearHistory();
		MF.removeCookies();
	}
}