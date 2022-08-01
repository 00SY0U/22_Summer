#include "PositiveItem.h"
#include "DxLib.h"
#include "Config.h"
#include "Collision.h"
#include "GameManager.h"

std::list<PositiveItem*> PositiveItem::objs = std::list<PositiveItem*>();
int PositiveItem::graph = -1;
int PositiveItem::sound = -1;

void PositiveItem::CheckHitPositiveItem(GameObject* obj)
{
	for (auto o : objs)
	{
		if (!o->isGotten && Collision::CheckHit(obj, o))
		{
			// ‰Á“_ˆ—
			o->isGotten = true;
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			GameManager::AddScore();
		}
	}
}

PositiveItem::PositiveItem(int _x, int _y)
	: GameObject{ _x, _y, TILE_SIZE, TILE_SIZE }
{
	if (graph == -1)
	{
		graph = LoadGraph("resources\\images\\Snowflake.png");
	}
	if (sound == -1)
	{
		sound = LoadSoundMem("resources\\sounds\\cion.wav");
	}
	isGotten = false;
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