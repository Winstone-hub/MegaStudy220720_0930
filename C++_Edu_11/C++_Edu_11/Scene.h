#pragma once
#include "Headers.h"

class Object;
class Scene
{
protected:
	static Object* Objects[EndID][MaxID];
public:
	virtual void Start(void)PURE;
	virtual void Update(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
public:
	Scene();
	virtual ~Scene();
};

