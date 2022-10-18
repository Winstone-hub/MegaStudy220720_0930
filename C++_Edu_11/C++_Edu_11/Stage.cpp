#include "Stage.h"
#include "ScaneManager.h"


Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Start(void)
{
	cout << "Stage" << endl;
}

void Stage::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		ScaneManager::GetInstance()->SetScene(EXITID);
}

void Stage::Render(void)
{

}

void Stage::Release(void)
{

}