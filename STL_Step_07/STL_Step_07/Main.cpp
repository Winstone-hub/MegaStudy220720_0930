#include "Headers.h"
#include "ObjectPool.h"
#include "Alatreon.h"

// ** DesignPattern
// ** ObjectPool Pattern


int main(void)
{
	list<Object*>* objectList = ObjectPool::GetInstance()->GetDesableObjectList("Alatreon");

	if (objectList == nullptr)
	{
		// ** 리스트 추가
		cout << "objectList == nullptr" << endl;

		Object* pObj = new Alatreon();
		pObj->Start();

		ObjectPool::GetInstance()->AddObjectList(pObj);
	}
	else
	{
		// ** switch from desable list to enable list
		if (!objectList->empty())
		{
			// ** desable list -> enable list

		}
		else
		{
			// ** create
			ObjectPool::GetInstance()->CreateObjectList();
		}
	}


	/*
	while (true)
	{
		system("cls");

		// ** 버튼 입력을 받아서
		if (GetAsyncKeyState(VK_RETURN))
		{
			// ** 현재 사용중인 키를 임시로 지정. 
			string key = "Alatreon";

			// ** 제일 먼저 DesableList에 데이터가 있는지 없는지 확인.
			if (!DesableList.empty())
			{
				// ** 데이터가 있다면 키를 확인.
				auto iter = DesableList.find(key);

				// ** DesableList 에 찾는 값이 있는지 확인.
				if (iter == DesableList.end())
				{
					// ** 찾는값이 없다면 새롭게 생성해준다.
					Object* pObj = new Alatreon;

					// ** 초기화.
					pObj->Start();

					// ** 생성 및 초기화된 객체를 List를 생성하여 추가한다.
					list<Object*> temp;
					temp.push_back(pObj);

					// ** 모든 작업이 완료 되었다면 맵에 추가한다.
					EnableList->insert(make_pair(pObj->GetKey(), temp));
				}


				Object* pObj = iter->second.front();
				pObj->Start();

				if (DesableList.find(pObj->GetKey())->second.empty())
				{
					auto iter2 = EnableList.find(pObj->GetKey());

					if (iter2 == EnableList.end())
					{
						list<Object*> temp;
						temp.push_back(pObj);
						EnableList.insert(make_pair(pObj->GetKey(), temp));
					}
					else
						iter2->second.push_back(pObj);
					
					DesableList.find(pObj->GetKey())->second.pop_front();
				}
			}
			else
			{
				Object* pObj = new Alatreon;
				pObj->Start();
				
				auto iter = EnableList.find(pObj->GetKey());

				if (iter == EnableList.end())
				{
					list<Object*> temp;
					temp.push_back(pObj);
					EnableList.insert(make_pair(pObj->GetKey(), temp));
				}
				else
					iter->second.push_back(pObj);
			}
		}

		//for(auto object : EnableList)
		for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
		{
			for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); )
			{
				int result = (*iter2)->Update();
				(*iter2)->Render();

				if (result == 1)
				{
					auto iterList = DesableList.find((*iter2)->GetKey());
					
					if (iterList == DesableList.end())
					{
						list<Object*> temp;
						temp.push_back((*iter2));
						DesableList.insert(make_pair((*iter2)->GetKey(), temp));
					}
					else
						iterList->second.push_back((*iter2));

					auto iter2List = EnableList.find((*iter2)->GetKey());

					if (iter2List != EnableList.end())
						iter2 = iter2List->second.erase(iter2);
				}
				else
					++iter2;
			}
		}
	}
	*/

	return 0;
}