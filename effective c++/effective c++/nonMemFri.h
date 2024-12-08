#pragma once

namespace nonMemFri
{
	class NonMemFri
	{
	public:
		void clearCache() const;
		void clearHistory() const;
		void removeCookies() const;
	};
	void clearAll(NonMemFri& MF);
}