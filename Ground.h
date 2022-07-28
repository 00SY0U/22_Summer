#pragma once
#include "GameObject.h"
#include <list>
class Ground
	: public GameObject
{
private:
	static std::list<Ground*> objs;
	int graph;
	int numBlocks;
public:
	static bool CheckHitGround(GameObject* obj);
	Ground(int _x, int _y, int _numBlocks);
	~Ground();
	void Update() override;
	void Draw() override;
};

