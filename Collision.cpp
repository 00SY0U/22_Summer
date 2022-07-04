#include "Collision.h"
#include <cmath>
#include "DxLib.h"
#include "GameObject.h"

// ‹éŒ`“–‚½‚è”»’è
bool Collision::CheckHit(GameObject* obj1, GameObject* obj2)
{
	// î•ñæ“¾
	Vec2 p1 = obj1->GetPos();
	Vec2 p2 = obj2->GetPos();
	int w1 = obj1->GetWidth();
	int w2 = obj2->GetWidth();
	int h1 = obj1->GetHeight();
	int h2 = obj2->GetHeight();

	// ’†SŠÔ‹——£æ“¾
	Vec2 c1 = p1 + Vec2{ w1 / 2, h1 / 2 };
	Vec2 c2 = p2 + Vec2{ w2 / 2, h2 / 2 };
	int dx = abs(c1.x - c2.x);
	int dy = abs(c1.y - c2.y);

	// ”»’è
	return (dx < (w1 + w2) / 2 && dy < (h1 + h2) / 2);
}