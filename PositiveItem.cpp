#include "PositiveItem.h"
#include "Collision.h"

std::list<PositiveItem*> PositiveItem::objs = std::list<PositiveItem*>();

bool PositiveItem::CheckHitPositiveItem(GameObject* obj, PositiveItem*& out)
{
	for (auto o : objs)
	{
		if (Collision::CheckHit(obj, o))
		{
			if (out != nullptr)
			{
				out = o;
			}
			return true;
		}
	}
	out = nullptr;
	return false;
}

PositiveItem::PositiveItem(int _x, int _y, int _width, int _height)
	: GameObject{ _x, _y, _width, _height }
{
	objs.push_back(this);
}

PositiveItem::~PositiveItem()
{
	objs.remove(this);
}