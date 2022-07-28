#pragma once
#include "GameObject.h"
class BackGround
	: public GameObject
{
private:
	int graph;
public:
	BackGround();
	void Draw() override;
};

