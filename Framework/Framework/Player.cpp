#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{

}

void Player::Update()
{
	DWORD key = InputManager::GetInstance()->GetKey();

	if (key & KEYID_UP)
		cout << "KEYID_UP" << endl;

	if (key & KEYID_DOWN)
		cout << "KEYID_DOWN" << endl;
}

void Player::Render()
{

}

void Player::Release()
{

}
