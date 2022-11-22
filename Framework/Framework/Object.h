#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	string Key;

	list<Object*>* Space;
	int Index;
public:
	virtual Object* Initialize(const string& _key)PURE;
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;
public:
	int GetIndex() { return Index; }
	void SetIndex(int _Index) { Index = _Index; }

	string GetKey() { return Key; }  
	list<Object*>* GetSpace() { return Space; }
	void SetSpace(list<Object*>* _Space) { Space = _Space; }
public:
	Object();
	Object(const Transform& _Info) : Info(_Info), Space(nullptr), Index(0) {}
	virtual ~Object();
};

