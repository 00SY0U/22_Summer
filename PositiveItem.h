#pragma once
#include "GameObject.h"
#include <list>
class PositiveItem
	: public GameObject
{
private:
	static std::list<PositiveItem*> objs;
	bool isGotten = false;
	int graph;
public:
	static void CheckHitPositiveItem(GameObject* obj);
	PositiveItem(int _x, int _y);
	~PositiveItem();
	void Update() override;
	void Draw() override;
};

