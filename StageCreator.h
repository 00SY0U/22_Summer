#pragma once
#include <vector>
#include "GameObject.h"
#include "StageLevel.h"

class StageCreator
{
private:
	static std::vector<GameObject*> objs;
public:
	static void Load(StageLevel lv);
	static void Delete();
};

