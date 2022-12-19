#include "vectorTools.h"

bool myComp(std::string a, std::string b)
{
	return a < b;
}

std::vector<std::string>& alphabeticallySort(std::vector<std::string>& a)
{
	std::size_t n = a.size();
	std::sort(a.begin(), a.end(), myComp);
	return a;
}