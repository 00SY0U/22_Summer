#include "StageCreator.h"
#include "DxLib.h"
#include "Config.h"
#include "Player.h"
#include "Ground.h"
#include "PositiveItem.h"

std::vector<GameObject*> StageCreator::objs = std::vector<GameObject*>();

void StageCreator::LoadEasy()
{
	objs.push_back(new Player(30, 50, PLAYER_TILE_SIZE, PLAYER_TILE_SIZE));
	objs.push_back(new Ground(0, WIN_HEIGHT - GROUND_TILE_SIZE, WIN_WIDTH * 3, GROUND_TILE_SIZE));
	objs.push_back(new Ground(WIN_WIDTH, WIN_HEIGHT - GROUND_TILE_SIZE * 4.5, WIN_WIDTH * 3, GROUND_TILE_SIZE));
	objs.push_back(new Ground(WIN_WIDTH * 1.5, WIN_HEIGHT - GROUND_TILE_SIZE * 8, WIN_WIDTH * 3, GROUND_TILE_SIZE));
}

void StageCreator::LoadNormal()
{

}

void StageCreator::LoadHard()
{

}

void StageCreator::LoadExtra()
{

}

void StageCreator::Load(StageLevel lv)
{
	// ステージオブジェクト生成
	switch (lv)
	{
	case StageLevel::Easy:
		LoadEasy();
		break;
	case StageLevel::Normal:
		LoadNormal();
		break;
	case StageLevel::Hard:
		LoadHard();
		break;
	case StageLevel::Extra:
		LoadExtra();
		break;
	}
}

void StageCreator::Delete()
{
	for (int i = 0; i < objs.size(); ++i)
	{
		delete objs[i];
	}
	objs = std::vector<GameObject*>();
}