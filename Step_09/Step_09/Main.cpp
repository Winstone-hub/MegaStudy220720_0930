#include <iostream>

using namespace std;



class Object
{
private:
	string Name;

public:
	string GetName() { return Name; }
	void SetName(string _Name) { Name = _Name; }
	/*
	void SetName(string Name)
	{
		this->Name = Name;
	}
	*/
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




int main(void)
{
	{
		Object* O1 = new Object();
		O1->SetName("홍길동");

		Singleton::GetInstance()->SetObject(O1);
	}
	
	string str = Singleton::GetInstance()->GetObject()->GetName();
	cout << str << endl;

	return 0;
}