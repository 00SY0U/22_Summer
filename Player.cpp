#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "Ground.h"

Player::Player(int _x, int _y, int _width, int _height)
	: GameObject{ _x, _y, _width, _height }
{
	gravity = 12;
	speed = 12;
	jumpPower = 30;
	jumpTimer = 0;
	onGround = false;
}

void Player::ApplyGravity()
{
	pos.y += gravity;
}

void Player::Move()
{
	if (Input::Left()) delta.x -= speed;
	if (Input::Right()) delta.x += speed;
}

void Player::Jump()
{
	if (onGround && Input::Jump())
	{
		jumpTimer = 1;
	}
	
	if (jumpTimer > 0)
	{
		delta.y -= jumpPower * (30 - jumpTimer) / 30.0;
		++jumpTimer;
	}

	if (jumpTimer > 30)
	{
		jumpTimer = 0;
	}

}

void Player::ApplyMove()
{
	// ぶつかったGroundを取得して、沿うように置きなおす？
	// 座標の差の正負から左右(上下)関係を把握
	// width(height)の足し引きで調節ができそう

	// x方向適用 めり込めば巻き戻し
	pos.y -= 10;
	pos.x += delta.x;
	if (Ground::CheckHitGround(this))
	{
		pos.x = curPos.x;
	}
	pos.y += 10;

	// y方向適用 めり込めば巻き戻し & 接地判定
	pos.x -= 10;
	pos.y += delta.y;
	onGround = false;
	if (Ground::CheckHitGround(this))
	{
		pos.y = curPos.y;

		if (jumpTimer < 1)
		{
			onGround = true;
			jumpTimer = 0;
		}
	}
	pos.x += 10;
}

void Player::Update()
{
	curPos = pos;
	delta = Vec2{ 0, 0 };

	Move();
	Jump();
	ApplyGravity();

	// めり込みを考慮しながら座標を更新
	ApplyMove();
}

void Player::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(200, 200, 200), true);
}