#include "Stage.h"
#include "SceneMamager.h"
#include "ObjectManager.h"
#include "Prototype.h"
#include "Player.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	Prototype::GetInstance()->Initialize();
	ObjectManager::GetInstance()->Initialize();

	ObjectManager::GetInstance()->DisableFormEnable();
	/*
	try
	{
		Object* ProtoObject = Prototype::GetInstance()->FindObject("Player");

		if (ProtoObject == nullptr)
			throw __LINE__;

		pPlayer = ProtoObject->Clone();
		pPlayer->Start();
	}
	catch (int i)
	{

	}
	catch (float f)
	{

	}
	catch (double d)
	{

	}
	catch (short s)
	{

	}
	catch (char c)
	{

	}
	catch (string s)
	{

	}
	catch (...)
	{
		cout << "Error : where (" << __FILE__ << ")  line(" << __LINE__ << ")" << endl;
		system("pause");

		pPlayer = (new Player)->Initialize("nullptr_key");
		pPlayer->Start();
	}
	*/
	Object* pObj = nullptr;
}

void Stage::Update()
{
	
	//pPlayer->Update();	
	/*
	cout << "Stage" << endl;
	if (GetAsyncKeyState('A'))
		SceneMamager::GetInstance()->SetScene(SCENEID_EXIT);
	*/
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	//pPlayer->Render();
}

void Stage::Release()
{

}
