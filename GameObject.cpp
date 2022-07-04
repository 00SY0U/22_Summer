#include "GameObject.h"

std::list<GameObject*> GameObject::objs = std::list<GameObject*>();

void GameObject::UpdateAll()
{
	for (auto o : objs)
	{
		o->Update();
	}
}

void GameObject::DrawAll()
{
	for (auto o : objs)
	{
		o->Draw();
	}
}

GameObject::GameObject(int _x, int _y, int _width, int _height)
	: pos{ _x, _y }, width{ _width }, height{ _height }
{
	objs.push_back(this);
}

GameObject::~GameObject()
{
	objs.remove(this);
}

Vec2 GameObject::GetPos()
{
	return pos;
}

int GameObject::GetWidth()
{
	return width;
}

int GameObject::GetHeight()
{
	return height;
}