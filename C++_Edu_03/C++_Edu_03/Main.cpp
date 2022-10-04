#include <iostream>

using namespace std;



class Object
{
public:
	int Number;
	Object() : Number(0) { }

	Object(int _number) : Number(_number)
	{

	}
};

int main(void)
{
	// ** [C 스타일]
	//Object* Obj = (Object*)malloc(sizeof(Object));
	//Object* Obj = (Object*)malloc(sizeof(Object) * count);
	
	/*
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << Obj[i][j].Number << endl;
		}
	}
	*/

	//free(Obj)




	// ** [C++ 스타일]
	//Object* Obj = new Object[sizeof(Object) * count];
	//Object* Obj = new Object;
	

	// ** 포인터 1차원 배열
	Object* Obj = new Object[sizeof(Object) * 5];
	

	// ** 포인터 2차원 배열 (다차원 배열)
	//Object (Obj)[5][10];


	/*
	for (Object* o = (*Obj); o != nullptr; o++)
	{

	}
	*/


	/*
	for (auto o = Obj ; o != nullptr ; o++)
	{

	}
	*/


	/*
	for (Object* o : Obj)
		cout << o->Number << endl;
	*/


	//delete Obj;
	delete[] Obj;






	// ** 포인터의 개념
	/*
	int Number = 10;
	void* value = &Number;

	cout << value << endl;

	int* num = (int*)value;
	cout << *num << endl;
	*/


	return 0;
}