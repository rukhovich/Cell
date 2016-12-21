#include <string>
#include <math.h>
#include <utility>

#pragma once

using std::string;
using std::to_string;

class Trans
{
	int a{0}, b{0};
public:
	Trans(int _a = 0, int _b = 0);
	Trans operator + (Trans y);
	Trans operator - (Trans y);
	Trans operator * (int k);
	string str();
	float value();
};
