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
			Instance = new ObjectPool();
		return Instance;
	}

private:
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DesableList;

public:
	list<Object*>* GetDesableObjectList(string key);
	void AddObjectList(Object* pObj, ListType type = ListType::Enable);
	void CreateObjectList();
	void Update();
	void Render();
private:
	ObjectPool();
public:
	~ObjectPool();
};

