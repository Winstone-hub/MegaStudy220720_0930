#include <iostream>
#include <Windows.h>
#include <map>
#include <vector>
#include <list>

using namespace std;



class Object
{
public:
	int Kor;
	int Eng;
	int Math;

	float Mean;
};

map<int, list<Object*> > Objects;


Object* CreateObject(int, int, int);
void AddObject(Object*, int);


// *************************************************
//   map
// *************************************************

int main(void)
{
	//***********************************************************
	// map<int, list<Object> >
	// map<string, vector<Object> >
	// 
	// vectorName.puah_back( pObj );
	// mapName["Key"] = vectorName;
	// 
	//***********************************************************


	for (int i = 0; i < 5; ++i)
	{
		// ** 난수 값 초기화.
		srand((unsigned int)GetTickCount64());

		// ** 오브젝트를 생성
		Object* pObj = CreateObject(
			rand() % 71 + 30,
			rand() % 71 + 30,
			rand() % 71 + 30);

		// ** 입력받을 값.
		int value = 0;

		// ** 입력
		cout << "입력 : "; cin >> value;

		// ** 오브젝트 추가.
		AddObject(pObj, value);
	}
	
	//***********************************************************
	// 출력
	//***********************************************************







	//***********************************************************
	// list< map<int,string> > 
	//***********************************************************


	return 0;
}



Object* CreateObject(int _kor, int _eng, int _math)
{
	Object* pObj = new Object;

	pObj->Kor = _kor;
	pObj->Eng = _eng;
	pObj->Math = _math;

	pObj->Mean = float((_kor + _eng + _math) / 3);

	return pObj;
}


void AddObject(Object* _pObj, int _value)
{
	// ** 입력된 값을 탐색.
	map<int, list<Object*>>::iterator iter = Objects.find(_value);

	// ** 데이터가 없다면...
	if (iter == Objects.end())
	{
		// ** 리스트를 새롭게 생성하고
		list<Object*> temp;

		// ** 생성된 리스트에 오브젝트를 추가.
		temp.push_back(_pObj);

		// ** 오브젝트가 추가된 리스트를 map 에 넣는다.
		Objects.insert(make_pair(_value, temp));
	}
	else // ** 찾는 데이터가 있다면...
		// ** 그곳에 오브젝트를 추가한다.
		iter->second.push_back(_pObj);
}












