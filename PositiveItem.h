#pragma once
#include "GameObject.h"
#include <list>
class PositiveItem
	: public GameObject
{
private:
	static std::list<PositiveItem*> objs;
	static int graph;
	static int sound;
	bool isGotten = false;
public:
	static void CheckHitPositiveItem(GameObject* obj);
	PositiveItem(int _x, int _y);
	~PositiveItem();
	void Update() override;
	void Draw() override;
};

