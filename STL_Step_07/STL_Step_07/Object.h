#pragma once
#include "Headers.h"

class Object
{
protected:
	INFO Info;
	string key;
	int count;
public:
	string GetKey() { return key; }
	void SetKey(string key) { key = key; }

public:
	virtual Object* Initialize()PURE;
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void OnDestroy(Object* pObj)PURE;
	virtual Object* Clone()PURE;
public:
	Object();
	Object(INFO _Info) : Info(_Info) {};
	virtual ~Object();
};

