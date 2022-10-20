#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	Transform Info;
	int Color;
	ULONGLONG Time;
	ULONGLONG DelayTime;
	int Switching;
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Logo();
	virtual ~Logo();
};

