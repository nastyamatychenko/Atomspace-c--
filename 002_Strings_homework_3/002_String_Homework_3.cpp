#include<iostream>
#include "String.h"

using namespace std;


bool str_contains(const char *strB, const char *strA)
{
	do
	{
		if (!strA)
		{
			if (*strB == *strA)
			{
				strB++; strA++;
			}
		}
		else
		{
			return true;
		}
	} while (*strB);

	return false;
}

const char *strstr(const char *strB, const char *strA)
{
	while (*strB) {
		if (!str_contains(strB, strA)) return nullptr;
		strB++;
	};

	return strB;
}

int main()
{
	char s1[] = "Hello world", s2[] = "wo";

	if (strstr(s1, s2)) std::cout << "contains";
	else std::cout << "not contains";

	return 0;
}