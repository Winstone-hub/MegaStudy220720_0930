#include <iostream>
#include <string>

using namespace std;


// ** namespace

// ** ���
// ** �߻�
// ** ������

// ** �����Լ� & ���������Լ�
// ** �����ε� & �������̵�
// ** ������ �����ε�


class Parent
{


};

class Child
{

};



class A
{
	// ** ������ ���� ���� ����
private:



	// ** ��Ӱ��迡���� ���� ���� ����, ����� �ƴ� ��쿡�� �����.
	// ** ��� : public
	// ** �� ��� : private
protected:
	string Name;
	int Age;


	// ** ������ ���� ���� ����
public:
	void Initialize()
	{
		Name = "";
		Age = 0;
	}
	void Render()
	{
		cout << Name << endl;
		cout << Age << endl;
	}
};

class B : public A
{
public:
	void Initialize()
	{
		Name = "ȫ�浿";
		Age = 32;
	}
	
};

class C : public A
{
public:
	void Initialize()
	{
		Name = "�Ӳ���";
		Age = 38;
	}
};



int main(void)
{
	B b;
	b.Initialize();
	b.Render();

	return 0;
}