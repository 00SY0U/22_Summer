#pragma once
#include "GameObject.h"
#include <list>
class PositiveItem
	: public GameObject
{
private:
	static std::list<PositiveItem*> objs;
public:
	static bool CheckHitPositiveItem(GameObject* obj, PositiveItem*& out);
	PositiveItem(int _x, int _y, int _width, int _height);
	~PositiveItem();

};

