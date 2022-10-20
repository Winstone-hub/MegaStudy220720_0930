#include "Stage.h"
#include "Child.h"


Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start(void)
{
}

void Stage::Update(void)
{
	Objects[EnemyID][0]->Update();
}

void Stage::Render(void)
{
	Objects[EnemyID][0]->Render();
}

void Stage::Release(void)
{

}