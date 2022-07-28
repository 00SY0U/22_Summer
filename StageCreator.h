#pragma once
#include <vector>
#include "GameObject.h"
#include "StageLevel.h"

class StageCreator
{
private:
	static std::vector<GameObject*> objs;
	static void LoadEasy();
	static void LoadNormal();
	static void LoadHard();
	static void LoadExtra();
public:
	static void Load(StageLevel lv);
	static void Delete();
};

