#pragma once
#include "StageCreator.h"
class GameManager
{
private:
	static GameManager I;
	int hpGraph;
	int score;
	int hp;
public:
	static void Play();
	static void Init(StageLevel lv);
	static void End();
	static void Damage();
	static void AddScore();
	GameManager();
	void Draw();
};

