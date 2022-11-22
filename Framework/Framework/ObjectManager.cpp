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
	//ErrorMessage(__LINE__);

	//»ı¼º.
	Object* pObj = ObjectPool::GetInstance()->Insert("Player");

	if (pObj == nullptr)
	{
		// ** Error Message
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

void ObjectManager::Render()
{
	for (auto iter = EnableList->begin(); iter != EnableList->end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
