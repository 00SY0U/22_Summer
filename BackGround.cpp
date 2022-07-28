#include "BackGround.h"
#include "DxLib.h"
BackGround::BackGround()
	: GameObject{ 0, 0, 0, 0 }
{
	graph = LoadGraph("resources\\images\\BackGround.png");
}

void BackGround::Draw()
{
	DrawGraph(0, 0, graph, false);
}