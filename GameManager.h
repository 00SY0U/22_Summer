#pragma once
#include "StageCreator.h"
class GameManager
{
private:
	static int bgm;
	static int gameOverSound;
	static bool gameOverPlayed;
	static GameManager I;
	int hpGraph;
	int score;
	int hp;
	int time;
	int timeCounter;
	bool gameOver;
public:
	static void Play();
	static void Init(StageLevel lv);
	static void End();
	static void Damage();
	static void AddScore();
	static void GameOver();
	GameManager();
	void Draw();
};

