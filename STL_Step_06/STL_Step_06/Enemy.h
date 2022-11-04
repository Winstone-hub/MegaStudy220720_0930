#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	Enemy(string name);
	Enemy(string name, Vector2 position);
	virtual ~Enemy();
};

