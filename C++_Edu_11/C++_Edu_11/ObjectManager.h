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
	Object* Player;
	Object* Objects[EndID][MaxID];

public:
	void SetPlayer(Object* _Player) { Player = _Player; }
	Object* GetPlayer() { return Player; }

	void SetObjects(Object* _Objects) { *(*Objects) = _Objects; }
private:
	ObjectManager();
public:
	~ObjectManager();
};

