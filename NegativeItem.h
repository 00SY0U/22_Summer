#pragma once
#include "GameObject.h"
#include <list>
class NegativeItem
	: public GameObject
{
private:
	static std::list<NegativeItem*> objs;
	static int graph;
	static int sound;
	bool isGotten = false;
public:
	static void CheckHitNegativeItem(GameObject* obj);
	NegativeItem(int _x, int _y);
	~NegativeItem();
	void Update() override;
	void Draw() override;
};

