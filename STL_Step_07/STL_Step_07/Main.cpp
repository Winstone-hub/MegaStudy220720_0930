#include "Headers.h"
#include "Alatreon.h"

// ** DesignPattern
// ** ObjectPool Pattern


int main(void)
{
	//list<Object*> EnableList;
	//list<Object*> DesableList;
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DesableList;

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_RETURN))
		{
			string key = "Alatreon";


			if (!DesableList.empty())
			{
				auto iter = DesableList.find(key);

				Object* pObj = iter->second.front();
				pObj->Start();


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
			else
			{
				Object* pObj = new Alatreon;
				pObj->Start();
				
				auto iter = EnableList.find(pObj->GetKey());

				if (iter == EnableList.end())
				{
					//->second.push_back(pObj);
				}
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
					DesableList.find((*iter2)->GetKey())->second.push_back((*iter2));
					iter2 = EnableList.find((*iter2)->GetKey())->second.erase(iter2);
				}
				else
					++iter2;
			}
		}

		
		for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
		{
			cout << "[DesableList]" << endl;
			cout << " [" << iter->first << "] " << endl;
			
			for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); )
			{
				cout << (*iter2)->GetKey() << endl;
			}
		}
	}

	return 0;
}
