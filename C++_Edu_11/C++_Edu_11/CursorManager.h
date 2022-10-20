#pragma once
#include "Headers.h"

class CursorManager
{
public:
	static void Renderer(float _x, float _y, string _str, int _Color = 15)
	{
		COORD pos = { (SHORT)_x, (SHORT)_y };

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), pos);

		SetColor(_Color);
		cout << _str;
	}

private:
	static void SetColor(int _Color)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE), _Color);
	}
private:
	CursorManager() {};
public:
	~CursorManager() {};
};