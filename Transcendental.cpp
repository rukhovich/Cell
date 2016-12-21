#include "Transcendental.hpp"

Trans::Trans(int _a, int _b)
{
	a = _a;
	b = _b;
}
Trans Trans::operator + (Trans y)
{
	return Trans(a + y.a, b + y.b);
}
Trans Trans::operator - (Trans y)
{
	return Trans(a - y.a, b - y.b);
}
Trans Trans::operator * (int k)
{
	return Trans(a * k, b * k);
}
string Trans::str()
{
	return to_string(a) + "," + to_string(b);
}
float Trans::value()
{
	return a + b * sqrt(3.0);
}
