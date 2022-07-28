#pragma once
#include "GameObject.h"
#include <list>
class NegativeItem
	: public GameObject
{
private:
	static std::list<NegativeItem*> objs;
	bool isGotten = false;
	int graph;
public:
	static void CheckHitNegativeItem(GameObject* obj);
	NegativeItem(int _x, int _y);
	~NegativeItem();
	void Update() override;
	void Draw() override;
};

