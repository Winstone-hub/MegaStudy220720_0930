#include "ScaneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

ScaneManager* ScaneManager::Instance = nullptr;

ScaneManager::ScaneManager() : SceneState(nullptr)
{

}

ScaneManager::~ScaneManager()
{
	Release();
}


void ScaneManager::SetScene(SceneID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case LOGOID:
		SceneState = new Logo;
		break;

	case MENUID:
		SceneState = new Menu;
		break;

	case STAGEID:
		SceneState = new Stage;
		break;

	case EXITID:
		exit(NULL);
		break;
	}

	SceneState->Start();
}

void ScaneManager::Update()
{
	SceneState->Update();
}

void ScaneManager::Render()
{
	SceneState->Render();
}

void ScaneManager::Release()
{

}