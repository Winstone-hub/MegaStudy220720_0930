#include "Logo.h"
#include "ScaneManager.h"
#include "Child.h"
#include "CursorManager.h"


Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start(void)
{
	Info.Position = Vector3(18.0f, 27.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	Color = 0;
	Switching = 0;
	Time = GetTickCount64();
	DelayTime = 100;
	Switching = 0;


	//=======================================
	// Logo Slider
	//=======================================
	Sliders[0].Texture = "忙";
	Sliders[1].Texture = "′";
	Sliders[2].Texture = "′";
	Sliders[3].Texture = "′";
	Sliders[4].Texture = "′";
	Sliders[5].Texture = "′";
	Sliders[6].Texture = "′";
	Sliders[7].Texture = "戌";

	for (int i = 0; i < 8; ++i)
	{
		Sliders[i].Info.Position = Vector3(118.0f + (i * 2), 3.0f + i, 0.0f);
		Sliders[i].Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
		Sliders[i].Info.Scale = Vector3(
			(float)Sliders[i].Texture.size(), 1.0f, 0.0f);
	}
}


void Logo::Update(void)
{
#ifdef DEBUG
	if (GetAsyncKeyState(VK_UP))
		Info.Position.y -= 1;

	if (GetAsyncKeyState(VK_DOWN))
		Info.Position.y += 1;

	if (GetAsyncKeyState(VK_RIGHT))
		Info.Position.x += 1;

	if (GetAsyncKeyState(VK_LEFT))
		Info.Position.x -= 1;
#endif
	if(GetAsyncKeyState(VK_RETURN))
		ScaneManager::GetInstance()->SetScene(MENUID);


	//=======================================
	// Logo Slider
	//=======================================

	for (int i = 0; i < 8; ++i)
	{
		if (Sliders[7].Info.Position.x > 65.0f)
		{
			Sliders[i].Info.Position.x -= 5.0f;

			if (116.0f > (Sliders[0].Info.Position.x + Sliders[0].Info.Scale.x))
			{
				Sliders[0].Texture += "式";
				Sliders[0].Info.Scale.x += 2;
			}
			if (116.0f > (Sliders[7].Info.Position.x + Sliders[7].Info.Scale.x))
			{
				Sliders[7].Texture += "式";
				Sliders[7].Info.Scale.x += 2;

				if (i == 7)
				{
					Sliders[7].Texture += "式";
					Sliders[7].Info.Scale.x += 2;
					Sliders[7].Texture += "式";
					Sliders[7].Info.Scale.x += 2;
				}
			}
		}
	}


	if (Time + DelayTime < GetTickCount64())
	{
		Time = GetTickCount64();
		//=======================================
		// Insert coin 梭緇歜.
		//=======================================
		++Switching;
		switch (Switching)
		{
		case 0:
			Color = BlackColors[0];
			break;
		case 1:
			Color = BlackColors[1];
			break;
		case 2:
			Color = BlackColors[2];
			break;
		case 3:
			Color = BlackColors[3];
			break;
		case 4:
			Color = BlackColors[4];
			DelayTime = 1000;
			break;
		case 5:
			Color = BlackColors[4];
			DelayTime = 100;
			break;
		case 6:
			Color = BlackColors[3];
			break;
		case 7:
			Color = BlackColors[2];
			break;
		case 8:
			Color = BlackColors[1];
			break;
		case 9:
			Color = BlackColors[0];
			break;
		default:
			Switching = -1;
		}
	}
}

void Logo::Render(void)
{
#ifdef DEBUG
	CursorManager::Renderer(0, 0, "X : ");
	CursorManager::Renderer(4, 0, Info.Position.x);
	CursorManager::Renderer(0, 1, "Y : ");
	CursorManager::Renderer(4, 1, Info.Position.y);
#endif // DEBUG


	for (int i = 0; i < 8; ++i)
	{
		if (Sliders[i].Info.Position.x < 118.0f)
			CursorManager::Renderer(
				Sliders[i].Info.Position.x, 
				Sliders[i].Info.Position.y + i,
				Sliders[i].Texture, 15);
	}

	CursorManager::Renderer(Info.Position.x, Info.Position.y + 0, " ___   __    _  _______  _______  ______    _______    _______  _______  ___   __    _", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 1, "|   | |  |  | ||       ||       ||    _ |  |       |  |       ||       ||   | |  |  | |", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 2, "|   | |   |_| ||  _____||    ___||   | ||  |_     _|  |       ||   _   ||   | |   |_| |", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 3, "|   | |       || |_____ |   |___ |   |_||_   |   |    |       ||  | |  ||   | |       |", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 4, "|   | |  _    ||_____  ||    ___||    __  |  |   |    |      _||  |_|  ||   | |  _    |", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 5, "|   | | | |   | _____| ||   |___ |   |  | |  |   |    |     |_ |       ||   | | | |   |", Color);
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 6, "|___| |_|  |__||_______||_______||___|  |_|  |___|    |_______||_______||___| |_|  |__|", Color);
}

void Logo::Release(void)
{

}
