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
	map<string, list<Object*>*> EnableList;
	map<string, list<Object*>*> DesableList;

public:
	list<Object*>* findMapList(string key, map<string, list<Object*>*>* mapList);
	void addMapObject(Object* pObj, map<string, list<Object*>*>* mapList);
	void Update();
	void Render();
private:
	ObjectPool();
public:
	~ObjectPool();
};

