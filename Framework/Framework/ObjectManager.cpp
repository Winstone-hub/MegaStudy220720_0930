#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}


void ObjectManager::Initialize()
{
	EnableList = ObjectPool::GetInstance()->GetEnableList();
	DisableList = ObjectPool::GetInstance()->GetDisableList();
}

void ObjectManager::DisableFormEnable()
{
	auto iter = EnableList->find("Player");

	//생성.
	Object* pObj = ObjectPool::GetInstance()->Insert("Player");

	if (pObj == nullptr)
	{
		// ** Error Message
		//ErrorMessage(__LINE__);
		return;
	}

	if (iter == EnableList->end())
	{
		list<Object*> temp;
		temp.push_back(pObj->Clone());
		EnableList->insert(make_pair(pObj->GetKey(), temp));
	}
	else
		iter->second.push_back(pObj);
}

void ObjectManager::EnableFormDisable()
{
	// ** 테스트 코드 =======================================
	auto pObj = EnableList->find("Player")->second.front();
	// ** ===================================================

	if (pObj == nullptr)
		ErrorMessage(__LINE__);

	ObjectPool::GetInstance()->Erase(pObj);
}

void ObjectManager::Render()
{
	for (auto iter = EnableList->begin(); iter != EnableList->end(); ++iter)
	{
		cout << " [ EnableList : " << iter->first << "] " << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}

	for (auto iter = DisableList->begin(); iter != DisableList->end(); ++iter)
	{
		cout << " [ DisableList : " << iter->first << "] " << endl;
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
