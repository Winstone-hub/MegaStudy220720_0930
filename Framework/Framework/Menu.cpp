#include "Menu.h"
#include "SceneMamager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{

}

void Menu::Update()
{
	cout << "Menu" << endl;
	if (GetAsyncKeyState('A'))
		SceneMamager::GetInstance()->SetScene(SCENEID_STAGE);
}

void Menu::Render()
{

}

void Menu::Release()
{

}
