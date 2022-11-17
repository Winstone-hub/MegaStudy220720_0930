#include "Headers.h"
#include "MainUpdate.h"
#include "DataManager.h"

int main(void)
{
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	// ** 경로 저장.
	/*
	DataManager::saveData("Images\\background.png");
	DataManager::saveData("Images\\logo.png");
	DataManager::saveData("Images\\menu.png");
	DataManager::saveData("Images\\stage.png");
	DataManager::saveData("Images\\player.png");
	DataManager::saveData("Images\\enemy.png");
	DataManager::saveData("Images\\bullet.png");
	*/
	
	while (true)
	{
		if (Time < GetTickCount64())
		{
			system("cls");

			//DataManager::loadData();
			
			Main.Update();
			Main.Render();
		}
	}

	return 0;
}