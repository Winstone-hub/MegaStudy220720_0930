#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	string Key;

	list<Object*>* Space;
public:
	virtual Object* Initialize(const string& _key)PURE;
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;
public:
	string GetKey() { return Key; }  
	void SetSpace(list<Object*>* _Space) { Space = _Space; }
public:
	Object();
	Object(const Transform &_Info) : Info(_Info), Space(nullptr) {}
	virtual ~Object();
};

