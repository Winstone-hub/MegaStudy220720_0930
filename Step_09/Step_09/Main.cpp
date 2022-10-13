#include <iostream>

using namespace std;



class Object
{
private:
	string Name;

public:
	string GetName() { return Name; }
	void SetName(string _Name) { Name = _Name; }

	//void SetName(string Name) { this->Name = Name; }
};


// ** 인스턴스
class Singleton
{
// ** static : 어디서나 쉽고 빠르게 접근할수 있어야 한다.
// ** Singleton* Instance; : 객체는 하나만 존재 해야 한다.
private:
	static Singleton* Instance;

public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton();
		return Instance;
	}
private:
	Object* pObj;
public:
	Object* GetObject() { return pObj; }
	void SetObject(Object* _pObj) { pObj = _pObj; }

// ** private: 객체는 어디서도 생성할 수 없아야 한다.
private:
	Singleton() : pObj(nullptr) { }
};

Singleton* Singleton::Instance = nullptr;




// ** 연산자 오버로딩
class Operator
{
public:
	int Number;

public:
	Operator operator+(Operator& _ref)
	{
		return Operator(Number + _ref.Number);
	}

	Operator operator-(Operator& _ref)
	{
		return Operator(Number - _ref.Number);
	}

	void operator+=(Operator& _ref)
	{
		Number += _ref.Number;
	}

	/*
	*  [반환값] =  피연산자 연산자 피연산자
	*                 ↓      ↓     ↓
	[반환값의 형태] [자기자신]+ ([연산할 항목])
	{
		return [반환값]
	}
	*/


public:
	Operator() : Number(0) { } 
	Operator(int _Number) : Number(_Number) { }
};

int main(void)
{
	// ** 단정도 부동 소수점 : IEEE 754
	//https://www.h-schmidt.net/


	/*
	Operator oper1, oper2;
	oper1.Number = 10;
	oper2.Number = 20;

	Operator oper3 = oper1 + oper2;
	cout << oper3.Number << endl;

	oper1 += oper2;
	cout << oper1.Number << endl;
	*/


	/*
	{
		Object* O1 = new Object();
		O1->SetName("홍길동");

		Singleton::GetInstance()->SetObject(O1);
	}
	
	string str = Singleton::GetInstance()->GetObject()->GetName();
	cout << str << endl;
	*/

	return 0;
}