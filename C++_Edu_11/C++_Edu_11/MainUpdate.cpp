#include "MainUpdate.h"
#include "ScaneManager.h"

MainUpdate::MainUpdate(void)
{

}

MainUpdate::~MainUpdate(void)
{

}

void MainUpdate::Start(void)
{
	ScaneManager::GetInstance()->SetScene(LOGOID);
}

void MainUpdate::Update(void)
{
	ScaneManager::GetInstance()->Update();
}

void MainUpdate::Render(void)
{
	ScaneManager::GetInstance()->Render();
}

void MainUpdate::Release(void)
{

}
