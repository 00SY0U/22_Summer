#pragma once
#include "GameObject.h"
class BackGround
	: public GameObject
{
private:
	static int graph;
public:
	BackGround();
	void Draw() override;
};

