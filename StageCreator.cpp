#include "StageCreator.h"
#include "DxLib.h"
#include "Config.h"
#include "BackGround.h"
#include "Player.h"
#include "Ground.h"
#include "PositiveItem.h"
#include "NegativeItem.h"

#define X(n) TILE_SIZE * (n)
#define Y(n) WIN_HEIGHT - TILE_SIZE * (n)

std::vector<GameObject*> StageCreator::objs = std::vector<GameObject*>();

void StageCreator::LoadEasy()
{
	// 背景
	objs.push_back(new BackGround());
	// プレイヤー
	objs.push_back(new Player(30, 50, PLAYER_WIDTH, PLAYER_HEIGHT));
	// 地面
	objs.push_back(new Ground(X(0), Y(1), 100));
	objs.push_back(new Ground(X(10), Y(4), 5));
	objs.push_back(new Ground(X(13), Y(6), 3));
	objs.push_back(new Ground(X(20), Y(4), 2));
	// スコアアイテム
	objs.push_back(new PositiveItem(X(10), Y(5)));
	// ダメージアイテム
	objs.push_back(new NegativeItem(X(11), Y(5)));
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