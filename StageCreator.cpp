#include "StageCreator.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "DxLib.h"
#include "Config.h"
#include "BackGround.h"
#include "Player.h"
#include "Ground.h"
#include "PositiveItem.h"
#include "NegativeItem.h"

#define X(n) TILE_SIZE * (n)
#define Y(n) WIN_HEIGHT - TILE_SIZE * (n + 1)

std::vector<GameObject*> StageCreator::objs = std::vector<GameObject*>();

void StageCreator::Load(StageLevel lv)
{
	// ステージファイル判別
	std::string fileName = "";
	switch (lv)
	{
	case StageLevel::Easy:
		fileName = "resources\\stages\\Easy.txt";
		break;
	case StageLevel::Normal:
		fileName = "resources\\stages\\Normal.txt";
		break;
	case StageLevel::Hard:
		fileName = "resources\\stages\\Hard.txt";
		break;
	case StageLevel::Extra:
		fileName = "resources\\stages\\Extra.txt";
		break;
	case StageLevel::Debug:
		fileName = "resources\\stages\\Stage.txt";
		break;
	}

	// ファイル読み込み
	std::ifstream file{ fileName };
	if (!file.is_open())
	{
		printfDx("読み込みに失敗\n");
		return;
	}

	std::string line;
	std::vector<std::string> stage{};
	while (getline(file, line))
	{
		stage.push_back(line);
	}
	std::reverse(stage.begin(), stage.end());

	// 背景配置
	objs.push_back(new BackGround);

	// プレイヤー配置
	objs.push_back(new Player{ X(3), Y(3) });

	// ステージ生成
	for (int i = 0; i < stage.size(); ++i)
	{
		for (int j = 0; j < stage[i].size(); ++j)
		{
			switch (stage[i][j])
			{
			case 'x':
				objs.push_back(new Ground{ X(j), Y(i) });
				break;
			case 'p':
				objs.push_back(new PositiveItem{ X(j), Y(i) });
				break;
			case 'n':
				objs.push_back(new NegativeItem{ X(j), Y(i) });
				break;
			}
		}
	}
}

void StageCreator::Delete()
{
	for (int i = 0; i < objs.size(); ++i)
	{
		delete objs[i];
	}
	objs = std::vector<GameObject*>();
}