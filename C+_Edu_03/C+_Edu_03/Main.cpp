#include <stdio.h>
#include <Windows.h>


struct Vector2
{
	int x, y;
};

struct Object
{
	Vector2 Position;
	char* Texture;
};

bool Horzontal = false;
bool Vertical = false;

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);

int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	// ** 플레피어 초기화
	Object Player;
	Player.Position.x = 0;
	Player.Position.y = 0;

	Player.Texture = (char*)"△";




	// 00110100
	
	// 00000001
	// 00000010
	// 00000100
	// 00001000
	// 00010000
	// 00100000
	// 01000000

	Object Bullet[128];

	// ** 총알이 발사 되었는지 확인하는 용도.
	bool ShowBullet[128];

	// ** 총알의 생성간의 간격을 주기 위함.
	ULONGLONG BulletDelay = GetTickCount64();

	for (int i = 0; i < 128; i++)
	{
		// ** srand = 랜덤함수 초기화
		srand(
			GetTickCount64() * GetTickCount64());

		// ** rand() = 랜덤 함수.
		// ** rand() % 40 = 0 ~ 39 사이의 랜덤값.
		Bullet[i].Position.x = 118;
		Bullet[i].Position.y = rand() % 40;
		Bullet[i].Texture = (char*)"*";

		ShowBullet[i] = false;
	}

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			InputKey(&Player);

			SetCursorPosition(
				Player.Position.x,
				Player.Position.y);

			printf("%s", Player.Texture);



			/*
			* 총알 생성.
			* 2.5초 간격으로 총알을 생성하고, 생성 하는 과정에서 현재 비활성화 되어있는 총알을 찾아 좌표를 수정하고,
			* 활성화 상태로 변경한다. 총알을 1발만 생성 할것이므로 활성화로 변경이 완료되면 즉시 반복문을 탈줄한다.
			*/
			for (int i = 0; i < 128; i++)
			{
				// ** 총알이 2.5초 단위로 생성됨.
				if (BulletDelay + 2500 < GetTickCount64())
				{
					//if (ShowBullet[i] == false)
					// ** 총알이 비활성화 상태라면...
					if (!ShowBullet[i])
					{
						// ** 재생성 되었다면 좌표를 다시 초기화 해준다.
						Bullet[i].Position.x = 118;
						Bullet[i].Position.y = rand() % 40;

						// ** 현재 상태를 활성화 상태로 변경 한다.
						ShowBullet[i] = true;

						// ** 시간값을 재 초기화 한다.
						BulletDelay = GetTickCount64();

						// ** 총알을 1개만 활성화 할 것이기 때문에
						// ** 반복문을 빠저나간다.
						break;
					}
				}
			}


			// ** 활성화 중인 총알을 그린다.
			for (int i = 0; i < 128; i++)
			{
				//if (ShowBullet[i] == true)
				// ** 총알이 활성화 상태라면...
				if (ShowBullet[i])
				{
					Bullet[i].Position.x--;

					SetCursorPosition(
						Bullet[i].Position.x,
						Bullet[i].Position.y);

					printf("%s", Bullet[i].Texture);
				}
			}
		}
	}

	return 0;
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