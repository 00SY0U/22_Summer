#include "Ground.h"
#include "DxLib.h"
#include "Collision.h"
#include "Config.h"

std::list<Ground*> Ground::objs = std::list<Ground*>();

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

Ground::Ground(int _x, int _y, int _numBlocks)
	: GameObject{ _x, _y, TILE_SIZE * _numBlocks, TILE_SIZE }, numBlocks{ _numBlocks }
{
	graph = LoadGraph("resources\\images\\Block.png");
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
	
	for (int i = 0; i < numBlocks; ++i)
	{
		DrawGraph(pos.x + i * TILE_SIZE, pos.y, graph, false);
	}

}
