#include "Logo.h"
#include "SceneMamager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{

}

void Logo::Update()
{
	cout << "Logo" << endl;
	if (GetAsyncKeyState('A'))
		SceneMamager::GetInstance()->SetScene(SCENEID_MENU);
}

void Logo::Render()
{

}

void Logo::Release()
{

}
