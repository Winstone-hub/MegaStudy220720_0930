#pragma once
#include "Object.h"

class Alatreon : public Object
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void OnDestroy(Object* pObj)override;
public:
	Alatreon();
	virtual ~Alatreon();
};

