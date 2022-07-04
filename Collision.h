#pragma once
class GameObject;
class Collision
{
public:
	static bool CheckHit(GameObject* obj1, GameObject* obj2);
};

