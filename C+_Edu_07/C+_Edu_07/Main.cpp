#include "Headers.h"

// http://patorjk.com/software/taag/#p=testall&f=Graffiti&t=Logo

// ** 함수 정리.
// ** 키 입력 함수 수정.



// ** 장면전환을 하기위한 변수
// ** 현재 장면을 보관한다.
SceneID SceneState = SceneID::LOGO;
static DWORD KeyState = 0;







void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey();

void LogoProgress();
void LogoRender(char* _str[], int _size, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str[], int _size, int _x, int _y);

void StageInitialize();
void StageProgress(Object* _Player, Object* _Enemy);
void StageRender(Object* _Player, Object* _Enemy);
bool Collision(Object* _Temp, Object* _Dest);


int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 초기화
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"△");

	// ** Enemy 초기화
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"■");

	StageInitialize();

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			InputKey();
			SetScene(pPlayer, Enemy);
		}
	}

	return 0;
}

// 　　　　　　 　┌───────┐
// 　　　　　　 　│　SceneState　│
// 　　　　　　 　└───────┘
//                        │
//        ┌───────┼───────┐
//        │              │              │
// ┌──────┐┌──────┐┌──────┐
// │　　Logo　　││　　Menu　　││    Stage   │ 
// └──────┘└──────┘└──────┘
void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
	{
		 static char* LogoTex[23] = {
			(char*)"LLLLLLLLLLL",
			(char*)"L:::::::::L",
			(char*)"L:::::::::L",
			(char*)"LL:::::::LL",
			(char*)"  L:::::L                  ooooooooooo      ggggggggg   ggggg   ooooooooooo",
			(char*)"  L:::::L                oo:::::::::::oo   g:::::::::ggg::::g oo:::::::::::oo",
			(char*)"  L:::::L               o:::::::::::::::o g:::::::::::::::::go:::::::::::::::o",
			(char*)"  L:::::L               o:::::ooooo:::::og::::::ggggg::::::ggo:::::ooooo:::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L         LLLLLLo::::o     o::::og::::::g    g:::::g o::::o     o::::o",
			(char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::og:::::::ggggg:::::g o:::::ooooo:::::o",
			(char*)"L::::::::::::::::::::::Lo:::::::::::::::o g::::::::::::::::g o:::::::::::::::o",
			(char*)"L::::::::::::::::::::::L oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo",
			(char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo       gggggggg::::::g    ooooooooooo",
			(char*)"                                                     g:::::g",
			(char*)"                                         gggggg      g:::::g",
			(char*)"                                         g:::::gg   gg:::::g",
			(char*)"                                          g::::::ggg:::::::g",
			(char*)"                                           gg:::::::::::::g",
			(char*)"                                             ggg::::::ggg",
			(char*)"                                                gggggg"
		};

		LogoProgress();
		LogoRender(LogoTex, 23, 22, 5);
	}
		break;

	case SceneID::MENU:
	{
		static char* MenuTex[16] = {
		(char*)"MMMMMMMM               MMMMMMMM",
			(char*)"M:::::::M             M:::::::M",
			(char*)"M::::::::M           M::::::::M",
			(char*)"M:::::::::M         M:::::::::M",
			(char*)"M::::::::::M       M::::::::::M    eeeeeeeeeeee    nnnn  nnnnnnnn    uuuuuu    uuuuuu",
			(char*)"M:::::::::::M     M:::::::::::M  ee::::::::::::ee  n:::nn::::::::nn  u::::u    u::::u",
			(char*)"M:::::::M::::M   M::::M:::::::M e::::::eeeee:::::een::::::::::::::nn u::::u    u::::u",
			(char*)"M::::::M M::::M M::::M M::::::Me::::::e     e:::::enn:::::::::::::::nu::::u    u::::u",
			(char*)"M::::::M  M::::M::::M  M::::::Me:::::::eeeee::::::e  n:::::nnnn:::::nu::::u    u::::u",
			(char*)"M::::::M   M:::::::M   M::::::Me:::::::::::::::::e   n::::n    n::::nu::::u    u::::u",
			(char*)"M::::::M    M:::::M    M::::::Me::::::eeeeeeeeeee    n::::n    n::::nu::::u    u::::u",
			(char*)"M::::::M     MMMMM     M::::::Me:::::::e             n::::n    n::::nu:::::uuuu:::::u",
			(char*)"M::::::M               M::::::Me::::::::e            n::::n    n::::nu:::::::::::::::uu",
			(char*)"M::::::M               M::::::M e::::::::eeeeeeee    n::::n    n::::n u:::::::::::::::u",
			(char*)"M::::::M               M::::::M  ee:::::::::::::e    n::::n    n::::n  uu::::::::uu:::u",
			(char*)"MMMMMMMM               MMMMMMMM    eeeeeeeeeeeeee    nnnnnn    nnnnnn    uuuuuuuu  uuuu" };

		MenuProgress();
		MenuRender(MenuTex, 16, 17, 8);
	}
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

// ** 오브젝트 생성 함수.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ** Object를 동적으로 생성한다.

	//Object* pObj = nullptr;

	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** 좌표를 셋팅
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** 동적할당을 해준다. 동적할당을 할때 문자열의 크기 + 1 만큼의 크기로 해준다.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);

	// ** 문자열을 복사한다.
	strcpy(pObj->Texture, _Texture);

	// ** 문자열의 길이로 크기를 정한다.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** 모든 셋팅이 완료되었다면 
	// ** 동적으로 생성된 Object 의 주소를 반환한다.
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
void InputKey()
{
	KeyState = 0;

	if (GetAsyncKeyState(VK_UP))
		KeyState = KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		KeyState = KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		KeyState = KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		KeyState = KEYID_RIGHT;

	if (GetAsyncKeyState(VK_RETURN))
		KeyState = KEYID_ESCAPE;

	if (GetAsyncKeyState(VK_ESCAPE))
		KeyState = KEYID_ENTER;

	if (GetAsyncKeyState(VK_SPACE))
		KeyState = KEYID_SPACE;
}

void LogoProgress()
{
	if (KeyState == KEYID_ESCAPE)
		SceneState = SceneID::MENU;
}



void LogoRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
}


void MenuProgress()
{
	if (KeyState == KEYID_ENTER)
	{
		SceneState = SceneID::STAGE;
	}
}

void MenuRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
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
	if (KeyState == KEYID_UP)
	{
		if (_Player->Position.y > 0)
			_Player->Position.y--;

		_Player->Texture = (char*)"△";
	}

	if (KeyState == KEYID_DOWN)
	{
		if (_Player->Position.y < 39)
			_Player->Position.y++;

		_Player->Texture = (char*)"▽";
	}

	if (KeyState == KEYID_LEFT)
	{
		if (_Player->Position.x > 0)
			_Player->Position.x--;

		_Player->Texture = (char*)"◁";
	}

	if (KeyState == KEYID_RIGHT)
	{
		if (_Player->Position.x < 118)
			_Player->Position.x++;

		_Player->Texture = (char*)"▷";
	}

	if (KeyState == KEYID_SPACE)
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
				printf("Bullet 충돌 입니다.");
			}
		}

		if (Bullet[i]->Position.x <= 1)
			Check[i] = false;
	}

	if (Collision(_Player, _Enemy))
	{
		SetCursorPosition(120 >> 1, 1);
		printf("충돌 입니다.");
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

// ** 충돌처리 함수
bool Collision(Object* _Temp, Object* _Dest)
{
	if (_Temp->Position.x + _Temp->Scale.x > _Dest->Position.x &&
		_Dest->Position.x + _Dest->Scale.x > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
		return true;
	return false;
}