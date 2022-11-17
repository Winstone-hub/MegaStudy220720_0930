#include "MainUpdate.h"
#include "SceneMamager.h"
#include "InputManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}


void MainUpdate::Start()
{
	SceneMamager::GetInstance()->SetScene(SCENEID_LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();

	SceneMamager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneMamager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}

