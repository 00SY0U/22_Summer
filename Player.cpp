#include "Player.h"
#include "DxLib.h"
#include "Config.h"
#include "Input.h"
#include "GameManager.h"
#include "Ground.h"
#include "Collision.h"
#include "PositiveItem.h"
#include "NegativeItem.h"

int Player::graph = -1;
int Player::sound = -1;

Player::Player(int _x, int _y)
	: GameObject{ _x, _y, PLAYER_WIDTH, PLAYER_HEIGHT }
{
	if (graph == -1)
	{
		graph = LoadGraph("resources\\images\\Player.png");
	}
	if (sound == -1)
	{
		sound = LoadSoundMem("resources\\sounds\\jump.wav");
	}

	// ���������p
	defaultXPos = 180;
	jumpTimer = 0;
	onGround = false;
}

void Player::CulcMovement()
{
	// �d�͂̓K�p
	delta.y += GRAVITY;

	// ���E����
	if (Input::Left())
	{
		delta.x -= PLAYER_SPEED;
	}
	if (Input::Right())
	{
		delta.x += PLAYER_SPEED;
	}

	// �W�����v����̓K�p
	if (onGround && Input::Jump())
	{
		PlaySoundMem(sound, DX_PLAYTYPE_BACK);
		jumpTimer = 1;
	}

	// �W�����v�K�p
	if (jumpTimer > 0)
	{
		delta.y -= PLAYER_JUMP_POWER * (PLAYER_JUMP_TIME - jumpTimer) / (double)PLAYER_JUMP_TIME;
		++jumpTimer;

		if (jumpTimer > PLAYER_JUMP_TIME)
		{
			jumpTimer = 0;
		}
	}
}

void Player::ApplyMove()
{
	// �߂荞�ݖh�~������
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
	if (pos.x > WIN_WIDTH - width)
	{
		pos.x = WIN_WIDTH - width;
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

	// �A�C�e���Ƃ̓����蔻��
	PositiveItem::CheckHitPositiveItem(this);
	NegativeItem::CheckHitNegativeItem(this);

	// ���[, �����Q�[���I�[�o�[����
	if (pos.x <= - width * 3 || pos.y >= WIN_WIDTH + height * 3)
	{
		GameManager::GameOver();
	}
}

void Player::Draw()
{
	// �����蔻��
	// DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(200, 200, 200), true);
	
	DrawGraph(pos.x, pos.y, graph, true);
}