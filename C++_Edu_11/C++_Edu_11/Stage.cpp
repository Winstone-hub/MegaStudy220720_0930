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
	Testcase = new Child;
	Testcase->Start();
}

void Stage::Update(void)
{
	Testcase->Update();
}

void Stage::Render(void)
{
	Testcase->Render();
}

void Stage::Release(void)
{
	delete Testcase;
	Testcase = nullptr;
}