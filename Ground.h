#pragma once
#include "GameObject.h"
#include <list>
class Ground
	: public GameObject
{
private:
	static std::list<Ground*> objs;
public:
	static bool CheckHitGround(GameObject* obj);
	Ground(int _x, int _y, int _width, int _height);
	~Ground();
	void Update() override;
	void Draw() override;
};

