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
			Instance = new Prototype;
		return Instance;
	}
private:
	map<string, Object*> PrototypeObjects;
public:
	void Initialize();
	Object* FindObject(string _key);
private:
	Prototype();
public:
	~Prototype();
};