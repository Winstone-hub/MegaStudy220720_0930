#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	map<string, list<Object*>>* EnableList;
	map<string, list<Object*>>* DisableList;
public:
	void Initialize();
	void DisableFormEnable();
	void EnableFormDisable();
	void Render();
private:
	ObjectManager();
public:
	~ObjectManager();
};

