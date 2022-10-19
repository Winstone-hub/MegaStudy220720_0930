#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
private:
	Object* Testcase;
public:
	virtual void Start(void)override;
	virtual void Update(void)override;
	virtual void Render(void)override;
	virtual void Release(void)override;
public:
	Stage();
	virtual ~Stage();
};

