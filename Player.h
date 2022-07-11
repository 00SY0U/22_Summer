#pragma once
#include "GameObject.h"
class Player
	: public GameObject
{
private:
	int speed;
	int jumpPower;
	int gravity;
	int defaultXPos;
	int jumpTimer;
	bool onGround;
	Vec2 curPos;
	Vec2 delta;
	void CulcMovement();
	void ApplyMove();
public:
	Player(int _x, int _y, int _width, int _height);
	void Update() override;
	void Draw() override;
};

