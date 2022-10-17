#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Logo();
	virtual ~Logo();
};

