#include "GameManager.h"
#include "DxLib.h"
#include "Config.h"
#include "StageCreator.h"
#include "GameObject.h"

GameManager GameManager::I = GameManager();

void GameManager::Init(StageLevel lv)
{
	InitGraph();
	SetFontSize(30);
	StageCreator::Load(lv);
	I = GameManager();
}

void GameManager::Play()
{
	I.score += SCORE_TIME;

	GameObject::UpdateAll();
	GameObject::DrawAll();

	I.Draw();
}

void GameManager::End()
{
	StageCreator::Delete();
}

void GameManager::Damage()
{
	I.hp -= 1;
}

void GameManager::AddScore()
{
	I.score += SCORE_ITEM;
}

GameManager::GameManager()
{
	hpGraph = LoadGraph("resources\\images\\Heart.png");
	score = 0;
	hp = 3;
}

void GameManager::Draw()
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "Score: %d", I.score);
	for (int i = 0; i < hp; ++i)
	{
		DrawGraph(WIN_WIDTH - (TILE_SIZE + 5) * (i + 1), 5, hpGraph, true);
	}
}