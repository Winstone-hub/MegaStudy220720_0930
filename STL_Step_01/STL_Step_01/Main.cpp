#include <iostream>
#include <vector>

using namespace std;


class Object
{
public:
	int Kor;
	int Eng;
	int Math;
};

int main(void)
{
	vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);
	numbers.push_back(50);


	cout << "[array]" << endl;
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers[i] << endl;

	cout << endl << "[at]" << endl;
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers.at(i) << endl;

	// ** 첫번째 원소를 가르킨다.
	cout << endl << numbers.front() << endl;

	// ** 마지막 원소를 가르킨다.
	cout << endl << numbers.back() << endl;

	// ** 컨테이너가 들고있는 원소의 개수
	cout << endl << "size : " << numbers.size() << endl;

	// ** 컨테이너가 수용할 수 있는 최대 공간.
	cout << endl << "capacity : " << numbers.capacity() << endl;


	// ** 컨테이너의 마지막 원소를 제거.
	numbers.pop_back();

	// ** 마지막 원소를 가르킨다.
	cout << endl << numbers.back() << endl;

	/*
	// ** 반복자 = iterator
	numbers.begin();
	numbers.end();

	numbers.insert();
	numbers.empty();

	numbers.clear();
	numbers.erase();
	*/

	//================================================
	// 실습예제
	//================================================

	vector<Object*> pObjects;


	return 0;
}