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
	// �Ԃ�����Ground���擾���āA�����悤�ɒu���Ȃ����H
	// ���W�̍��̐������獶�E(�㉺)�֌W��c��
	// width(height)�̑��������Œ��߂��ł�����

	// x�����K�p �߂荞�߂Ί����߂�
	pos.y -= 10;
	pos.x += delta.x;
	if (Ground::CheckHitGround(this))
	{
		pos.x = curPos.x;
	}
	pos.y += 10;

	// y�����K�p �߂荞�߂Ί����߂� & �ڒn����
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

	// �߂荞�݂��l�����Ȃ�����W���X�V
	ApplyMove();
}

void Player::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(200, 200, 200), true);
}