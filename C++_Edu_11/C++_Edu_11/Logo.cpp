#include "Logo.h"
#include "ScaneManager.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start(void)
{
	cout << "Logo" << endl;
}

void Logo::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		ScaneManager::GetInstance()->SetScene(MENUID);
}

void Logo::Render(void)
{

}

void Logo::Release(void)
{

}
