#include "Stage.h"
#include "SceneMamager.h"
#include "Player.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
}

void Stage::Update()
{
	pPlayer->Update();
	/*
	cout << "Stage" << endl;
	if (GetAsyncKeyState('A'))
		SceneMamager::GetInstance()->SetScene(SCENEID_EXIT);
	*/
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{

}
