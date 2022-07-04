#include "Vec2.h"

Vec2::Vec2()
	: x{ 0 }, y{ 0 }
{
}

Vec2::Vec2(int _x, int _y)
	: x{ _x }, y{ _y }
{
}

Vec2 Vec2::operator+(Vec2 v)
{
	return Vec2{ x + v.x, y + v.y };
}