#include "Headers.h"


// ** 장면 관리 (scene 전환)

// ** 생성 함수.
// ** 함수 정리.


bool Horzontal = false;
bool Vertical = false;
SceneID SceneState = SceneID::LOGO;


void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void Render(char* _str, int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);


int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 초기화
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"△");

	// ** Enemy 초기화
	Object Enemy;
	Enemy.Position = Vector2(int(120 * 0.3333f * 2), 40 >> 1);
	Enemy.Texture = (char*)"■";
	Enemy.Scale = Vector2((int)strlen(Enemy.Texture), 1);

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			SetScene(pPlayer, &Enemy);
		}
	}

	return 0;
}


void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
		Render((char*)"LOGO", 58, 20);

		if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
			SceneState = SceneID::MENU;
		break;
	case SceneID::MENU:
		Render((char*)"MENU", 58, 20);

		if (GetAsyncKeyState('S'))
			SceneState = SceneID::STAGE;
		break;
	case SceneID::STAGE:
		// ** ===== Progress ===== 
		InputKey(_pPlayer);

		// ** =====  Render  ===== 
		// ** Player
		Render(_pPlayer->Texture,
			_pPlayer->Position.x,
			_pPlayer->Position.y);

		// ** Enemy
		Render(_pEnemy->Texture,
			_pEnemy->Position.x,
			_pEnemy->Position.y);

		// ** 충돌
		if (_pPlayer->Position.x + 2 > _pEnemy->Position.x &&
			_pEnemy->Position.x + 2 > _pPlayer->Position.x &&
			_pPlayer->Position.y == _pEnemy->Position.y)
		{
			SetCursorPosition(120 >> 1, 1);
			printf("충돌 입니다.");
		}

		if (GetAsyncKeyState('Q'))
			SceneState = SceneID::EXIT;
		break;
	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

Object* CreateObject(int _x, int _y, char* _Texture)
{
	Object* pObj = (Object*)malloc(sizeof(Object));
	
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);
	strcpy(pObj->Texture, _Texture);

	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);
	
	return pObj;
}

// ** 커서의 위치를 이동시킨다.
void SetCursorPosition(int _x, int _y)
{
	// ** 좌표를 설정.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** 설정한 좌표로 이동시키는 함수.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = 현재 콘솔창의 핸들.
	// ** HANDLE : 윈도우 창의 기본 설정값을 셋팅할 수 있음.
}


void Render(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}

// ** 커서를 보이게/안보이게 하는 함수.
// ** true 보이게, false 안보이게.
void ShowCursor(bool _b)
{
	// ** 커서의 기본정보를 생성한다.
	CONSOLE_CURSOR_INFO Info;

	// ** 커서의 기본정보를 셋팅한다.
	// ** 커서를 보이게/안보이게 한다.
	Info.bVisible = _b;

	// ** 커서의 크기를 설정한다.
	Info.dwSize = 1;

	// ** 커서의 설정을 적용시키는 함수.
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// ** 플레이어의 키 입력을 받고, 입력에 따라 Texture 를 변경 한다.
void InputKey(Object* _Object)
{
	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"△";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"▽";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"◁";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"▷";
		Horzontal = true;
	}
	else
		Horzontal = false;
}




