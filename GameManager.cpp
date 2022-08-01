#include "GameManager.h"
#include "DxLib.h"
#include "Config.h"
#include "Input.h"
#include "StageCreator.h"
#include "GameObject.h"

int GameManager::bgm = -1;
int GameManager::gameOverSound = -1;
bool GameManager::gameOverPlayed = false;
GameManager GameManager::I = GameManager();

void GameManager::Init(StageLevel lv)
{
	SetFontSize(30);
	if (bgm == -1)
	{
		bgm = LoadSoundMem("resources\\sounds\\planB.wav");
	}
	if (gameOverSound == -1)
	{
		gameOverSound = LoadSoundMem("resources\\sounds\\gameover.wav");
	}
	gameOverPlayed = false;
	StageCreator::Load(lv);
	I = GameManager();
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}

void GameManager::Play()
{
	if (!I.gameOver && I.time > 0)
	{
		I.score += SCORE_TIME;
		I.timeCounter++;
		if (I.timeCounter % 30 == 0) I.time--;
		GameObject::UpdateAll();
	}

	GameObject::DrawAll();
	I.Draw();

	if (I.gameOver || I.time <= 0)
	{
		if (!gameOverPlayed)
		{
			StopSoundMem(bgm);
			PlaySoundMem(gameOverSound, DX_PLAYTYPE_BACK);
			gameOverPlayed = true;
		}

		DrawString(WIN_WIDTH / 2.5, WIN_HEIGHT / 3, "GameOver!", GetColor(0, 0, 0));
		DrawString(WIN_WIDTH / 2.8, WIN_HEIGHT / 2, "Press Return.", GetColor(0, 0, 0));
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			End();

			// ƒŠƒUƒ‹ƒg‚Ö‚Ì‘JˆÚˆ—
		}
	}
}

void GameManager::End()
{
	StageCreator::Delete();
}

void GameManager::Damage()
{
	I.hp -= 1;
	if (I.hp <= 0)
	{
		GameOver();
	}
}

void GameManager::AddScore()
{
	I.score += SCORE_ITEM;
}

void GameManager::GameOver()
{
	I.gameOver = true;
}

GameManager::GameManager()
{
	hpGraph = LoadGraph("resources\\images\\Heart.png");
	score = 0;
	hp = 3;
	time = TIME_LIMIT;
	timeCounter = 0;
	gameOver = false;
}

void GameManager::Draw()
{
	DrawFormatString(10, 10, GetColor(0, 0, 0), "Time: %d", I.time);
	DrawFormatString(10, 40, GetColor(0, 0, 0), "Score: %d", I.score);
	for (int i = 0; i < hp; ++i)
	{
		DrawGraph(WIN_WIDTH - (TILE_SIZE + 5) * (i + 1), 5, hpGraph, true);
	}
}