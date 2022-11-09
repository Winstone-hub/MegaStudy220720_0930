#include "ObjectPool.h"
#include "Alatreon.h"

ObjectPool* ObjectPool::Instance = nullptr;


ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

list<Object*>* ObjectPool::GetDesableObjectList(string key)
{
	// ** 오브젝트가 담겨있는 리스트가 존재하는지 탐색
	auto iter = DesableList.find(key);

	// ** 존재 한다면 리스트를 반환하고
	if (iter != DesableList.end())
		return iter->second;

	// ** 그렇지 않다면 nullptr을 반환한다.
	return nullptr;
}

void ObjectPool::AddObjectList(Object* pObj, ListType type)
{
	map<string, list<Object*>*>* mapList = nullptr;

	if (type == ListType::Enable)
		mapList = &EnableList;
	else
		mapList = &DesableList;

	// ** 오브젝트가 담겨야 할 공간이 이미 존재하는지 탐색
	auto iter = mapList->find(pObj->GetKey());

	// ** 존재하지 않는다면 새로운 공간을 확보하고 추가한다.
	if (iter == mapList->end())
	{
		list<Object*>* temp = new list<Object*>();
		temp->push_back(pObj);
		mapList->insert(make_pair(pObj->GetKey(), temp));
	}
	else // ** 존재 한다면 그 해당 위치에 객체를 넣는다.
		iter->second->push_back(pObj);
}

void ObjectPool::CreateObjectList()
{
	/*
	list<Object*>* plist = GetDesableObjectList("Alatreon");

	if (plist == nullptr)
	{

	}
	else
	{

	}
	*/

	for (int i = 0; i < 4; ++i)
	{
		Object* pObj = new Alatreon();
		pObj->Start();

		AddObjectList(pObj, ListType::Desable);
	}

	Object* pObj = new Alatreon();
	pObj->Start();

	AddObjectList(pObj);
}

void ObjectPool::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second->begin(); iter2 != iter->second->end();)
		{
			int result = (*iter2)->Update();

			if (result == 1)
			{
				AddObjectList((*iter2), ListType::Desable);
				iter2 = iter->second->erase(iter2);
			}
			else
				++iter2;
		}
	}

}

void ObjectPool::Render()
{
	// ** Enable
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		cout << "[Enable]" << endl;
		cout << " [" << iter->first << "] " << endl;

		for (auto iter2 = iter->second->begin(); iter2 != iter->second->end(); ++iter2)
			cout << (*iter2)->GetKey() << endl;
	}

	// ** Desable
	for (auto iter = DesableList.begin(); iter != DesableList.end(); ++iter)
	{
		cout << "[Desable]" << endl;
		cout << " [" << iter->first << "] " << endl;

		for (auto iter2 = iter->second->begin(); iter2 != iter->second->end(); ++iter2)
			cout << (*iter2)->GetKey() << endl;
	}
}
