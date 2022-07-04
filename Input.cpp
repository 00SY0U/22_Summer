#include "Input.h"
#include "DxLib.h"

bool Input::Left()
{
	return CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT);
}

bool Input::Right()
{
	return CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT);
}

bool Input::Jump()
{
	return CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP);
}