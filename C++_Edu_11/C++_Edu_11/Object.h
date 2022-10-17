#pragma once
#include "Headers.h"

// ** 추상클래스
class Object
{
protected:
	Transform Info;

public:
	virtual void Start(void)PURE;
	virtual void Update(void)PURE;
	virtual void Render(void)PURE;
	virtual void Release(void)PURE;
public:
	Object();
	virtual ~Object();
};

