#include "ObjectManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : Player(nullptr)
{
	*(*Objects) = nullptr;
}

ObjectManager::~ObjectManager()
{
}
