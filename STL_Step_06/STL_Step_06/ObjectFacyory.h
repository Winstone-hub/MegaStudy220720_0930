#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


class ObjectFacyory
{
public:
	template <typename T>
	static Object* CreateObject()
	{
		return new T();
	}

	template <typename T>
	static Object* CreateObject(string name)
	{
		return new T(name);
	}

	template <typename T>
	static Object* CreateObject(string name, Vector2 position)
	{
		return new T(name, position);
	}

	/*
	static Object* CreateObject(float _x, float _y)
	{
		return new T();
	}

	static Object* CreateObject(Vector3 Position)
	{
		return new T();
	}

	static Object* CreateObject(float x, float y, string name)
	{
		Object* pObj = new T();

		return pObj->SetName(name)->SetX(x)->SetY(y);
	}

	static Object* CreateObject(Vector3 Position, string name)
	{
		return new T();
	}
	*/

private:
	ObjectFacyory() {};
	~ObjectFacyory() {};
};