#pragma once
#include "Headers.h"

class Object
{
protected:
	string key;
	int count;
public:
	string GetKey() { return key; }

public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void OnDestroy(Object* pObj)PURE;

public:
	Object();
	virtual ~Object();
};

