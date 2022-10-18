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
	ScaneManager::GetInstance()->SetScene(STAGEID);
}

void MainUpdate::Update(void)
{

}

void MainUpdate::Render(void)
{

}

void MainUpdate::Release(void)
{

}
