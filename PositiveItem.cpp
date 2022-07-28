#include "PositiveItem.h"
#include "DxLib.h"
#include "Config.h"
#include "Collision.h"
#include "GameManager.h"

std::list<PositiveItem*> PositiveItem::objs = std::list<PositiveItem*>();

void PositiveItem::CheckHitPositiveItem(GameObject* obj)
{
	for (auto o : objs)
	{
		if (!o->isGotten && Collision::CheckHit(obj, o))
		{
			// ‰Á“_ˆ—
			o->isGotten = true;
			GameManager::AddScore();
		}
	}
}

PositiveItem::PositiveItem(int _x, int _y)
	: GameObject{ _x, _y, TILE_SIZE, TILE_SIZE }
{
	isGotten = false;
	graph = LoadGraph("resources\\images\\Snowflake.png");
	objs.push_back(this);
}

PositiveItem::~PositiveItem()
{
	objs.remove(this);
}

void PositiveItem::Update()
{
	pos.x -= SCROLL_SPEED;
}

void PositiveItem::Draw()
{
	if (!isGotten)
	{
		DrawGraph(pos.x, pos.y, graph, true);
	}
}