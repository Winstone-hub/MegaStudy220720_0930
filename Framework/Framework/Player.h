#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Player();
	virtual ~Player();
};

