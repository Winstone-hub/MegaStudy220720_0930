#include "Bullet.h"

Bullet::Bullet()
{
	cout << "Bullet" << endl;
}

Bullet::Bullet(string name) : Object("Bullet", name)
{
}

Bullet::Bullet(string name, Vector2 position) : Object("Bullet", name, position)
{
}

Bullet::~Bullet()
{
}
