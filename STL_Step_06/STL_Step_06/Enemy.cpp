#include "Enemy.h"

Enemy::Enemy()
{
	cout << "Enemy" << endl;
}

Enemy::Enemy(string name) : Object("Enemy", name)
{
}

Enemy::Enemy(string name, Vector2 position) : Object("Enemy", name, position)
{
}

Enemy::~Enemy()
{
}
