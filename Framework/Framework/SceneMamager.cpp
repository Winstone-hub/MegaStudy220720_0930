#include "SceneMamager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneMamager* SceneMamager::Instance = nullptr;

SceneMamager::SceneMamager() : SceneState(nullptr)
{

}

SceneMamager::~SceneMamager()
{
	Release();
}

void SceneMamager::SetScene(Scene_ID id)
{
	if (SceneState != nullptr)
		::Safe_Release(SceneState);

	switch (id)
	{
	case SCENEID_LOGO:
		SceneState = new Logo;
		break;

	case SCENEID_MENU:
		SceneState = new Menu;
		break;

	case SCENEID_STAGE:
		SceneState = new Stage;
		break;

	case SCENEID_EXIT:
		exit(NULL);
		break;
	}
	SceneState->Start();
}

void SceneMamager::Update()
{
	SceneState->Update();
}

void SceneMamager::Render()
{
	SceneState->Render();
}

void SceneMamager::Release()
{
	::Safe_Release(SceneState);
}
