#pragma once
#include "Headers.h"

class Object;
class ObjectPool
{
private:
	static ObjectPool* Instance;
public:
	static ObjectPool* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPool;
		return Instance;
	}
private:
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	map<string, list<Object*>>* GetEnableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisableList() { return &DisableList; } 
public:
	void CreateObject(string key);

	void FindObject();
	void Update();

	Object* Pop(string _key);
	void Erase();

	void Release();
private:
	ObjectPool();
public:
	~ObjectPool();
};

