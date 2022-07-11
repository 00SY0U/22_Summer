#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include "Ground.h"
#include "Collision.h"

Player::Player(int _x, int _y, int _width, int _height)
	: GameObject{ _x, _y, _width, _height }
{
	// �X�e�[�^�X
	speed = 10;
	jumpPower = 50;
	gravity = 20;

	// ���������p
	defaultXPos = 180;
	jumpTimer = 0;
	onGround = false;
}

void Player::CulcMovement()
{
	// �d�͂̓K�p
	delta.y += gravity;

	// ���E����
	if (Input::Left())
	{
		delta.x -= speed;
	}
	if (Input::Right())
	{
		delta.x += speed;
	}

	// �W�����v����̓K�p
	if (onGround && Input::Jump())
	{
		jumpTimer = 1;
	}

	// �W�����v�K�p
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
	// �߂荞�ݖh�~����
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
			// �������̑��x�ŐڐG => �ڒn
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