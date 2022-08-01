#pragma once
#include "GameObject.h"
class Player
	: public GameObject
{
private:
	static int graph;
	static int sound;
	int defaultXPos;
	int jumpTimer;
	bool onGround;
	Vec2 curPos;
	Vec2 delta;
	void CulcMovement();
	void ApplyMove();
public:
	Player(int _x, int _y);
	void Update() override;
	void Draw() override;
};

