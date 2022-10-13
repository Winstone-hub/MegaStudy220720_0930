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


// ** �ν��Ͻ�
class Singleton
{
// ** static : ��𼭳� ���� ������ �����Ҽ� �־�� �Ѵ�.
// ** Singleton* Instance; : ��ü�� �ϳ��� ���� �ؾ� �Ѵ�.
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

// ** private: ��ü�� ��𼭵� ������ �� ���ƾ� �Ѵ�.
private:
	Singleton() : pObj(nullptr) { }
};

Singleton* Singleton::Instance = nullptr;




// ** ������ �����ε�
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
	*  [��ȯ��] =  �ǿ����� ������ �ǿ�����
	*                 ��      ��     ��
	[��ȯ���� ����] [�ڱ��ڽ�]+ ([������ �׸�])
	{
		return [��ȯ��]
	}
	*/


public:
	Operator() : Number(0) { } 
	Operator(int _Number) : Number(_Number) { }
};

int main(void)
{
	// ** ������ �ε� �Ҽ��� : IEEE 754
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
		O1->SetName("ȫ�浿");

		Singleton::GetInstance()->SetObject(O1);
	}
	
	string str = Singleton::GetInstance()->GetObject()->GetName();
	cout << str << endl;
	*/

	return 0;
}