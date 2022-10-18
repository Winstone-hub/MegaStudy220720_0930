#include "Menu.h"
#include "ScaneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Start(void)
{
	cout << "Menu" << endl;
}

void Menu::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		ScaneManager::GetInstance()->SetScene(STAGEID);
}

void Menu::Render(void)
{

}

void Menu::Release(void)
{

}