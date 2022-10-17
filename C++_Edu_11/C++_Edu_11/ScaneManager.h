#pragma once
#include "Headers.h"

class Scene;
class ScaneManager
{
private:
	static ScaneManager* Instance;
public:
	static ScaneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ScaneManager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene();
	void Update();
	void Render();
	void Release();
private:
	ScaneManager();
public:
	~ScaneManager();
};

