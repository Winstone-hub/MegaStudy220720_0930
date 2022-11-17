#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : dwKey(0)
{

}

InputManager::~InputManager()
{

}


void InputManager::InputKey()
{
	dwKey = 0;

	if (GetAsyncKeyState(VK_UP))
		dwKey |= KEYID_UP;

	if (GetAsyncKeyState(VK_DOWN))
		dwKey |= KEYID_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		dwKey |= KEYID_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		dwKey |= KEYID_RIGHT;

	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEYID_SPACE;

	// ** enter
	if (GetAsyncKeyState(VK_RETURN))
		dwKey |= KEYID_ENTER;

	// ** esc
	if (GetAsyncKeyState(VK_ESCAPE))
		dwKey |= KEYID_ESC;

	// ** ctrl
	if (GetAsyncKeyState(VK_CONTROL))
		dwKey |= KEYID_CTRL;

	// ** alt
	if (GetAsyncKeyState(VK_MENU)) 
		dwKey |= KEYID_ALT;
}



