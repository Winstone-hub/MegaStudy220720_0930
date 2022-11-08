#include "ObjectPool.h"
#include "Alatreon.h"

ObjectPool* ObjectPool::Instance = nullptr;


ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

list<Object*>* ObjectPool::findMapList(string key, map<string, list<Object*>*>* mapList)
{
	// ** 오브젝트가 담겨있는 리스트가 존재하는지 탐색
	auto iter = mapList->find(key);

	// ** 존재 한다면 리스트를 반환하고
	if (iter != mapList->end())
		return iter->second;

	// ** 그렇지 않다면 nullptr을 반환한다.
	return nullptr;
}

void ObjectPool::addMapObject(Object* pObj, map<string, list<Object*>*>* mapList)
{
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

void ObjectPool::Update()
{
	
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
