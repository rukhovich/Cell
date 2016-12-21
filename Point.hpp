#include "Transcendental.hpp"
#include <utility>
#include <string>

#pragma once

using std::pair;
using std::string;

class Point
{
	Trans x, y;	
public:
	Point(int a = 0, int b = 0);
	Point(Trans a, Trans b);
	Point(int x_a, int x_b, int y_a, int y_b);
	Point operator + (Point t);
	Point operator - (Point t);
	Point operator * (int k);
	string str();
	pair <float, float> value();
};
