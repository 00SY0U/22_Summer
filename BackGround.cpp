#include "BackGround.h"
#include "DxLib.h"

int BackGround::graph = -1;

BackGround::BackGround()
	: GameObject{ 0, 0, 0, 0 }
{
	if (graph == -1)
	{
		graph = LoadGraph("resources\\images\\BackGround.png");
	}
}

void BackGround::Draw()
{
	DrawGraph(0, 0, graph, false);
}