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
		// ** ����Ʈ �߰�
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

		// ** ��ư �Է��� �޾Ƽ�
		if (GetAsyncKeyState(VK_RETURN))
		{
			// ** ���� ������� Ű�� �ӽ÷� ����. 
			string key = "Alatreon";

			// ** ���� ���� DesableList�� �����Ͱ� �ִ��� ������ Ȯ��.
			if (!DesableList.empty())
			{
				// ** �����Ͱ� �ִٸ� Ű�� Ȯ��.
				auto iter = DesableList.find(key);

				// ** DesableList �� ã�� ���� �ִ��� Ȯ��.
				if (iter == DesableList.end())
				{
					// ** ã�°��� ���ٸ� ���Ӱ� �������ش�.
					Object* pObj = new Alatreon;

					// ** �ʱ�ȭ.
					pObj->Start();

					// ** ���� �� �ʱ�ȭ�� ��ü�� List�� �����Ͽ� �߰��Ѵ�.
					list<Object*> temp;
					temp.push_back(pObj);

					// ** ��� �۾��� �Ϸ� �Ǿ��ٸ� �ʿ� �߰��Ѵ�.
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