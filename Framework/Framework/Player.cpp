#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

Object* Player::Initialize(const string& _key)
{
	// ** 초기화.
	Key = _key;
	return this;
}

void Player::Start()
{
	// ** 초기화.
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
	cout << Key << ": " << Index << endl;
}

void Player::Release()
{

}
