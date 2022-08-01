#include "Ground.h"
#include "DxLib.h"
#include "Collision.h"
#include "Config.h"

std::list<Ground*> Ground::objs = std::list<Ground*>();
int Ground::graph = -1;

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

Ground::Ground(int _x, int _y)
	: GameObject{ _x, _y, TILE_SIZE, TILE_SIZE }
{
	if (graph == -1)
	{
		graph = LoadGraph("resources\\images\\Block.png");
	}
	objs.push_back(this);
}

Ground::~Ground()
{
	objs.remove(this);
}

void Ground::Update()
{
	pos.x -= SCROLL_SPEED;
}

void Ground::Draw()
{
	// DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(255, 255, 255), true);
	DrawGraph(pos.x, pos.y, graph, false);
}
