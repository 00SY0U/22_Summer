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

	// 内部処理用
	defaultXPos = 180;
	jumpTimer = 0;
	onGround = false;
}

void Player::CulcMovement()
{
	// 重力の適用
	delta.y += GRAVITY;

	// 左右操作
	if (Input::Left())
	{
		delta.x -= PLAYER_SPEED;
	}
	if (Input::Right())
	{
		delta.x += PLAYER_SPEED;
	}

	// ジャンプ操作の適用
	if (onGround && Input::Jump())
	{
		PlaySoundMem(sound, DX_PLAYTYPE_BACK);
		jumpTimer = 1;
	}

	// ジャンプ適用
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
	// めり込み防止処理等
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

	// アイテムとの当たり判定
	PositiveItem::CheckHitPositiveItem(this);
	NegativeItem::CheckHitNegativeItem(this);

	// 左端, 落下ゲームオーバー判定
	if (pos.x <= - width * 3 || pos.y >= WIN_WIDTH + height * 3)
	{
		GameManager::GameOver();
	}
}

void Player::Draw()
{
	// 当たり判定
	// DrawBox(pos.x, pos.y, pos.x + width, pos.y + height, GetColor(200, 200, 200), true);
	
	DrawGraph(pos.x, pos.y, graph, true);
}