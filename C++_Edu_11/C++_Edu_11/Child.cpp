#include "Child.h"
#include "ScaneManager.h"
#include "CursorManager.h"

Child::Child()
{
	cout << "Child ������" << endl;
}

Child::~Child()
{
	cout << "Child �Ҹ���" << endl;
}

void Child::Start(void)
{
	Info.Position = Vector3(40.0f, 5.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);

	Tex[0] = "	 ������Music Title In Here";
	Tex[1] = "0:00 ���������ܦ������������������� 4:00";
	Tex[2] = " �ԤԤԤԤ� ���Ԥԡ��ԤԢ� �ԤԤԤԤ� ";
}

void Child::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
		ScaneManager::GetInstance()->SetScene(EXITID);
}

void Child::Render(void)
{
	for(int i = 0 ; i < 3; ++i)
		CursorManager::Renderer(
			Info.Position.x,
			Info.Position.y + i,
			Tex[i], 4);
}

void Child::Release(void)
{

}
