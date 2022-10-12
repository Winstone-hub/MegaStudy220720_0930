#pragma once
#include "Player.h"
#include "Enemy.h"

// ** 관리자 클래스로 사용하기 위함.
// ** 단 하나의 인스턴스만 만들고싶을때 사용한다.
class Object;
class SingletonManager
{
private:
	static SingletonManager* Instance;
public:
	static SingletonManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SingletonManager;
		return Instance;
	}
public:
	Object* CreatePlayer() { return new Player; }
	Object* CreateEnemy() { return new Enemy; }

private:
	SingletonManager() { }
};

SingletonManager* SingletonManager::Instance = nullptr;