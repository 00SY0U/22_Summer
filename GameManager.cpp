#include "GameManager.h"
#include "StageCreator.h"
#include "GameObject.h"
void GameManager::Init()
{
	StageCreator::Load(StageLevel::Easy);
}

void GameManager::Play()
{
	GameObject::UpdateAll();
	GameObject::DrawAll();
}

void GameManager::End()
{
	StageCreator::Delete();
}