#pragma once
class Vec2
{
public:
	int x;
	int y;
	Vec2();
	Vec2(int _x, int _y);
	Vec2 operator+(Vec2 v);
};

