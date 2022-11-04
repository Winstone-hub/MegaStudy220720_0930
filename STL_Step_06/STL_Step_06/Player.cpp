#include "Player.h"

Player::Player()
{
	cout << "Player" << endl;
}

Player::Player(string name) : Object("Player", name)
{

}

Player::Player(string name, Vector2 position) : Object("Player", name, position)
{

}

Player::~Player()
{
}
