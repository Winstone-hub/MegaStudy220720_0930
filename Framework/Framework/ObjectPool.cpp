#include "ObjectPool.h"
#include "Prototype.h"
#include "Object.h"

ObjectPool* ObjectPool::Instance = nullptr;


ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{
	Release();
}


bool ObjectPool::CreateObject(string _key)
{
	// ** 복사 생성.
	Object* ProtoObject = Prototype::GetInstance()->FindObject("Player");

	if (ProtoObject != nullptr)
	{
		list<Object*> temp;
		for (int i = 0; i < 5; ++i)
		{
			Object* pObj = ProtoObject->Clone();
			pObj->SetSpace(&temp);
			temp.push_back(pObj);
			DisableList.insert(make_pair(_key, temp));
		}

		return true;
	}

	return false;
}

list<Object*>* ObjectPool::FindObjectList(string _key)
{
	auto iter = DisableList.find(_key);

	if (iter == DisableList.end())
		return nullptr;

	return &iter->second;
}

Object* ObjectPool::Insert(string _key)
{
START:
	auto iter = FindObjectList(_key);

	if (iter == nullptr)
	{
		if(CreateObject(_key))
			goto START;

		ErrorMessage(__LINE__);
		return nullptr;
	}
	else
	{
		Object* pObj = iter->back();
		iter->pop_back();
		return pObj;
	}
}

void ObjectPool::Erase(Object* _Obj)
{
	//auto iter = EnableList.find(_Obj->GetKey());

}

void ObjectPool::Release()
{
	for (auto iter = DisableList.begin(); iter != DisableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
	}
	DisableList.clear();


	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
	}
	EnableList.clear();
}