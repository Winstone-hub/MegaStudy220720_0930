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

	//

	if (ProtoObject != nullptr)
	{
		auto iter = DisableList.find(_key);

		if (iter == DisableList.end())
		{
			Counts.insert(make_pair(_key, 0));

			list<Object*> temp;
			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = ProtoObject->Clone();
				pObj->SetSpace(&temp);
				pObj->SetIndex(Counts.find(_key)->second++);
				temp.push_back(pObj);
			}
			DisableList.insert(make_pair(_key, temp));
		}
		else
		{
			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = ProtoObject->Clone();
				pObj->SetIndex(Counts.find(_key)->second++);
				pObj->SetSpace(&iter->second);
				iter->second.push_back(pObj);
			}
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
		CREATE:
		if(CreateObject(_key))
			goto START;

		ErrorMessage(__LINE__);
		return nullptr;
	}
	else
	{
		if (!iter->empty())
		{
			Object* pObj = iter->back();
			iter->pop_back();
			return pObj;
		}
		else
			goto CREATE;
	}
}

void ObjectPool::Erase(Object* _Obj)
{
	auto iter = EnableList.find(_Obj->GetKey());

	if (iter == EnableList.end())
	{
		ErrorMessage(__LINE__);
		return;
	}

	if (iter->second.empty())
	{
		ErrorMessage(__LINE__);
		return;
	}


	for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); )
	{
		if (_Obj->GetIndex() == (*iter2)->GetIndex())
		{
			// ** 테스트코드==============================================
			DisableList.find(_Obj->GetKey())->second.push_back((*iter2));
			// ** ========================================================

			iter2 = iter->second.erase(iter2);
		}
		else
			++iter2;
	}
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