#include "Point.hpp"

Point::Point(int a, int b)
{
	x = Trans(a, 0);
	y = Trans(b, 0);
}
Point::Point(Trans a, Trans b)
{
	x = a;
	y = b;
}
Point::Point(int x_a, int x_b, int y_a, int y_b)
{
	x = Trans(x_a, x_b);
	y = Trans(y_a, y_b);
}
Point Point::operator + (Point t)
{
	return Point(x + t.x, y + t.y);
}
Point Point::operator - (Point t)
{
	return Point(x - t.x, y - t.y);
}
Point Point::operator * (int k)
{
	return Point(x * k, y * k);
}
string Point::str()
{
	return x.str() + ";" + y.str();
}
pair <float, float> Point::value()
{
	return std::make_pair(x.value(), y.value());
}
