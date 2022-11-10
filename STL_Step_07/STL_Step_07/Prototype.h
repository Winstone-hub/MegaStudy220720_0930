#pragma once
#include "Headers.h"


class Object;
class Prototype
{
private:
	static Prototype* Instance;

public:
	static Prototype* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Prototype();
		return Instance;
	}
private:
	map<string, Object*> ProtoTypeObject;

public:
	void Initialize();
	bool AddProtoTypeObject(Object* object);
	Object* findObject(string key);

private:
	Prototype();
public:
	~Prototype();
};

