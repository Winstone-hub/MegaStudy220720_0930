#include <stdio.h>
#include <Windows.h>

struct Vector2
{
	int x, y;
};

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);

int main(void)
{
	// ** 커서를 안보이게 설정함.
	ShowCursor(false);

	// ** 시간 셋팅
	ULONGLONG Time = GetTickCount64();

	// ** 플레이어 좌표
	Vector2 PlayerPosition;
	PlayerPosition.x = 0;
	PlayerPosition.y = 0;

	// ** 플레이어 Texture
	char* Texture = (char*)"△";

	// ** true/false 둘중에 하나만 반환.
	// ** 키 입력이 횡 이동일때를 확인.
	bool Horzontal = false;

	// ** 키 입력이 종 이동일때를 확인.
	bool Vertical = false;

	// ** 루프
	while (true)
	{
		// ** 0.05초 간격으로 반복
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			
			// ** 화면 클리어
			system("cls");

			// ** 키 입력.
			// GetAsyncKeyState() = 키입력 함수
			
			// 상황에 따라서 다음을 반환 함.
			// 0x0000, 0x0001, 0x8000, 0x8001
			
			// ** 뒤쪽 0과 1의 차의
			// 0 : 이전에 눌린적 없음.
			// 1 : 이전에 눌린적 있음.
			
			// ** 앞쪽 8과 0의 차의
			// 0 : 현재 눌리지 않음.
			// 8 : 현재 눌림.
			
			// ** 매개변수로 Virtual Key 를 입력 받는다.
			//if (GetAsyncKeyState(VK_UP) & 0x01)
				//printf("UP\n");

			if (GetAsyncKeyState(VK_UP) && !Horzontal)
			{
				// ** y좌표가 0보다 클 때에만 입력을 받는다.
				if (PlayerPosition.y > 0)
					PlayerPosition.y--;

				Texture = (char*)"△";
				Vertical = true;
			}
			else
				Vertical = false;
				
			if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
			{
				// ** y좌표가 39보다 작을때에만 입력을 받는다.
				if(PlayerPosition.y < 39)
					PlayerPosition.y++;

				Texture = (char*)"▽";
				Vertical = true;
			}
			else
				Vertical = false;

			if (GetAsyncKeyState(VK_LEFT) && !Vertical)
			{
				// ** x좌표가 0보다 클 때에만 입력을 받는다.
				if (PlayerPosition.x > 0)
					PlayerPosition.x--;

				Texture = (char*)"◁";
				Horzontal = true;
			}
			else
				Horzontal = false;

			if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
			{
				// ** x좌표가 118보다 작을 때에만 입력을 받는다.
				if (PlayerPosition.x < 118)
					PlayerPosition.x++;

				Texture = (char*)"▷";
				Horzontal = true;
			}
			else
				Horzontal = false;

			SetCursorPosition(
				PlayerPosition.x, 
				PlayerPosition.y);

			printf("%s", Texture);
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
