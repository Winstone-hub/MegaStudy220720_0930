#include "../../Common/Headers.h"

// ** 디스코드 링크
// https://discord.gg/HVwPDyx7

// http://patorjk.com/software/taag/#p=testall&f=Graffiti&t=Logo
// https://igotit.tistory.com/entry/Visual-Studio-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8-%EC%86%8D%EC%84%B1%EC%97%90%EC%84%9C-%EB%A7%88%ED%81%AC%EB%A1%9C-%EC%9D%98%EB%AF%B8

// ** 키 입력 함수 수정.
// ** 파일 입출력.
char* LogoTex[23];

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

// ** 장면전환을 하기위한 변수
// ** 현재 장면을 보관한다.
SceneID SceneState = SceneID::LOGO;

// ** 어떤 키를 입력 받았는지 확인하기 위한 변수.
static DWORD KeyState = 0;

void SetScene(Object* _pPlayer, Object* _pEnemy, Object* _pBullet);
char* ReadAll(char* _FileName);
void ReadLine(char* _FileName, char** _LogoTex);

Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey();


void LogoInitialize();
void LogoProgress();
void LogoRender(char* _str[], int _size, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str[], int _size, int _x, int _y);

void StageInitialize();
void StageProgress(Object* _Player, Object* _Enemy, Object* _pBullet);
void StageRender(Object* _Player, Object* _Enemy, Object* _pBullet);
bool Collision(Object* _Temp, Object* _Dest);



bool Check[128];

int main(void)
{
	Object* Bullet = (Object*)malloc(sizeof(Object) * 128);
	
	for (int i = 0; i < 128; ++i)
	{
		Check[i] = false;
		Bullet[i].Position.x = 10;
	}

	/*
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 초기화
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"△");

	// ** Enemy 초기화
	Object* Enemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"■");

	LogoInitialize();
	StageInitialize();

	while (true)
	{
		if (Time + 50 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			InputKey();
			SetScene(pPlayer, Enemy, Bullet);
		}
	}
	*/

	return 0;
}

// 　　　　　　 　┌───────┐
// 　　　　　　 　│　SceneState  │
// 　　　　　　 　└───────┘
// 　　　　　　　　　　 │
//        ┌───────┼───────┐
//        │　　　　　　　│　　　　　　　│
// ┌──────┐┌──────┐┌──────┐
// │　　Logo　  ││　Menu　　 ││    Stage　　│ 
// └──────┘└──────┘└──────┘
void SetScene(Object* _pPlayer, Object* _pEnemy, Object* _pBullet)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
	{
		LogoProgress();
		LogoRender(LogoTex, 23, 22, 5);
	}
	break;

	case SceneID::MENU:
	{
		MenuProgress();
		MenuRender(MenuTex, 16, 17, 8);
	}
	break;

	case SceneID::STAGE:
		StageProgress(_pPlayer, _pEnemy, _pBullet);
		StageRender(_pPlayer, _pEnemy, _pBullet);
		break;

	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}

// ** 데이터 전체 불러오기.
char* ReadAll(char* _FileName)
{
	/*
	* r = 읽기 전용
	* r+ = 읽기+쓰기 함께 지원하지만 파일이 없으면 안됨.
	* w = 쓰기 전용 (덮어쓰기를 하기때문에 주의)
	* w+ = 읽기+쓰기 함께 지원하지만 덮어쓰기를 하기때문에 주의

	* [파일 입출력 함수]
	* fopen : 파일 열기, 파일을 열지 않으면 데이터에 접근이 불가.
	* fclose : 파일 닫기, 파일이 열려있는 상태로 계속 유지됨.
	* fgetc : 파일에서 문자 읽기
	* fgets : 파일에서 문자열 읽기

	* fputc : 파일에서 문자 출력
	* fputs : 파일에서 문자열 출력

	* fscanf : 파일에 데이터 입력(쓰기)
	* feof : 파일의 문제가 있는지 없는지 확인.
	*/
	FILE* pFile = fopen("Test.txt", "r");

	char Buffer[1024];
	fread(Buffer, 1, 1024, pFile);

	char* str = (char*)malloc(strlen(Buffer) + 1);
	strcpy(str, Buffer);

	return str;
}

// ** 데이터를 한줄씩 복사
void ReadLine(char* _FileName, char** _Tex)
{
	FILE* pFile = fopen("Test.txt", "rt");

	int size = 0;
	while (!feof(pFile))
	{
		// ** 데이터 한줄씩 불러오기
		char str[1024] = "";
		fgets(str, 1024, pFile);

		_Tex[size] = (char*)malloc(strlen(str));
		strcpy(_Tex[size], str);
		size++;
	}

	fclose(pFile);
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
		KeyState |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		KeyState |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		KeyState |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		KeyState |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_RETURN))
		KeyState |= KEYID_ESCAPE;

	if (GetAsyncKeyState(VK_ESCAPE))
		KeyState |= KEYID_ENTER;

	if (GetAsyncKeyState(VK_SPACE))
		KeyState |= KEYID_SPACE;

	if (GetAsyncKeyState(VK_SHIFT))
		KeyState |= KEYID_SHIFT;
}


void LogoInitialize()
{
	for (int i = 0; i < 23; ++i)
		ReadLine((char*)"Test.txt", LogoTex);
}

void LogoProgress()
{
	if (KeyState & KEYID_ESCAPE)
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
	if (KeyState & KEYID_ENTER)
		SceneState = SceneID::STAGE;
}

void MenuRender(char* _str[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _str[i]);
	}
}

void StageInitialize()
{
	/*
	for (int i = 0; i < 128; ++i)
	{
		Bullet[i] = CreateObject(0, 0, (i % 2) == 0 ? (char*)"*" : (char*)".");
		Check[i] = false;
	}
	*/
	
}

void StageProgress(Object* _Player, Object* _Enemy, Object* _pBullet)
{
	if (KeyState & KEYID_UP)
	{
		if (_Player->Position.y > 0)
			_Player->Position.y--;

		_Player->Texture = (char*)"△";
	}

	if (KeyState & KEYID_DOWN)
	{
		if (_Player->Position.y < 39)
			_Player->Position.y++;

		_Player->Texture = (char*)"▽";
	}

	if (KeyState & KEYID_LEFT)
	{
		if (_Player->Position.x > 0)
			_Player->Position.x--;

		_Player->Texture = (char*)"◁";
	}

	if (KeyState & KEYID_RIGHT)
	{
		if (_Player->Position.x < 118)
			_Player->Position.x++;

		_Player->Texture = (char*)"▷";
	}
	/*
	if (KeyState & KEYID_SPACE)
	{
		for (int i = 0; i < 128; ++i)
		{
			_pBullet[i].Position.x = 118;
			_pBullet[i].Position.y = rand() % 40;
			break;
		}
	}

	
	for (int i = 0; i < 128; ++i)
	{
		_pBullet[i].Position.x -= 1;

		// ** 
		if (_Player->Position.x + _Player->Scale.x > _pBullet[i].Position.x &&
			_pBullet[i].Position.x + _pBullet[i].Scale.x > _Player->Position.x &&
			_Player->Position.y == _pBullet[i].Position.y)
		{

		}

		if (_pBullet[i].Position.x <= 1)
		{

		}
	}
	*/
	

	if (Collision(_Player, _Enemy))
	{
		SetCursorPosition(120 >> 1, 1);
		printf("충돌 입니다.");
	}

	if (GetAsyncKeyState('Q'))
		SceneState = SceneID::EXIT;
}

void StageRender(Object* _Player, Object* _Enemy, Object* _pBullet)
{
	SetCursorPosition(_Player->Position.x, _Player->Position.y);
	printf("%s", _Player->Texture);

	for (int i = 0; i < 128; ++i)
	{
		if (Check[i])
		{
			SetCursorPosition(_pBullet[i].Position.x, _pBullet[i].Position.y);
			printf("%s", _pBullet[i].Texture);
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