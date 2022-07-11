#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "Ground.h"
#include "Collision.h"

Player::Player(int _x, int _y, int _width, int _height)
	: GameObject{ _x, _y, _width, _height }
{
	// ステータス
	speed = 10;
	jumpPower = 50;
	gravity = 20;

	// 内部処理用
	defaultXPos = 180;
	jumpTimer = 0;
	onGround = false;
}

void Player::CulcMovement()
{
	// 重力の適用
	delta.y += gravity;

	// 左右操作
	if (Input::Left())
	{
		delta.x -= speed;
	}
	if (Input::Right())
	{
		delta.x += speed;
	}

	// ジャンプ操作の適用
	if (onGround && Input::Jump())
	{
		jumpTimer = 1;
	}

	// ジャンプ適用
	if (jumpTimer > 0)
	{
		delta.y -= jumpPower * (30 - jumpTimer) / 30.0;
		++jumpTimer;

		if (jumpTimer > 30)
		{
			jumpTimer = 0;
		}
	}
}

void Player::ApplyMove()
{
	// めり込み防止処理
	pos.x += delta.x;
	while (Ground::CheckHitGround(this))
	{
		if (delta.x < 0)
		{
			++pos.x;
		}
		else
		{
			--pos.x;
		}
	}

	onGround = false;
	pos.y += delta.y;
	while (Ground::CheckHitGround(this))
	{
		if (delta.y < 0)
		{
			++pos.y;
		}
		else
		{
			// 下向きの速度で接触 => 接地
			onGround = true;
			--pos.y;
		}
	}
}

void Player::Update()
{
	curPos = pos;
	delta = Vec2{ 0, 0 };

	CulcMovement();
	ApplyMove();
}

void Player::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(200, 200, 200), true);
}