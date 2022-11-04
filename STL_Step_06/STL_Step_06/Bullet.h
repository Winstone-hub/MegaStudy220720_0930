#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(string name);
	Bullet(string name, Vector2 position);
	virtual ~Bullet();
};

