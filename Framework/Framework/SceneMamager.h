#pragma once
#include "Headers.h"

class Scene;
class SceneMamager
{
private:
	static SceneMamager* Instance;
public:
	static SceneMamager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneMamager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene(Scene_ID id);
	void Update();
	void Render();
	void Release();
private:
	SceneMamager();
public:
	~SceneMamager();
};

