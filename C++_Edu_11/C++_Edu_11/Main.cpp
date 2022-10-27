#include "Headers.h"
#include "Child.h"
#include "MainUpdate.h"


int main(void)
{
	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			system("cls");

			Time = GetTickCount64();

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}


