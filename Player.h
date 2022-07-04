#pragma once
#include "GameObject.h"
class Player
	: public GameObject
{
private:
	int gravity;
	int speed;
	int jumpPower;
	int jumpTimer;
	bool onGround;
	Vec2 curPos;
	Vec2 delta;
	void ApplyGravity();
	void Move();
	void Jump();
	void ApplyMove();
	void AdjX();
	void AdjY();
public:
	Player(int _x, int _y, int _width, int _height);
	void Update() override;
	void Draw() override;
};

