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
			if (!DesableList.empty())
			{
				Object* pObj = DesableList.front();
				pObj->Start();
				EnableList.push_back(pObj);
				DesableList.pop_front();
			}
			else
			{
				Object* pObj = new Alatreon;
				pObj->Start();
				EnableList.push_back(pObj);
			}
		}

		//for(auto object : EnableList)
		for (auto iter = EnableList.begin(); iter != EnableList.end(); )
		{
			int result = (*iter)->Update();
			(*iter)->Render();

			if (result == 1)
			{
				DesableList.push_back((*iter));
				iter = EnableList.erase(iter);
			}
			else
				++iter;
		}

		cout << "[DesableList]" << endl;
		for (auto object : DesableList)
			cout << object->GetKey() << endl;
	}

	return 0;
}
