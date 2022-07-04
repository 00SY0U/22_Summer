#include "Ground.h"
#include "DxLib.h"
#include "Collision.h"

std::list<Ground*> Ground::objs = std::list<Ground*>();

Ground::Ground(int _x, int _y, int _width, int _height)
	: GameObject{ _x, _y, _width, _height }
{
	objs.push_back(this);
}

Ground::~Ground()
{
	objs.remove(this);
}

bool Ground::CheckHitGround(GameObject* obj)
{
	for (auto o : objs)
	{
		if (Collision::CheckHit(obj, o))
		{
			return true;
		}
	}
	return false;
}

void Ground::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(255, 255, 255), true);
}
