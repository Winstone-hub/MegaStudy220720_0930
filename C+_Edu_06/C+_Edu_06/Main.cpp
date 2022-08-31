#include "Headers.h"

// ** �Լ� ����.
// ** Ű �Է� �Լ� ����.



// ** �����ȯ�� �ϱ����� ����
// ** ���� ����� �����Ѵ�.
SceneID SceneState = SceneID::LOGO;
DWORD KeyState = 0;


void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);

void LogoProgress();
void LogoRender(char* _str, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str, int _x, int _y);

void StageInitialize();
void StageProgress(Object* _Player, Object* _Enemy);
void StageRender(Object* _Player, Object* _Enemy);
bool Collision(Object* _Temp, Object* _Dest);



int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** �÷��̾� �ʱ�ȭ
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"��");

	// ** Enemy �ʱ�ȭ
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"��");

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			SetScene(pPlayer, Enemy);
		}
	}

	return 0;
}


void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
		LogoProgress();
		LogoRender((char*)"Logo", 58, 20);
		break;

	case SceneID::MENU:
		MenuProgress();
		MenuRender((char*)"MENU", 58, 20);
		break;

	case SceneID::STAGE:
		StageProgress(_pPlayer, _pEnemy);
		StageRender(_pPlayer, _pEnemy);
		break;

	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

// ** ������Ʈ ���� �Լ�.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ** Object�� �������� �����Ѵ�.
	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** ��ǥ�� ����
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** �����Ҵ��� ���ش�. �����Ҵ��� �Ҷ� ���ڿ��� ũ�� + 1 ��ŭ�� ũ��� ���ش�.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);
	
	// ** ���ڿ��� �����Ѵ�.
	strcpy(pObj->Texture, _Texture);

	// ** ���ڿ��� ���̷� ũ�⸦ ���Ѵ�.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** ��� ������ �Ϸ�Ǿ��ٸ� 
	// ** �������� ������ Object �� �ּҸ� ��ȯ�Ѵ�.
	return pObj;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** ������ ��ǥ�� �̵���Ű�� �Լ�.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ�â�� �ڵ�.
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����.
}

// ** Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�.
// ** true ���̰�, false �Ⱥ��̰�.
void ShowCursor(bool _b)
{
	// ** Ŀ���� �⺻������ �����Ѵ�.
	CONSOLE_CURSOR_INFO Info;

	// ** Ŀ���� �⺻������ �����Ѵ�.
	// ** Ŀ���� ���̰�/�Ⱥ��̰� �Ѵ�.
	Info.bVisible = _b;

	// ** Ŀ���� ũ�⸦ �����Ѵ�.
	Info.dwSize = 1;

	// ** Ŀ���� ������ �����Ű�� �Լ�.
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// ** �÷��̾��� Ű �Է��� �ް�, �Է¿� ���� Texture �� ���� �Ѵ�.
void InputKey(Object* _Object)
{
	KeyState = 0;

	if (GetAsyncKeyState(VK_UP))
	{
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"��";
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"��";
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"��";
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"��";
	}
}



void LogoProgress()
{
	if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
		SceneState = SceneID::MENU;
}

void LogoRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}


void MenuProgress()
{
	if (GetAsyncKeyState('S'))
	{
		StageInitialize();
		SceneState = SceneID::STAGE;
	}
}

void MenuRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}

Object* Bullet[128];
bool Check[128];

void StageInitialize()
{
	for (int i = 0; i < 128; ++i)
	{
		Bullet[i] = CreateObject(0, 0, (char*)"*");
		Check[i] = false;
	}
}

void StageProgress(Object* _Player, Object* _Enemy)
{
	InputKey(_Player);

	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < 128; ++i)
		{
			if (!Check[i])
			{
				Bullet[i]->Position.x = 118;
				Bullet[i]->Position.y = rand() % 40;
				Check[i] = true;
				break;
			}
		}
	}


	for (int i = 0; i < 128; ++i)
	{
		if (Check[i])
		{
			Bullet[i]->Position.x -= 1;

			if (Collision(_Player, Bullet[i]))
			{
				SetCursorPosition(120 >> 1, 1);
				printf("Bullet �浹 �Դϴ�.");
			}
		}

		if (Bullet[i]->Position.x <= 1)
			Check[i] = false;
	}

	if (Collision(_Player, _Enemy))
	{
		SetCursorPosition(120 >> 1, 1);
		printf("�浹 �Դϴ�.");
	}

	if (GetAsyncKeyState('Q'))
		SceneState = SceneID::EXIT;
}

void StageRender(Object* _Player, Object* _Enemy)
{
	SetCursorPosition(_Player->Position.x, _Player->Position.y);
	printf("%s", _Player->Texture);

	for (int i = 0; i < 128; ++i)
	{
		if (Check[i])
		{
			SetCursorPosition(Bullet[i]->Position.x, Bullet[i]->Position.y);
			printf("%s", Bullet[i]->Texture);
		}
	}

	SetCursorPosition(_Enemy->Position.x, _Enemy->Position.y);
	printf("%s", _Enemy->Texture);
}

// ** �浹ó�� �Լ�
bool Collision(Object* _Temp, Object* _Dest)
{
	if (_Temp->Position.x + _Temp->Scale.x > _Dest->Position.x &&
		_Dest->Position.x + _Dest->Scale.x > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
		return true;
	return false;
}