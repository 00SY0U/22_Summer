#include "NegativeItem.h"
#include "DxLib.h"
#include "Config.h"
#include "Collision.h" 
#include "GameManager.h"

std::list<NegativeItem*> NegativeItem::objs = std::list<NegativeItem*>();
int NegativeItem::graph = -1;
int NegativeItem::sound = -1;

void NegativeItem::CheckHitNegativeItem(GameObject* obj)
{
	for (auto o : objs)
	{
		if (!o->isGotten && Collision::CheckHit(obj, o))
		{
			// ƒ_ƒ[ƒWˆ—
			o->isGotten = true;
			PlaySoundMem(sound, DX_PLAYTYPE_BACK);
			GameManager::Damage();
		}
	}
}

NegativeItem::NegativeItem(int _x, int _y)
	: GameObject{ _x, _y, TILE_SIZE, TILE_SIZE }
{
	if (graph == -1)
	{
		graph = LoadGraph("resources\\images\\Fire.png");
	}
	if (sound == -1)
	{
		sound = LoadSoundMem("resources\\sounds\\fire.wav");
	}
	isGotten = false;
	objs.push_back(this);
}

NegativeItem::~NegativeItem()
{
	objs.remove(this);
}

void NegativeItem::Update()
{
	pos.x -= SCROLL_SPEED;
}

void NegativeItem::Draw()
{
	if (!isGotten)
	{
		DrawGraph(pos.x, pos.y, graph, true);
	}
}