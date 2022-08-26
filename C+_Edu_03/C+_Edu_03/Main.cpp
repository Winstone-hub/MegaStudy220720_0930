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

	// ** �÷��Ǿ� �ʱ�ȭ
	Object Player;
	Player.Position.x = 0;
	Player.Position.y = 0;

	Player.Texture = (char*)"��";




	// 00110100
	
	// 00000001
	// 00000010
	// 00000100
	// 00001000
	// 00010000
	// 00100000
	// 01000000

	Object Bullet[128];

	// ** �Ѿ��� �߻� �Ǿ����� Ȯ���ϴ� �뵵.
	bool ShowBullet[128];

	// ** �Ѿ��� �������� ������ �ֱ� ����.
	ULONGLONG BulletDelay = GetTickCount64();

	for (int i = 0; i < 128; i++)
	{
		// ** srand = �����Լ� �ʱ�ȭ
		srand(
			GetTickCount64() * GetTickCount64());

		// ** rand() = ���� �Լ�.
		// ** rand() % 40 = 0 ~ 39 ������ ������.
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
			* �Ѿ� ����.
			* 2.5�� �������� �Ѿ��� �����ϰ�, ���� �ϴ� �������� ���� ��Ȱ��ȭ �Ǿ��ִ� �Ѿ��� ã�� ��ǥ�� �����ϰ�,
			* Ȱ��ȭ ���·� �����Ѵ�. �Ѿ��� 1�߸� ���� �Ұ��̹Ƿ� Ȱ��ȭ�� ������ �Ϸ�Ǹ� ��� �ݺ����� Ż���Ѵ�.
			*/
			for (int i = 0; i < 128; i++)
			{
				// ** �Ѿ��� 2.5�� ������ ������.
				if (BulletDelay + 2500 < GetTickCount64())
				{
					//if (ShowBullet[i] == false)
					// ** �Ѿ��� ��Ȱ��ȭ ���¶��...
					if (!ShowBullet[i])
					{
						// ** ����� �Ǿ��ٸ� ��ǥ�� �ٽ� �ʱ�ȭ ���ش�.
						Bullet[i].Position.x = 118;
						Bullet[i].Position.y = rand() % 40;

						// ** ���� ���¸� Ȱ��ȭ ���·� ���� �Ѵ�.
						ShowBullet[i] = true;

						// ** �ð����� �� �ʱ�ȭ �Ѵ�.
						BulletDelay = GetTickCount64();

						// ** �Ѿ��� 1���� Ȱ��ȭ �� ���̱� ������
						// ** �ݺ����� ����������.
						break;
					}
				}
			}


			// ** Ȱ��ȭ ���� �Ѿ��� �׸���.
			for (int i = 0; i < 128; i++)
			{
				//if (ShowBullet[i] == true)
				// ** �Ѿ��� Ȱ��ȭ ���¶��...
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
	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;
}