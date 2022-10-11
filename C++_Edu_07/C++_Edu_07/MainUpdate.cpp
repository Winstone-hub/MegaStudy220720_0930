#include "MainUpdate.h"

#include "SingletonManager.h"
#include "Player.h"
#include "Enemy.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize()
{
	ObjectList[0] = SingletonManager::GetInstance()->CreatePlayer();
	ObjectList[0]->Initialize();

	ObjectList[1] = SingletonManager::GetInstance()->CreateEnemy();
	ObjectList[1]->Initialize();
}

void MainUpdate::Progress()
{
	for (Object* Element : ObjectList)
		Element->Progress();
}

void MainUpdate::Render()
{
	for (Object* Element : ObjectList)
		Element->Render();
}

void MainUpdate::Release()
{
	for (Object* Element : ObjectList)
	{
		delete Element;
		Element = nullptr;
	}
}