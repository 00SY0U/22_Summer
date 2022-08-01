#pragma once
#include "GameObject.h"
#include <list>
class Ground
	: public GameObject
{
private:
	static std::list<Ground*> objs;
	static int graph;
public:
	static bool CheckHitGround(GameObject* obj);
	Ground(int _x, int _y);
	~Ground();
	void Update() override;
	void Draw() override;
};

