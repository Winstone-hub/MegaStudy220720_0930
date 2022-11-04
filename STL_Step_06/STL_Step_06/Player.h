#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player();
	Player(string name);
	Player(string name, Vector2 position);
	virtual ~Player();
};

