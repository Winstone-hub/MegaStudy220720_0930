#include "Menu.h"
#include "ScaneManager.h"
#include "ObjectManager.h"
#include "Child.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Start(void)
{
	ObjectManager::GetInstance()->SetObjects(*(*Objects));

	for (int i = 0; i < EndID; ++i)
	{
		for (int j = 0; j < MaxID; ++j)
		{
			Objects[i][j] = new Child;
			Objects[i][j]->Start();
		}
	}
	//ScaneManager::GetInstance()->SetScene(STAGEID);
}

void Menu::Update(void)
{

}

void Menu::Render(void)
{

}

void Menu::Release(void)
{

}