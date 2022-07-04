#pragma once
#include <list>
#include "Vec2.h"
class GameObject
{
private:
	static std::list<GameObject*> objs;
protected:
	Vec2 pos;
	int width;
	int height;
public:
	static void UpdateAll();
	static void DrawAll();
	GameObject(int _x, int _y, int _width, int _height);
	~GameObject();
	Vec2 GetPos();
	int GetWidth();
	int GetHeight();
	virtual void Update() {}
	virtual void Draw() {}
};

